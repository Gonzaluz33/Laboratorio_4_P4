#include "dt_ejercicio.hpp"

DTEjercicio::DTEjercicio(string descripcion):
    descripcion(descripcion)
{
}

string DTEjercicio::getDescripcion() {
    return descripcion;
}
