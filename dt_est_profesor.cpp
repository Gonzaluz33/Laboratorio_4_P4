#include "dt_est_profesor.hpp"


DTEstProfesor::DTEstProfesor(DTCurso c,int promedio){
    this->curso = c;
    this->promedio_avance = promedio;
}

int DTEstProfesor::getPromedioAvance(){
    return this->promedio_avance;
}

DTCurso DTEstProfesor::getCurso(){
    return this->curso;
}
