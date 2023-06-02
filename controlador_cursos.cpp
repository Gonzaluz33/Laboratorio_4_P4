#include "controlador_cursos.hpp"
#include "controlador_usuarios.hpp"

ControladorCursos::ControladorCursos() {

}

ControladorCursos::~ControladorCursos() {

}

vector<string> ControladorCursos::listarProfesores() {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    return cu->listarProfesores();
}

void ControladorCursos::iniciarAltaCurso(string nickname, string nombreCurso,
                                         string descripcion, Dificultad dificultad) {
    nickname_recordado = nickname;
    nombreCurso_recordado = nombreCurso;
    descripcion_recordado = descripcion;
    dificultad_recordado = dificultad;
}

vector<DTIdioma> ControladorCursos::listaIdiomasProfesor(string nickname) {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    return cu->listaIdiomasProfesor(nickname);
}

void ControladorCursos::seleccionarIdiomaCurso(DTIdioma idioma) {
    idioma_recordado = idioma;
}

vector<DTCurso> ControladorCursos::listarCursosHabilitados() {
    vector<DTCurso> salida;
    for(int i = 0; i < cursosHabilitados.size(); i++) {
        salida.push_back(cursosHabilitados[i]->getDTCurso());
    }
}

void ControladorCursos::seleccionarCursosPrevios(string nombre) {
    cursosPrevios.push_back(nombre);
}

void ControladorCursos::crearCurso() {
    curso_recordado = new Curso(nickname_recordado, nombreCurso_recordado,
                                descripcion_recordado, dificultad_recordado,
                                idioma_recordado, cursosPrevios);

    /* Libero memoria */
    cursosPrevios.clear();
    nickname_recordado.clear();
    nombreCurso_recordado.clear();
    descripcion_recordado.clear();

    cursos.push_back(curso_recordado); // parece que el set de cursos no se usa, *si eliminamos
                                       // cursos eliminar esta linea.*
}

void ControladorCursos::darAltaCurso() {
    Idioma *idioma_notificacion;
    
    cursosNoHabilitados.insert(pair<string, Curso*>(curso_recordado->getNombre(), curso_recordado));

    /* Notifico que se creo el curso */
    idioma_notificacion = curso_recordado.getIdioma();
    string nombreCurso_notificacion = curso_recordado.getNombre();
    idioma_notificacion.notificarCambio(nombreCurso_notificacion);

    /* Libero memoria */
    curso_recordado = nullptr;
}

vector<DTCurso> ControladorCursos::listarCursosNoHabilitados() {
    vector<DTCurso> salida;
    
    map<string, Curso *>::iterator it;
    for(it = cursosNoHabilitados.begin(); it != cursosNoHabilitados.end(); it++) {
        salida.push_back(it->second->getDTCurso());
    }
    return salida;
}

void ControladorCursos::seleccionarCurso(string nombreCurso) {
    pair<string, Curso *> curso_recordado_par = cursosNoHabilitados.find(nombreCurso);
    if(curso_recordado_par == cursosNoHabilitados.end()) {
        curso_recordado_par = cursosHabilitados.find(nombreCurso);
    }

    curso_recordado = curso_recordado_par.second;
}

void ControladorCursos::crearLeccion(string nombreTema, string objetivo) {
    leccion_recordada = curso_recordado->crearLeccion(nombreTema, objetivo);
}

void ControladorCursos::altaLeccion() {
    lecciones.push_back(leccion_recordada); // si lecciones no se usa podemos eliminar esta linea

    /* Libero memoria */
    curso_recordado = nullptr;
    leccion_recordada = nullptr;
}

vector<DTLeccion> ControladorCursos::listarLeccionesOrdenado() {
    return curso_recordado->listarLeccionesOrdenado();
}

void ControladorCursos::seleccionarLeccion(string nombreTema) {
    leccion_recordada = curso_recordado->seleccionarLeccion(nombreTema);
}

void ControladorCursos::crearEjercicio(TipoEjercicio tipo, string descripcion) {
    tipo_recordado = tipo;
    descripcionEjercicio_recordado = descripcion;
}

void ControladorCursos::agregarDatosCP(string fraseACompletar, string solucion) {
    fraseACompletar_recordada = fraseACompletar;
    solucion_recordada = solucion;
}

void ControladorCursos::agregarDatosTR(string fraseATraducir, string traduccion) {
    fraseATraducir_recordada = fraseATraducir;
    traduccion_recordada = traduccion;
}

