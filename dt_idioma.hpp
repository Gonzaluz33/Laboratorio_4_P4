#ifndef DT_IDIOMA_HPP
#define DT_IDIOMA_HPP

#include <string>

using namespace std;

class DTIdioma {
public:
    DTIdioma();
    DTIdioma(string nombre);
    ~DTIdioma();
    DTIdioma(const DTIdioma& other) : nombre(other.nombre) {};
    string getNombre(){
            return this->nombre;
        };
    bool operator==(const DTIdioma& other) const {
        return nombre == other.nombre;
    }
private:

    string nombre;
};

#endif
