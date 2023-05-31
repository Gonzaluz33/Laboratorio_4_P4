#include <string>
#include "dt_ejercicio"
#include "tipo_ejercicio.hpp"

using namespace std;

class ejercicio{
    private:
        string descripcion;
        tipoEjercicio tipo;
    public:
        ejercicio(string,tipoEjercicio);
        virtual ~ejercicio();
        string getDescripcion();
        void setDescripcion(string);
        tipoEjercicio getTipo();
        void setTipo(tipoEjercicio);
        bool estaPendiente();
        DTEjercicio getDataEjercicio();
};
