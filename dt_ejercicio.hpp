#ifndef DT_EJERCICIO_HPP
#define DT_EJERCICIO_HPP

#include <string>

using namespace std;

class DTEjercicio {
public:
    DTEjercicio(string descripcion);
    virtual ~DTEjercicio(){};
    string getDescripcion();
private:
    string descripcion;
};

#endif
