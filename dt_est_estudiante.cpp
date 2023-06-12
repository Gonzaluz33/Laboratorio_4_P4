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

ostream& operator<<(ostream& os, DTEstEstudiante estEstudiante){ 
    DTCurso curso = estEstudiante.getDTCurso();
    os << "Nombre del curso: " + curso.getNombre() + "\nAvance Correspondiente: " + to_string(estEstudiante.getAvance()) + "%";
    return os;
}

