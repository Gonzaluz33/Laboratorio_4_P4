#include "inscripcion.hpp"

Inscripcion::Inscripcion(DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal, bool cursoAprobado){
    this->fechaInscripcion = fechaInscripcion;
    this->porcentajeEjerciciosRealizados = porEjerReal;
    this->cantidadEjerciciosRealizados = cantEjerReal;
    this->cursoAprobado;
}

Inscripcion::~Inscripcion(){}

DTFecha Inscripcion::getFechaInscripcion(){
    return this->fechaIncripcion;
}

void Inscripcion::setFechaInscripcion(DTFecha f){
    this->fechaInscripcion = f;
}
int Inscripcion::getCantEjerciciosHechos(){
    return this->cantEjerciciosHechos;
}
    
void Inscripcion::setCantTotalHechos(int t){
    this->cantEjerciciosHechos = t;
}

int Inscripcion::getPorcentajeEjerciciosRealizados(){
    return this->porcentajeEjerciciosRealizados;
}

void Inscripcion::setPorcentajeEjerciciosRealizados(int p){
    this->porcentajeEjerciciosRealizados = p;
}

int Inscripcion::getCantidadEjerciciosRealizados(){
    return this->cantidadEjerciciosRealizados;
}
void Inscripcion::setCantidadEjerciciosRealizados(int cant){
    this->cantidadEjerciciosRealizados = cant;
}

bool Inscripcion::getCursoAprobado(){
    return this->cursoAprobado;
}

void Inscripcion::setCursoAprobado(bool curso){
    this->cursoAprobado = curso;
}
Leccion* Inscripcion::getLeccionActual(){
    return this->leccionAsignada;
}

vector<DTEjercicio> Inscripcion::listarEjerciciosPendientes(){
   map<string,DTEjercicio> SetDTEjercicio;
    for (it=this->Incripciones.begin(); it!=this->Inscripciones.end(); ++it){
        if(this->Ejercicios[it]->estaPendiente()){
            SetDTEjercicio.insert(this->Ejercicios[it]->getDataEjercicio());
        }
   }
   return SetDTEjercicios;
   
}

DTEstEstudiante Inscripcion::getEstEstudiante(){
    DTCurso nuevo = this->cursoAsignado->getdataCurso();
    int promedioAvance = this->cursoAsignado->getPromedioAvance();
    DTEstEstudiante curso =  DtEstEstudiante(nuevo, promedioAvance);
    return curso;
}

void Inscripcion::incrementarCantEjRealizados(){
    this->cantidadEjerciciosRealizados++;
}

void Inscripcion::eliminarDePendientes(Ejercicio* ej){
    string des_a_comparar = ej->getDescripcion();
    vector<Ejercicio*>::iterator it;
    for(it = this->Ejercicios.begin(); it != this->Ejercicios.end(); ++it){
        if(des_a_comparar == *it->getDescripcion()){   
            Ejercicio* borrar = *it;
            delete borrar;
            this->Ejercicios.erase(it);
        }
    }
}

bool Inscripcion::leccionTerminada(int cantEjActualizado, int totalEj){
    return cantEjActualizado==totalEj;
}
int Inscripcion::getPorcentajeEjerciciosRealizados(){
    return this->porsentajeEjerciciosRealizados;
}