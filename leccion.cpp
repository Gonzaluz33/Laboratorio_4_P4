#include "leccion.hpp"

Leccion::leccion(int totalE, string nomTema, string objetivo){
    this->totalEjercicios = totalE;
    this->nombreTema = nomTema;
    this->objetivo = objetivo;
}

int Leccion::getTotalEjercicios(){
    return this->totalEjercicios;
}

void Leccion::setTotalEjercicios(int t){
    this->totalEjercicios = t;
}

int Leccion::getCantEjerciciosHechos(){
    return this->cantEjerciciosHechos;
}

void Leccion::setCantTotalHechos(int t){
    this->cantEjerciciosHechos = t;
}    

string Leccion::getNombreTema(){
    return this->nombreTema;
}

void Leccion::setNombreTema(string nom){
    this->nombreTema = nom;
}

string Leccion::getObjetivo(){
    return this->objetivo;
}

void Leccion::setObjetivo(string objetivo){
    this->objetivo = objetivo;
}

void Leccion::crearCP(string descripcion, string fac, string sol){
    Ejercicio* ejercicioNuevo = new CompletarPalabras(descripcion, fac, sol);
    this->Ejercicios.tipo.insert(descripcion, ejercicioNuevo);
}

void Leccion::crearTR( string descripcion, string fat, string trad){
    Ejercicio* ejercicioNuevo = new Traduccion(descripcion, fat, trad);
    this->Ejercicios.tipo.insert(descripcion, ejercicioNuevo);
}