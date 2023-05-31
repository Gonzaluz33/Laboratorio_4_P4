#include "dt_profesor.hpp"

DTProfesor::DTProfesor(string nickname, string nombre, string descripcion,
                       string instituto, vector<DTIdioma> idiomas):
    DTUsuario(nickname, nombre, descripcion),
    instituto(instituto),
    idiomas(idiomas)
{
}

// no se si hay que destruir los elementos de el vector idiomas
DTProfesor::~DTProfesor() {

}

string DTProfesor::getInstituto() {
    return instituto;
}


vector<DTIdioma> DTProfesor::getIdiomas() {
    return idiomas;
}
