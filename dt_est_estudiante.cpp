#include "dt_est_estudiante.hpp"


DTEstEstudiante::DTEstEstudiante(DTCurso c,int a):
    curso_(c)
{
    this->avance=a;
}

DTEstEstudiante::~DTEstEstudiante(){}

DTCurso DTEstEstudiante::getDTCurso(){
    return this->curso_;
}

int DTEstEstudiante::getAvance(){
    return this->avance;
}
