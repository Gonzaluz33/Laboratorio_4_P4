#include "dt_leccion.hpp"
#include "dt_completar_palabras.hpp"
#include "dt_traduccion.hpp"
#include <iostream>

using namespace std;

DTLeccion::DTLeccion(string nombreTema, string objetivo, int totalDeEjercicios, vector<DTEjercicio*> ejercicios):
    nombreTema(nombreTema),
    objetivo(objetivo),
    totalDeEjercicios(totalDeEjercicios),
    ejercicios(ejercicios)
{
}

DTLeccion::DTLeccion(const DTLeccion &otro) {
    if (this != &otro) {
        nombreTema = otro.nombreTema;
        objetivo = otro.objetivo;
        totalDeEjercicios = otro.totalDeEjercicios;
        vector<DTEjercicio*>::const_iterator it;
        for (it = otro.ejercicios.begin(); it != otro.ejercicios.end(); it++) {
            DTCompletarPalabras *cp = dynamic_cast<DTCompletarPalabras*>(*it);
            if (cp) {
                ejercicios.push_back(new DTCompletarPalabras(*cp));
            } else {
                DTTraduccion *t = dynamic_cast<DTTraduccion*>(*it);
                ejercicios.push_back(new DTTraduccion(*t));
            }
        }
    }
}

// no se si hay que destruir el vector o se destruye solo
DTLeccion::~DTLeccion() {
    vector<DTEjercicio*>::iterator it;
    for (it = ejercicios.begin(); it != ejercicios.end(); it++) {
        delete *it;
    }
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
