#include <string>
#include "traduccion.hpp"

traduccion::traduccion(string desc,tipoEjercicio t,string fat,string tf) : ejercicio(desc,t){
    this->frase_a_traducir=fat;
    this->traduccion_frase=tf;
}

traduccion::~traduccion(){}

void traduccion::setFrase_a_traducir(string fat){
    this->frase_a_traducir=fat;
}

string traduccion::getFrase_a_traducir(){
    return this->frase_a_traducir;
}

void traduccion::setTraduccion_frase(string tf){
    this->traduccion_frase=tf;
}

string traduccion::getTraduccion_frase(){
    return this->traduccion_frase;
}

bool traduccion::estaAprobadoT(string frase_traducida){
    return frase_traducida==this->traduccion_frase;
}