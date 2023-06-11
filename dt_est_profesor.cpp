#include "dt_est_profesor.hpp"


DTEstProfesor::DTEstProfesor(DTCurso c,int promedio):
    curso(c)
{
    this->promedio_avance = promedio;
}

DTEstProfesor::~DTEstProfesor(){}

int DTEstProfesor::getPromedioAvance(){
    return this->promedio_avance;
}

DTCurso DTEstProfesor::getCurso(){
    return this->curso;
}

ostream& operator<<(ostream& os, DTEstProfesor estProfesor){ 
    DTCurso curso = estProfesor.getCurso();
    os << "Nombre del curso: " + curso.getNombre() + "Avance Correspondiente: " + char(estProfesor.getPromedioAvance());
    return os;
}