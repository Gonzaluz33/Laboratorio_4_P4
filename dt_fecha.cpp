#include "dt_fecha.hpp"


DTFecha::DTFecha(int d,int m, int a){
    this->dia=d;
    this->mes=m;
    this->anio=a;
}

DTFecha::~DTFecha(){}

int DTFecha::getDia(){
    return this->dia;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
}
ostream& operator<<(ostream& os, DTFecha fecha){ 
    os << to_string(fecha.getDia()) + "/" + to_string(fecha.getMes()) +  "/" + to_string(fecha.getAnio());
  return os;
}
