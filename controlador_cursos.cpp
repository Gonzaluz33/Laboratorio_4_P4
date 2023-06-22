#include "controlador_cursos.hpp"
#include "controlador_usuarios.hpp"
#include "profesor.hpp"
#include "estudiante.hpp"
#include "inscripcion.hpp"
#include "ejercicio.hpp"
#include "completarPalabras.hpp"
#include "traduccion.hpp"
#include <ctime>

ControladorCursos::ControladorCursos() {

}

ControladorCursos::~ControladorCursos() {

    map<string, Curso *>::iterator it_c;
    for (it_c = cursosHabilitados.begin(); it_c != cursosHabilitados.end(); it_c++) {
        delete it_c->second;
    }
    map<string, Curso *>::iterator it_c2;
    cursosHabilitados.clear();
    for (it_c2 = cursosNoHabilitados.begin(); it_c2 != cursosNoHabilitados.end(); it_c2++) {
        delete it_c2->second;
    }
    cursosNoHabilitados.clear();
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
    idioma_recordado = idioma.getNombre();
}

vector<DTCurso> ControladorCursos::listarCursosHabilitados() {
    vector<DTCurso> salida;
    map<string, Curso*>::iterator it;
    for(it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
        salida.push_back(it->second->getdataCurso());
    }
    return salida;
}

void ControladorCursos::seleccionarCursosPrevios(string nombre) {
    nombresCursosPrevios.push_back(nombre);
}

void ControladorCursos::crearCurso() {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    Profesor *profesor = dynamic_cast<Profesor*>(cu->buscarUsuario(nickname_recordado));
    Idioma *idioma = cu->getIdiomas().find(idioma_recordado)->second;
    vector<Curso*> cursosPrevios;
    vector<string>::iterator it;
    for (it = nombresCursosPrevios.begin(); it != nombresCursosPrevios.end(); it++) {
        map<string,Curso*>::iterator iter = cursosHabilitados.find(*it);
        cursosPrevios.push_back(iter->second);
    }
    curso_recordado = new Curso(nombreCurso_recordado, descripcion_recordado,
                                dificultad_recordado, profesor,
                                idioma, cursosPrevios);

    /* Libero memoria */
    nombresCursosPrevios.clear();
    nickname_recordado.clear();
    nombreCurso_recordado.clear();
    descripcion_recordado.clear();
}

void ControladorCursos::darAltaCurso() {
    Idioma *idioma_notificacion;
    
    cursosNoHabilitados.insert(pair<string, Curso*>(curso_recordado->getNombre(), curso_recordado));

    /* Notifico que se creo el curso */
    idioma_notificacion = curso_recordado->getIdioma();
    string nombreCurso_notificacion = curso_recordado->getNombre();
    idioma_notificacion->notificarCambio(nombreCurso_notificacion);

    curso_recordado = nullptr;
}

vector<DTCurso> ControladorCursos::listarCursosNoHabilitados() {
    vector<DTCurso> salida;
    
    map<string, Curso *>::iterator it;
    for(it = cursosNoHabilitados.begin(); it != cursosNoHabilitados.end(); it++) {
        salida.push_back(it->second->getdataCurso());
    }
    return salida;
}

void ControladorCursos::seleccionarCurso(string nombreCurso) {
    map<string, Curso *>::iterator curso_recordado_par = cursosNoHabilitados.find(nombreCurso);
    if(curso_recordado_par == cursosNoHabilitados.end()) {
        curso_recordado_par = cursosHabilitados.find(nombreCurso);
    }

    curso_recordado = curso_recordado_par->second;
}

void ControladorCursos::crearLeccion(string nombreTema, string objetivo) {
    leccion_recordada = curso_recordado->crearLeccion(nombreTema, objetivo);
}

void ControladorCursos::altaLeccion() {

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
    case CompPalabras:
        leccion_recordada->crearCP(descripcionEjercicio_recordado, fraseACompletar_recordada, solucion_recordada);
        break;
    case Trad:
        leccion_recordada->crearTR(descripcionEjercicio_recordado, fraseATraducir_recordada, traduccion_recordada);
        break;
    }

    /* Libero memoria */
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
        salida.push_back(it->second->getdataCurso());
    }
    for(it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
        salida.push_back(it->second->getdataCurso());
    }

    return salida;
}

void ControladorCursos::eliminarCurso(string nombreCurso) {
    Curso *cursoAEliminar;
    map<string, Curso *>::iterator par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
        cursosHabilitados.erase(nombreCurso);
    } else {
        cursosNoHabilitados.erase(nombreCurso);
    }
    
    cursoAEliminar = par->second;
    
    delete cursoAEliminar;
}

vector<DTCurso> ControladorCursos::listarCursosNoAprobados(string nickname) {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    estudiante_recordado = dynamic_cast<Estudiante*>(cu->buscarUsuario(nickname));
    return cu->listarCursosNoAprobados(nickname);
}

vector<DTEjercicio*> ControladorCursos::listarEjerciciosPendientes(string nombreCurso) {
    map<string, Inscripcion*> inscripciones;
    map<string, Curso *>::iterator par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    curso_recordado = par->second;
    inscripciones = estudiante_recordado->getInscripciones();
    leccion_recordada = inscripciones.find(nombreCurso)->second->getLeccionActual();
    return estudiante_recordado->listarEjerciciosPendientes(nombreCurso);
}

