#include "dt_estudiante.hpp"

DTEstudiante::DTEstudiante(string nickname, string nombre, string descripcion, string pais,DTFecha fecha):
    DTUsuario(nickname, nombre, descripcion),
    pais(pais),
    fecha(fecha)
{
}

DTEstudiante::~DTEstudiante() {

}

string DTEstudiante::getPais() {
    return pais;
}
DTFecha DTEstudiante::getDTFecha(){
    return this->fecha;
}
