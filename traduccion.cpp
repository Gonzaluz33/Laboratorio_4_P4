#include "traduccion.hpp"

Traduccion::Traduccion(string desc,TipoEjercicio t,string fat,string tf) : ejercicio(desc,t){
    this->frase_a_traducir=fat;
    this->traduccion_frase=tf;
}

Traduccion::~Traduccion(){}

void Traduccion::setFrase_a_traducir(string fat){
    this->frase_a_traducir=fat;
}

string Traduccion::getFrase_a_traducir(){
    return this->frase_a_traducir;
}

void Traduccion::setTraduccion_frase(string tf){
    this->traduccion_frase=tf;
}

string Traduccion::getTraduccion_frase(){
    return this->traduccion_frase;
}

bool Traduccion::estaAprobadoT(string frase_traducida){
    return frase_traducida==this->traduccion_frase;
}
