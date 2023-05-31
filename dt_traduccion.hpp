#ifndef DT_TRADUCCION_HPP
#define DT_TRADUCCION_HPP

#include <string>
#include "dt_ejercicio.hpp"

using namespace std;

class DTTraduccion : public DTEjercicio {
public:
    DTTraduccion(string descripcion, string frase, string traduccion);
    ~DTTraduccion();
    string getFraseTraducir();
    string getTraduccionFrase();
private:
    string frase, traduccion;
};

#endif
