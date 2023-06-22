#include "leccion.hpp"
#include "ejercicio.hpp"
#include "completarPalabras.hpp"
#include "traduccion.hpp"

Leccion::Leccion(string nomTema, string objetivo){
    this->totalEjercicios = 0;
    this->nombreTema = nomTema;
    this->objetivo = objetivo;
}

Leccion::~Leccion() {
    map<string, Ejercicio*>::iterator it;
    for(it = ejercicios.begin(); it != ejercicios.end(); it++) {
        delete it->second;
    }
    ejercicios.clear();
}

int Leccion::getTotalEjercicios(){
    return this->totalEjercicios;
}


int Leccion::getCantEjerciciosHechos(){
    return this->cantEjerciciosHechos;
}

string Leccion::getNombreTema(){
    return this->nombreTema;
}

string Leccion::getObjetivo(){
    return this->objetivo;
}

void Leccion::crearCP(string descripcion, string fac, string sol){
    Ejercicio* ejercicioNuevo = new CompletarPalabras(descripcion, CompPalabras, fac, sol);
    ejercicios.insert(pair<string, Ejercicio*>(descripcion, ejercicioNuevo));
    totalEjercicios++;
}

void Leccion::crearTR( string descripcion, string fat, string trad){
    Ejercicio* ejercicioNuevo = new Traduccion(descripcion, Trad, fat, trad);
    this->ejercicios.insert(pair<string, Ejercicio*>(descripcion, ejercicioNuevo));
    totalEjercicios++;
}

map<string, Ejercicio*> Leccion::getEjercicios() {
    return ejercicios;
}

DTLeccion Leccion::getDataLeccion() {
    vector<DTEjercicio*> dts_ejercicios;
    map<string, Ejercicio*>::iterator it;
    for (it = ejercicios.begin(); it != ejercicios.end(); it++) {
        dts_ejercicios.push_back(it->second->getDataEjercicio());
    }
    return DTLeccion(nombreTema, objetivo, totalEjercicios, dts_ejercicios);
}
