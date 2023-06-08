#include "dt_inscripcion.hpp"

DTInscripcion::DTInscripcion(string nombreEstudiante, DTFecha fechaInscripcion):
    nombreEstudiante(nombreEstudiante),
    fechaInscripcion(fechaInscripcion)
{

}

DTInscripcion::~DTInscripcion() {

}

string DTInscripcion::getNombreEstudiante() {
    return nombreEstudiante;
}

DTFecha DTInscripcion::getFechaInscripcion() {
    return fechaInscripcion;
}
