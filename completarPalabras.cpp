#include "completarPalabras.hpp"
#include "dt_completar_palabras.hpp"

CompletarPalabras::CompletarPalabras(string desc, TipoEjercicio t,string fr,string pf):
    Ejercicio(desc,t)
{
    this->frase = fr;
    this->palabras_faltantes = pf;
}

CompletarPalabras::~CompletarPalabras(){}

string CompletarPalabras::getFrase(){
    return this->frase;
}

string CompletarPalabras::getPalabras_faltantes(){
    return this->palabras_faltantes;
}

void CompletarPalabras::setFrase(string fr){
    this->frase = fr;
}

void CompletarPalabras::setPalabras_faltantes(string pf){
    this->palabras_faltantes = pf;
}

bool CompletarPalabras::estaAprobadoCP(string palabras_faltantes){
    return strtolower(palabras_faltantes) == strtolower(this->palabras_faltantes);
}

DTEjercicio* CompletarPalabras::getDataEjercicio() {
    return new DTCompletarPalabras(this->getDescripcion(), frase, palabras_faltantes);
}
