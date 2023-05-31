#include "dt_idioma.hpp"

DTIdioma::DTIdioma(string nombre):
    nombre(nombre)
{
}

DTIdioma::~DTIdioma() {

}

string DTIdioma::getNombre() {
    return nombre;
}
