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

Dificultad Curso::getDifiultad(){
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
    for(i = 0; i < Lecciones.size(); i++){
        totalEjercicios = totalEjercicios + Lecciones[i]->getCantEjercicios();
    }
    return totalEjercicios;
}

void Curso::crearLeccion(string nombreTema, string objetivo){
    Leccion* leccionNueva = new Leccion(nombreTema, objetivo, this->getTotalEjercicios());
    this->Lecciones.push_back(leccionNueva);
}

vector<DTEstEstudiante*> Curso::listarEstCurso(){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Estudiante e = cu->buscarUsuario(nickname);
    vector<DTEstEstudiante*> setDTEstEstudiante;
    for (i = 0; i < e->Inscripciones.size(); i++){
        setDTEstudiante.push_back(e->Inscripciones[i]->getEstEstudiante());
    }
    return setDtEstEstudiante;
}

int Curso::getPromedioAvance(){
    int Avance = 0;
    for (i = 0; i < Inscripciones.size(); i++){
        Avance = Avance + Inscripciones[i]->porsentajeEjerciciosRealizados;
    }
    return Avance/Inscripciones.size();
}

