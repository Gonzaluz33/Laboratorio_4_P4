#ifndef IDIOMA_HPP
#define IDIOMA_HPP

#include "string"
#include "dt_idioma.hpp"
#include "IObserver.hpp"
#include <vector>
#include <set>

class Idioma {
    private:
        string nombre;
        set<IObserver *> observadores;
    public:
        Idioma(string nombre);
        virtual ~Idioma();
        string getNombre();
        DTIdioma getDataIdioma();
        void agregarObservador(IObserver *o); 
        void eliminarObservador(IObserver *o);
        vector <DTIdioma> compararIdioma(vector <DTIdioma>iS); 
        void notificarCambio(string nombre_curso);
};

#endif
