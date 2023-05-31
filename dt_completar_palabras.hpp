#ifndef DT_COMPLETAR_PALABRAS_HPP
#define DT_COMPLETAR_PALABRAS_HPP

#include <string>
#include "dt_ejercicio.hpp"

using namespace std;

class DTCompletarPalabras : public DTEjercicio {
public:
    DTCompletarPalabras(string descripcion, string frase, string palabrasFaltantes);
    ~DTCompletarPalabras();
    string getFrase();
    string getPalabrasFaltantes();
private:
    string frase, palabrasFaltantes;
};

#endif
