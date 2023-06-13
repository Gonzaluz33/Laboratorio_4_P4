#ifndef LECCION_HPP
#define LECCION_HPP

#include <string>
#include "dt_leccion.hpp"
#include "tipo_ejercicio.hpp"
#include "ejercicio.hpp"
#include <vector>
#include <map>
using namespace std;

class Leccion{
private:
    int totalEjercicios;
    int cantEjerciciosHechos;
    string nombreTema;
    string objetivo;
    map<string, Ejercicio*> ejercicios;
public:
    Leccion(int totalE, string nomTema, string objetivo);
    ~Leccion();
    int getTotalEjercicios();
    int getCantEjerciciosHechos();
    string getNombreTema();
    string getObjetivo();
    void crearCP(string descripcion,string fac, string sol);
    void crearTR(string descripcion, string fat, string trad);
    map<string, Ejercicio*> getEjercicios();
    DTLeccion getDataLeccion();
};

#endif
