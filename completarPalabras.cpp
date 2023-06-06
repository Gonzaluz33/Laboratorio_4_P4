#include "completarPalabras.hpp"

CompletarPalabras::CompletarPalabras(string desc, TipoEjercicio t,string fr,string pf):
    Ejercicio(desc,t)
{
    this->frase = fr;
    this->Palabras_faltantes = pf;
}

CompletarPalabras::~CompletarPalabras(){}

string CompletarPalabras::getFrase(){
    return this->frase;
}

string CompletarPalabras::getPalabras_faltantes(){
    return this->Palabras_faltantes;
}

void CompletarPalabras::setFrase(string fr){
    this->frase = fr;
}

void CompletarPalabras::setPalabras_faltantes(string pf){
    this->Palabras_faltantes = pf;
}

bool CompletarPalabras::estaAprobadoCP(string palabras_faltantes){
    return palabras_faltantes == this->Palabras_faltantes;
}
