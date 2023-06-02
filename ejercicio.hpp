#include <string>
#include "dt_ejercicio"
#include "tipo_ejercicio.hpp"

using namespace std;

class Ejercicio{
    private:
        string descripcion;
        tipoEjercicio tipo;
    public:
        Ejercicio(string,tipoEjercicio);
        virtual ~Ejercicio();
        string getDescripcion();
        void setDescripcion(string);
        tipoEjercicio getTipo();
        void setTipo(TipoEjercicio);
        bool estaPendiente();
        DTEjercicio getDataEjercicio();
};
