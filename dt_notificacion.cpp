#include "dt_notificacion.hpp"
#include <string>

DTNotificacion::DTNotificacion(string nombre_curso, string nombre_idioma):
    nombre_curso(nombre_curso),
    nombre_idioma(nombre_idioma)
{
}

DTNotificacion::~DTNotificacion(){

}

string DTNotificacion::getNombreCurso(){
    return this->nombre_curso;
}

string DTNotificacion::getNombreIdioma(){
    return this->nombre_idioma;
}

ostream& operator<<(ostream& os, DTNotificacion notificacion){ 
    os << "Nombre del curso: " + notificacion.getNombreCurso() + "\nIdioma Correspondiente: " + notificacion.getNombreIdioma();
  return os;
}



