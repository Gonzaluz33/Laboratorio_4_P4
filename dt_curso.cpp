#include "dt_curso.hpp"

DTCurso::DTCurso(string nombre, string descripcion, Dificultad dificultad, DTIdioma idioma, 
                 int cantidadLecciones, int cantidadEjercicios, DTProfesor profesor):
    nombre(nombre),
    descripcion(descripcion),
    dificultad(dificultad),
    idioma(idioma),
    cantidadLecciones(cantidadLecciones),
    cantidadEjercicios(cantidadEjercicios),
    profesor(profesor)
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
