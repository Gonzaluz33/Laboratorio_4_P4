#include "curso.hpp"
#include "profesor.hpp"
#include "inscripcion.hpp"

Curso::Curso(string nombre, string descripcion, Dificultad dificultad, Profesor *profesor, Idioma *idioma, vector<Curso*> cursosPrevios) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->profesorAsignado = profesor;
    this->idioma = idioma;
    this->cursosPrevios = cursosPrevios;
    this->estaHabilitado = false;
}

Curso::~Curso(){
    vector <Leccion*>::iterator it_l;
    for(it_l = lecciones.begin(); it_l != lecciones.end(); it_l++) {
        delete *it_l;
    }
}

string Curso::getNombre(){
    return this->nombre;
}

string Curso::getDescripcion(){
    return this->descripcion;
}

Dificultad Curso::getDificultad(){
    return this->dificultad;
}

DTCurso Curso::getdataCurso(){
    vector<DTLeccion> dts_lecciones;
    vector<Leccion*>::iterator it_leccion;
    for(it_leccion = lecciones.begin(); it_leccion != lecciones.end(); it_leccion++) {
        dts_lecciones.push_back(DTLeccion((*it_leccion)->getDataLeccion()));
    }

    vector<DTInscripcion> dts_inscripciones;
    map<string, Inscripcion*>::iterator it_inscripcion;
    for(it_inscripcion = inscripciones.begin(); it_inscripcion != inscripciones.end(); it_inscripcion++) {
        dts_inscripciones.push_back(it_inscripcion->second->getDataInscripcion());
    }

    return DTCurso(this->getNombre(),this->getDescripcion(), this->getDificultad(),
            this->idioma->getDataIdioma(), lecciones.size(), this->getTotalEjercicios(),
            dynamic_cast<DTProfesor*>(this->profesorAsignado->getDataUsuario()),
            this->estaHabilitado, dts_lecciones, dts_inscripciones);
}

int Curso::getTotalEjercicios(){
    int totalEjercicios = 0;
    vector<Leccion *>::iterator it;
    for (it=lecciones.begin(); it != lecciones.end(); it++){
        totalEjercicios = totalEjercicios + (*it)->getTotalEjercicios();
    }
    return totalEjercicios;
}

Leccion *Curso::crearLeccion(string nombreTema, string objetivo){
    Leccion* leccionNueva = new Leccion(this->getTotalEjercicios(), nombreTema, objetivo);
    this->lecciones.push_back(leccionNueva);
    return leccionNueva;
}

DTEstCurso Curso::listarEstCurso(){
    DTEstCurso nuevo = DTEstCurso(this->getPromedioAvance(), this->getdataCurso());
    return nuevo;
}

int Curso::getPromedioAvance(){
    int Avance = 0;
    map<string,Inscripcion*>::iterator it;
    for (it = inscripciones.begin(); it != inscripciones.end(); ++it){
        Avance = Avance + it->second->getPorcentajeEjerciciosRealizados();
    }
    return (inscripciones.size() != 0) ? Avance/inscripciones.size() : 0;
}

vector<Leccion*> Curso::getLecciones() {
    return lecciones;
}

Idioma *Curso::getIdioma() {
    return idioma;
}

vector<DTLeccion> Curso::listarLeccionesOrdenado() {
    vector<DTLeccion> salida;
    vector<Leccion*>::iterator it;
    for (it = lecciones.begin(); it != lecciones.end(); it++) {
        salida.push_back((*it)->getDataLeccion());
    }
    return salida;
}

Leccion *Curso::seleccionarLeccion(string nombreTema) {
    vector<Leccion *>::iterator it = lecciones.begin();
    while((*it)->getNombreTema() != nombreTema) {
        it++;
    }
    return *it;
}

vector<Curso*> Curso::getCursosPrevios() {
    return cursosPrevios;
}

void Curso::setEstaHabilitado(bool valor) {
    estaHabilitado = valor;
}

void Curso::agregarInscripcion(Inscripcion* insc,string nickname_est){
    this->inscripciones.insert(pair<string,Inscripcion*>(nickname_est, insc));
}

void Curso::agregarCursoPrevio(Curso *cursoPrevio) {
    this->cursosPrevios.push_back(cursoPrevio);
}
