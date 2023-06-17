#ifndef EJERCICIO_HPP
#define EJERCICIO_HPP

#include <string>
#include "dt_ejercicio.hpp"
#include "tipo_ejercicio.hpp"

using namespace std;

class Ejercicio{
    private:
        string descripcion;
        TipoEjercicio tipo;
    public:
        Ejercicio(string,TipoEjercicio);
        virtual ~Ejercicio();
        string getDescripcion();
        void setDescripcion(string);
        TipoEjercicio getTipo();
        void setTipo(TipoEjercicio);
        bool estaPendiente();
        virtual DTEjercicio* getDataEjercicio()=0;
        string strtolower(string entrada);
};

#endif
