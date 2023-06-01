#include "string"
#include "dt_idioma.hpp"
#include "IObserver.hpp"
#include <vector>
#include <set>

class Idioma {
    private:
        string nombre;
        set<INotificador *> observadores;
        void notificarCambio(string nombre_curso);
    public:
        Idioma(string nombre);
        virtual ~Idioma();
        string getNombre();
        DTIdioma getDataIdioma();
        void agregarObservador(IObserver *o); 
        void eliminarObservador(IObserver *o);
        vector <DTIdioma> compararIdioma(vector <DTIdioma>iS); 
};
