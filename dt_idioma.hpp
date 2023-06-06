#ifndef DT_IDIOMA_HPP
#define DT_IDIOMA_HPP

#include <string>

using namespace std;

class DTIdioma {
public:
    DTIdioma(string nombre);
    ~DTIdioma();
    string getNombre();
    bool operator==(const DTIdioma& other) const {
        return nombre == other.nombre;
    }
private:

    string nombre;
};

#endif
