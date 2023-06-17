#ifndef COMPLETARPALABRAS_HPP
#define COMPLETARPALABRAS_HPP
#include "ejercicio.hpp"

class CompletarPalabras : public Ejercicio{
    private:
        string frase;
        string palabras_faltantes;
    public:
        CompletarPalabras(string, TipoEjercicio,string,string);
        ~CompletarPalabras();
        string getFrase();
        string getPalabras_faltantes();
        void setFrase(string);
        void setPalabras_faltantes(string);
        bool estaAprobadoCP(string);
        DTEjercicio* getDataEjercicio();
};

#endif
