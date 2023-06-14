#include "dt_curso.hpp"

DTCurso::DTCurso(string nombre, string descripcion, Dificultad dificultad, DTIdioma idioma, 
                 int cantidadLecciones, int cantidadEjercicios, DTProfesor *profesor,
                 bool estaHabilitado, vector<DTLeccion> lecciones, 
                 vector<DTInscripcion> inscripciones, vector<DTCurso> cursosPrevios):
    nombre(nombre),
    descripcion(descripcion),
    dificultad(dificultad),
    idioma(idioma),
    cantidadLecciones(cantidadLecciones),
    cantidadEjercicios(cantidadEjercicios),
    profesor(profesor),
    estaHabilitado(estaHabilitado),
    lecciones(lecciones),
    inscripciones(inscripciones),
    cursosPrevios(cursosPrevios)
{
}

DTCurso::DTCurso(const DTCurso &otro):
    idioma(otro.idioma),
    nombre(otro.nombre),
    descripcion(otro.descripcion),
    dificultad(otro.dificultad),
    cantidadLecciones(otro.cantidadLecciones),
    cantidadEjercicios(otro.cantidadEjercicios),
    estaHabilitado(otro.estaHabilitado),
    lecciones(otro.lecciones),
    inscripciones(otro.inscripciones)
{
    if (this != &otro) {
        profesor = new DTProfesor(*otro.profesor);
    }
}

DTCurso::~DTCurso() {
    delete profesor;
}

string DTCurso::getNombre() {
    return nombre;
}

string DTCurso::getDescripcion() {
    return descripcion;
}

Dificultad DTCurso::getDificultad() {
    return dificultad;
}

DTIdioma DTCurso::getIdioma() {
    return idioma;
}

int DTCurso::getCantidadLecciones() {
    return cantidadLecciones;
}

int DTCurso::getCantidadEjercicios() {
    return cantidadEjercicios;
}

DTProfesor *DTCurso::getProfesor() {
    return profesor;
}

bool DTCurso::getEstaHabilitado() {
    return estaHabilitado;
}

vector<DTLeccion> DTCurso::getLecciones() {
    return lecciones;
}

vector<DTInscripcion> DTCurso::getInscripciones() {
    return inscripciones;
}

vector<DTCurso> DTCurso::getCursosPrevios() {
    return cursosPrevios;
}
