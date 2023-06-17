#include "ejercicio.hpp"

Ejercicio::Ejercicio(string desc, TipoEjercicio t){
    this->descripcion = desc;
    this->tipo = t;
}

Ejercicio::~Ejercicio(){}

string Ejercicio::getDescripcion(){
    return this->descripcion;
}

void Ejercicio::setDescripcion(string desc){
    this->descripcion = desc;
}

TipoEjercicio Ejercicio::getTipo(){
    return this->tipo;
}

void Ejercicio::setTipo(TipoEjercicio t){
    this->tipo = t;
}

string Ejercicio::strtolower(string entrada) {
    string salida = entrada;
    for(char &caracter : salida) {
        caracter = tolower(caracter);
    }
    return salida;
}
