#include "dt_traduccion.hpp"

DTTraduccion::DTTraduccion(string descripcion, string frase, string traduccion):
    DTEjercicio(descripcion),
    frase(frase),
    traduccion(traduccion)
{
}

DTTraduccion::~DTTraduccion() {

}

string DTTraduccion::getFraseTraducir() {
    return frase;
}

string DTTraduccion::getTraduccionFrase() {
    return traduccion;
}
