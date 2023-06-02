#include "inscripcion.hpp"

Inscripcion::Inscripcion(DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal, bool cursoAprobado){
    this->fechaInscripcion = fechaInscripcion;
    this->porsentajeEjerciciosRealizados = porEjerReal;
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

int Inscripcion::getPorsentajeEjerciciosRealizados(){
    return this->porsentajeEjerciciosRealizados;
}

void Inscripcion::setPorsentajeEjerciciosRealizados(int p){
    this->porsentajeEjerciciosRealizados = p;
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
   vector<DTEjercicio> SetDTEjercicio;
   for (i = 0; i < this->Ejercicios.size(); i++){
        if(this->Ejercicios[i]->estaPendiente()){
            SetDTEjercicio.push_back(this->Ejercicios[i]->getDataEjercicio());
        }
   }
   return SetDTEjercicios;
   
}

DTEstEstudiante Inscripcion::getEstEstudiante(){
    DTCurso nuevo = this->cursoAsignado->getdataCurso();
    int promedioAvance = this->cursoAsignado->getPromedioAvance();
    DTEstEstudiante* curso = new DtEstEstudiante(nuevo, promedioAvance);
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