void ControladorCursos::seleccionarEjercicio(DTEjercicio ejercicio) {
    ejercicio_recordado = leccion_recordada->getEjercicios()
                                        .find(ejercicio.getDescripcion())->second;
}

void ControladorCursos::ingresarSolucionCP(string sol) {
    solucion_recordada = sol;
}

void ControladorCursos::ingresarSolucionT(string sol) {
    traduccion_recordada = sol;
}

bool ControladorCursos::ejercicioAprobado() {
    bool aprobado;

    CompletarPalabras *ejCP = dynamic_cast<CompletarPalabras*>(ejercicio_recordado);
    if (ejCP) {
        aprobado = ejCP->estaAprobadoCP(solucion_recordada);
    } else {
        Traduccion *ejTR = dynamic_cast<Traduccion*>(ejercicio_recordado);
        aprobado = ejTR->estaAprobadoT(traduccion_recordada);
    }

    if (aprobado) {
        estudiante_recordado->actualizarInscripcion(curso_recordado->getNombre(), ejercicio_recordado);
    }

    /* Libero memoria */
    estudiante_recordado = nullptr;
    curso_recordado = nullptr;
    leccion_recordada = nullptr;
    ejercicio_recordado = nullptr;
    solucion_recordada.clear();
    traduccion_recordada.clear();

    return aprobado;
}

DTEstCurso ControladorCursos::listarEstCurso(string nombreCurso) {
    Curso *curso;
    map<string, Curso *>::iterator par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    curso = par->second;

    return curso->listarEstCurso();
}

bool ControladorCursos::habilitarCurso() {
    vector<Leccion*> lecciones;
    vector<Leccion*>::iterator it;
    bool salida = false;

    lecciones = curso_recordado->getLecciones();
    if (lecciones.begin() != lecciones.end()) { // si hay lecciones
        it = lecciones.begin();
        while (it != lecciones.end() && !salida) { // itero por las lecciones
                                                  // y si tiene ejercicio sigo
                                                  // si no tiene retorno true
            map<string, Ejercicio*> ejercicios = (*it)->getEjercicios();
            if ((*it)->getEjercicios().begin() == (*it)->getEjercicios().end()) {
                salida = true;
            }
            it++;
        }
    } else {
        salida = true;
    }
    if (!salida) {
        cursosNoHabilitados.erase(curso_recordado->getNombre());
        cursosHabilitados.insert(pair<string, Curso*>(curso_recordado->getNombre(),
                                                      curso_recordado));
        curso_recordado->setEstaHabilitado(true);
    }

    /* Libero memoria */
    curso_recordado = nullptr;

    return salida;
}

DTCurso ControladorCursos::getDataCurso(string nombreCurso) {
    map<string, Curso *>::iterator par = cursosNoHabilitados.find(nombreCurso);
    if(par == cursosNoHabilitados.end()) {
        par = cursosHabilitados.find(nombreCurso);
    }
    return par->second->getdataCurso();
}

static bool estaApto(Estudiante *estudiante, vector<Curso *> cursosPrevios) {
    bool estaAprobado = true;
    vector<Curso*>::iterator it = cursosPrevios.begin();
    while (it != cursosPrevios.end() && estaAprobado) {
        Inscripcion *inscripcion = estudiante->getInscripcionDeCurso((*it)->getNombre());
        if (inscripcion == nullptr) {
            estaAprobado = false;
        } else {
            estaAprobado = inscripcion->getCursoAprobado();
        }
        it++;
    }
    return estaAprobado;
}

vector<DTCurso> ControladorCursos::listarCursosDisponibles(string nickname) {
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    Estudiante *estudiante = dynamic_cast<Estudiante*>(cu->buscarUsuario(nickname));
    vector<DTCurso> salida;
    map<string, Curso*>::iterator it;
    for (it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
        if (estaApto(estudiante, it->second->getCursosPrevios())) {
            salida.push_back(it->second->getdataCurso());
        }
    }
    this->estudiante_recordado = estudiante;
    return salida;
}

Ejercicio *ControladorCursos::getEjercicioRecordado(){
    return this->ejercicio_recordado;
}

void ControladorCursos::inscribirseACurso(DTCurso curso){
    time_t tiempoActual = time(nullptr);
    tm* fechaHora = localtime(&tiempoActual);
    int anio = fechaHora->tm_year + 1900; // tm_year cuenta los años a partir de 1900
    int mes = fechaHora->tm_mon + 1;      // tm_mon cuenta los meses desde 0 (enero)
    int dia = fechaHora->tm_mday; 
    DTFecha fecha = DTFecha(dia,mes,anio);
    string nombre = curso.getNombre();
    Curso* cursoActual = this->cursosHabilitados.find(nombre)->second;
    this->estudiante_recordado->inscribirse(cursoActual,fecha);
    
}

void ControladorCursos::agregarCursoPrevio(string nombreCurso, string nombreCursoPrevio) {
    map<string,Curso*>::iterator it = cursosHabilitados.find(nombreCurso);
    if (it == cursosHabilitados.end()) {
        it = cursosNoHabilitados.find(nombreCurso);
    }
    Curso *curso = it->second;
    Curso *cursoPrevio = cursosHabilitados.find(nombreCursoPrevio)->second;

    curso->agregarCursoPrevio(cursoPrevio);
}
