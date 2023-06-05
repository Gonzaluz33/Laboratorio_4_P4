#include "leccion.hpp"
#include "ejercicio.hpp"
#include "completarPalabras.hpp"
#include "traduccion.hpp"

Leccion::Leccion(int totalE, string nomTema, string objetivo){
    this->totalEjercicios = totalE;
    this->nombreTema = nomTema;
    this->objetivo = objetivo;
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
}

void Leccion::crearTR( string descripcion, string fat, string trad){
    Ejercicio* ejercicioNuevo = new Traduccion(descripcion, Trad, fat, trad);
    this->ejercicios.insert(pair<string, Ejercicio*>(descripcion, ejercicioNuevo));
}