void ControladorCursos::altaEjercicio() {
    switch (tipo_recordado) {
    case CompletarPalabras:
        leccion_recordada->crearCP(descripcionEjercicio_recordado, fraseACompletar_recordada, solucion_recordada);
        break;
    case Traduccion:
        leccion_recordada->crearTR(descripcionEjercicio_recordado, fraseATraducir_recordada, traduccion_recordada);
        break;
    }

    /* Libero memoria */
    leccion_recordada = nullptr;
    curso_recordado = nullptr;
    descripcionEjercicio_recordado.clear();
    fraseACompletar_recordada.clear();
    fraseATraducir_recordada.clear();
    solucion_recordada.clear();
    traduccion_recordada.clear();
}

vector<DTCurso> ControladorCursos::listarCursos() {
    vector<DTCurso> salida;
    
    map<string, Curso *>::iterator it;
    for(it = cursosNoHabilitados.begin(); it != cursosNoHabilitados.end(); it++) {
        salida.push_back(it->second->getDTCurso());
    }
    for(it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
        salida.push_back(it->second->getDTCurso());
    }

    return salida;
}

void ControladorCursos::eliminarCurso(string nombreCurso) {
    Curso *cursoAEliminar;
    pair<string, Curso *> par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
        cursosHabilitados.erase(nombreCurso);
    } else {
        cursosNoHabilitados.erase(nombreCurso);
    }
    
    cursoAEliminar = par.second;
    
    delete cursoAEliminar;
}

vector<DTCurso> ControladorCursos::listarCursosNoAprobados(string nickname) {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    estudiante_recordado = cu->getEstudiantes().find(nickname).second; // hay que implementarla
    return cu->listarCursosNoAprobados(nickname);
}

vector<DTEjercicio> ControladorCursos::listarEjerciciosPendientes(string nombreCurso) {
    vector<Inscripcion> inscripciones;
    pair<string, Curso *> par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    curso_recordado = par.second;
    inscripciones = estudiante_recordado->getInscripciones();
    leccion_recordada = inscripciones.find(nombreCurso).second->getCurso();
    return estudiante_recordado->listarEjerciciosPendientes(nombreCurso);
}

void ControladorCursos::seleccionarEjercicio(DTEjercicio ejercicio) {
    ejercicio_recordado = leccion_recordada->getEjercicios()
                                        .find(ejercicio.getDescripcion()).second;
}

void ControladorCursos::ingresarSolucionCP(string sol) {
    solucion_recordada = sol;
}

void ControladorCursos::ingresarSolucionT(string sol) {
    traduccion_recordada = sol;
}

bool ControladorCursos::ejercicioAprobado() {
    bool aprobado;

    if (/* es CompletarPalabras */true) { // como se que subclase es ????
        aprobado = ejercicio_recordado->estaAprobadoCP(solucion_recordada);
    } else {
        aprobado = ejercicio_recordado->estaAprobadoT(traduccion_recordada);
    }

    if (aprobado) {
        estudiante_recordado->actualizarInscripcion(curso_recordado->getNombre());
    }

    /* Libero memoria */
    estudiante_recordado = nullptr;
    curso_recordado = nullptr;
    leccion_recordada = nullptr;
    ejercicio_recordado = nullptr;
    solucion_recordada.clear();
    traduccion_recordada.clear();
}

DTEstCurso ControladorCursos::listarEstCurso(string nombreCurso) {
    Curso *curso;
    pair<string, Curso *> par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    curso = par.second;

    return curso->listarEstCurso();
}

bool ControladorCursos::habilitarCurso() {
    map<string, Leccion *> lecciones;
    map<string, Leccion *>::iterator it;
    bool salida = false;

    lecciones = curso_recordado->getLecciones();
    if (lecciones.begin() != lecciones.end()) { // si hay lecciones
        it = lecciones.begin();
        while (it != lecciones.end() || salida) { // itero por las lecciones
                                                  // y si tiene ejercicio sigo
                                                  // si no tiene retorno true
            if (it->second->getEjerciccios().begin() == it->second->getEjerciccios().end()) {
                salida = true;
            }
            it++;
        }
    } else {
        salida = true;
    }

    /* Libero memoria */
    curso_recordado = nullptr;

    return salida;
}

DTCurso ControladorCursos::getDataCurso(string nombreCurso) {
    pair<string, Curso *> par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    return par.second->getDataCurso();
}
