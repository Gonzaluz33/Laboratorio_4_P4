#include "curso.hpp"

Curso::Curso(string nombre, string descripcion, Dificultad dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
}

Curso::~Curso(){}

string Curso::getNombre(){
    return this->nombre;
}

void Curso::setNombre(string nom){
    this->nombre = nom;
}

string Curso::getDescripcion(){
    return this->descripcion;
}

void Curso::setDescripcion(string des){
    this->descripcion = des;
} 

Dificultad Curso::getDificultad(){
    return this->dificultad;
}

void Curso::setDificultad(Dificultad dif){
    this->dificultad = dif;
}

DTCurso Curso::getdataCurso(){
    DTCurso* cursoNuevo = new DTCurso(this->getNombre(),this->getDescripcion(), this->getDificultad(),this->getIdioma(),
            this->getCantidadLecciones(), this->getCantidadEjercicios(), this->getProfesor());
    return cursoNuevo;
}

int Curso::getTotalEjercicios(){
    int totalEjercicios = 0;
    for (i=0; i < this->Lecciones.size>>; i++){
        totalEjercicios = totalEjercicios + Lecciones[i]->getCantEjercicios();
    }
    return totalEjercicios;
}

void Curso::crearLeccion(string nombreTema, string objetivo){
    Leccion* leccionNueva = new Leccion(nombreTema, objetivo, this->getTotalEjercicios());
    this->Lecciones.push_back(leccionNueva);
}

DTEstCurso Curso::listarEstCurso(string nickname){
    int est = 0;
    DTEstCurso nuevo = DTEstCurso(this->getPromedioAvance(), this->getdataCurso());
    return nuevo;
}

int Curso::getPromedioAvance(){
    int Avance = 0;
    for (it=this->Incripciones.begin(); it!=this->Inscripciones.end(); ++it){
        Avance = Avance + Inscripciones[it]->porcentajeEjerciciosRealizados;
    }
    return Avance/Inscripciones.size();
}

