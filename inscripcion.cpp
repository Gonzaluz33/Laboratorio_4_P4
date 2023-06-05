#include "inscripcion.hpp"

Inscripcion::Inscripcion(DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal, bool cursoAprobado):
    fechaInscripcion(fechaInscripcion)
{
    this->porcentajeEjerciciosRealizados = porEjerReal;
    this->cantidadEjerciciosRealizados = cantEjerReal;
    this->cursoAprobado = cursoAprobado;
}

Inscripcion::~Inscripcion(){}

DTFecha Inscripcion::getFechaInscripcion(){
    return this->fechaInscripcion;
}

DTCurso Inscripcion::getDataCurso(){

    return this->cursoAsignado->getdataCurso();
}   

int Inscripcion::getPorcentajeEjerciciosRealizados(){
    return this->porcentajeEjerciciosRealizados;
}


int Inscripcion::getCantidadEjerciciosRealizados(){
    return this->cantidadEjerciciosRealizados;
}

bool Inscripcion::getCursoAprobado(){
    return this->cursoAprobado;
}

Leccion* Inscripcion::getLeccionActual(){
    return this->leccionAsignada;
}

vector<DTEjercicio> Inscripcion::listarEjerciciosPendientes(){
    vector<DTEjercicio> SetDTEjercicios;
    map<string, Ejercicio*>::iterator it;
    for (it = this->ejerciciosPendientes.begin(); it != this->ejerciciosPendientes.end(); ++it){
        SetDTEjercicios.push_back(it->second->getDataEjercicio());
    }
   return SetDTEjercicios;
}

DTEstEstudiante Inscripcion::getEstEstudiante(){
    DTCurso nuevo = this->cursoAsignado->getdataCurso();
    int promedioAvance = this->cursoAsignado->getPromedioAvance();
    DTEstEstudiante curso =  DTEstEstudiante(nuevo, promedioAvance);
    return curso;
}

void Inscripcion::incrementarCantEjRealizados(){
    this->cantidadEjerciciosRealizados++;
}

void Inscripcion::eliminarDePendientes(Ejercicio* ej){
    string des_a_comparar = ej->getDescripcion();
    ejerciciosPendientes.erase(des_a_comparar);
}

bool Inscripcion::leccionTerminada(int cantEjActualizado, int totalEj){
    return cantEjActualizado==totalEj;
}
