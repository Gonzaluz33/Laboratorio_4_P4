#include "dt_estudiante.hpp"

DTEstudiante::DTEstudiante(string nickname, string nombre, string descripcion, string pais):
    DTUsuario(nickname, nombre, descripcion),
    pais(pais)
{
}

DTEstudiante::~DTEstudiante() {

}

string DTEstudiante::getPais() {
    return pais;
}
