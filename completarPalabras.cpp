#include "completarPalabras.hpp"

completarPalabras::completarPalabras(string desc,tipoEjercicio t,string fr,string pf) : ejercicio(desc,t){
    this->frase = fr;
    this->Palabras_faltantes = pf;
}

completarPalabras::~completarPalabras(){}

string completarPalabras::getFrase(){
    return this->frase;
}

string completarPalabras::getPalabras_faltantes(){
    return this->Palabras_faltantes;
}

void completarPalabras::setFrase(string fr){
    this->frase = fr;
}

void completarPalabras::setPalabras_faltantes(string pf){
    this->Palabras_faltantes;
}

bool completarPalabras::estaAprobadoCP(string palabras_faltantes){
    return palabras_faltantes==this->Palabras_faltantes;
}