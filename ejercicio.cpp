#include "ejercicio.hpp"

ejercicio::ejercicio(string desc,tipoEjercicio t){
    this->descripcion = desc;
    this->tipo = t;
}

ejercicio::~ejercicio(){}

string ejercicio::getDescripcion(){
    return this->descripcion;
}

void ejercicio::setDescripcion(string desc){
    this->descripcion = desc;
}

tipoEjercicio ejercicio::getTipo(){
    return this->tipo;
}

void ejercicio::setTipo(tipoEjercicio t){
    this->tipo = t;
}
DTEjercicio ejercicio::getDataEjercicio(){
    DTEjercicio dte = DTEjercicio(this->descripcion,this->tipo);
    return dte;
}