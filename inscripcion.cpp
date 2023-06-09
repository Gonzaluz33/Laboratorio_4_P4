#include "inscripcion.hpp"

// DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal
Inscripcion::Inscripcion(Curso *curso, Estudiante *estudiante, DTFecha fechaInscripcion):
    fechaInscripcion(fechaInscripcion)
{
    this->cursoAsignado = curso;
    this->estudianteAsignado = estudiante;
    this->porcentajeEjerciciosRealizados = 0;
    this->cantidadEjerciciosRealizados = 0;
    this->cursoAprobado = false;
    this->leccionAsignada = curso->getLecciones().front();

    this->ejerciciosPendientes = leccionAsignada->getEjercicios();
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
    if (ejerciciosPendientes.size() == 0) {
        vector<Leccion*>::iterator it;
        vector<Leccion*> lecciones = cursoAsignado->getLecciones();
        it = lecciones.begin();
        while (it != lecciones.end() && (*it) != leccionAsignada) {
            it++;
        }
        leccionAsignada = *(it++);

        if(leccionAsignada == lecciones.back()) {
            cursoAprobado = true;
        } else {
            ejerciciosPendientes = leccionAsignada->getEjercicios();
        }
    }
}

Curso *Inscripcion::getCurso() {
    return cursoAsignado;
}

/* Parece que no lo usamos
bool Inscripcion::leccionTerminada(int cantEjActualizado, int totalEj){
    return cantEjActualizado==totalEj;
}
*/
