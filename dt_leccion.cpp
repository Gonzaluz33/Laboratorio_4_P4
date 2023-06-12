#include "dt_leccion.hpp"

DTLeccion::DTLeccion(string nombreTema, string objetivo, int totalDeEjercicios, vector<DTEjercicio*> ejercicios):
    nombreTema(nombreTema),
    objetivo(objetivo),
    totalDeEjercicios(totalDeEjercicios),
    ejercicios(ejercicios)
{
}

// no se si hay que destruir el vector o se destruye solo
DTLeccion::~DTLeccion() {

}

string DTLeccion::getNombreTema() {
    return nombreTema;
}

string DTLeccion::getObjetivo() {
    return objetivo;
}

int DTLeccion::getTotalDeEjercicios() {
    return totalDeEjercicios;
}

vector<DTEjercicio*> DTLeccion::getEjercicios() {
    return ejercicios;
}
