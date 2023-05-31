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
    curso_recordado = cursosNoHabilitados.find(nombreCurso);
    if(curso_recordado == cursosNoHabilitados.end()) {
        curso_recordado = cursosHabilitados.find(nombreCurso);
    }
}

void ControladorCursos::crearLeccion(string nombreTema, string objetivo);
void ControladorCursos::altaLeccion();
vector<DTLeccion> ControladorCursos::listarLeccionesOrdenado();
void ControladorCursos::seleccionarLeccion(string nombreTema);
void ControladorCursos::crearEjercicio(TipoEjercicio tipo, string descripcion);
void ControladorCursos::agregarDatosCP(string fraseACompletar, string solucion);
void ControladorCursos::agregarDatosTR(string fraseATraducir, string traduccion);
void ControladorCursos::altaEjercicio();
vector<DTCurso> ControladorCursos::listarCursos();
void ControladorCursos::eliminarCurso(string curso);
vector<DTCurso> ControladorCursos::listarCursosNoAprobados(string nickname);
vector<DTEjercicio> ControladorCursos::listarEjerciciosPendientes(string nombreCurso);
void ControladorCursos::seleccionarEjercicio(DTEjercicio ejercicio);
void ControladorCursos::ingresarSolucionCP(string sol);
void ControladorCursos::ingresarSolucionT(string sol);
bool ejercicioAprobado();
DTEstCurso listarEstCurso(string nombreCurso);

