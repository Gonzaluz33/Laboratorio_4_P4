#include "dt_curso.hpp"

DTCurso::DTCurso(string nombre, string descripcion, Dificultad dificultad, DTIdioma idioma, 
                 int cantidadLecciones, int cantidadEjercicios, DTProfesor profesor,
                 bool estaHabilitado, vector<DTLeccion> lecciones, 
                 vector<DTInscripcion> inscripciones):
    nombre(nombre),
    descripcion(descripcion),
    dificultad(dificultad),
    idioma(idioma),
    cantidadLecciones(cantidadLecciones),
    cantidadEjercicios(cantidadEjercicios),
    profesor(profesor),
    estaHabilitado(estaHabilitado),
    lecciones(lecciones),
    inscripciones(inscripciones)
{
}

DTCurso::~DTCurso() {

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

DTProfesor DTCurso::getProfesor() {
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
