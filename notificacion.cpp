#include "notificacion.hpp"

Notificacion::Notificacion(string nombre_curso, string nombre_idioma):
    nombre_curso(nombre_curso),
    nombre_idioma(nombre_idioma)
{
}

Notificacion::~Notificacion() {

}

DTNotificacion Notificacion::getDataNotificacion(){
    DTNotificacion dtNot = DTNotificacion(this->nombre_curso, this->nombre_idioma);
    return dtNot;
}

string Notificacion::getNombreCurso() {
    return nombre_curso;
}

string Notificacion::getNombreIdioma() {
    return nombre_idioma;
}
