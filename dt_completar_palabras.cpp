#include "dt_completar_palabras.hpp"

DTCompletarPalabras::DTCompletarPalabras(string descripcion, string frase, string palabrasFaltantes):
    DTEjercicio(descripcion),
    frase(frase),
    palabrasFaltantes(palabrasFaltantes)
{
}

DTCompletarPalabras::~DTCompletarPalabras() {

}

string DTCompletarPalabras::getFrase() {
    return frase;
}

string DTCompletarPalabras::getPalabrasFaltantes() {
    return palabrasFaltantes;
}
