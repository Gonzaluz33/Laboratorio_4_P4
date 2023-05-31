#ifndef DT_LECCION_HPP
#define DT_LECCION_HPP

#include <string>
#include <vector>
#include "dt_ejercicio.hpp"

using namespace std;

class DTLeccion {
public:
    DTLeccion(string nombreTema, string objetivo, int totalDeEjercicios, vector<DTEjercicio> ejercicios);
    ~DTLeccion();
    string getNombreTema();
    string getObjetivo();
    int getTotalDeEjercicios();
    vector<DTEjercicio> getEjercicios();
private:
    string nombreTema, objetivo;
    int totalDeEjercicios;
    vector<DTEjercicio> ejercicios;
};

#endif
