#ifndef TRADUCCION_HPP
#define TRADUCCION_HPP

#include <string>
#include "ejercicio.hpp"

class Traduccion : public Ejercicio{
    private:
        string frase_a_traducir;
        string traduccion_frase;
    public:
        Traduccion(string,TipoEjercicio,string,string);
        ~Traduccion();
        void setFrase_a_traducir(string);
        string getFrase_a_traducir();
        void setTraduccion_frase(string);
        string getTraduccion_frase();
        bool estaAprobadoT(string);
        DTEjercicio *getDataEjercicio();
};

#endif
