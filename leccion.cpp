#include "leccion.hpp"

Leccion::leccion(int totalE, string nomTema, string objetivo){
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
    Ejercicio* ejercicioNuevo = new CompletarPalabras(descripcion, fac, sol);
    this->Ejercicios.tipo.insert(descripcion, ejercicioNuevo);
}

void Leccion::crearTR( string descripcion, string fat, string trad){
    Ejercicio* ejercicioNuevo = new Traduccion(descripcion, fat, trad);
    this->Ejercicios.tipo.insert(descripcion, ejercicioNuevo);
}