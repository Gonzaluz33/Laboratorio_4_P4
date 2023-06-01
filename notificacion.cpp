#include "notificacion.hpp"

DTNotificacion Notificacion::getDataNotificacion(){
    DTNotificacion dtNot = DTNotificacion(this->nombre_curso, this->nombre_idioma);
    return dtNot;
}