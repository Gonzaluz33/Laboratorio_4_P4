#ifndef completarPalabras
#define completarPalabras
#include "ejercicio.hpp"

class CompletarPalabras : public ejercicio{
    private:
        string frase;
        string Palabras_faltantes;
    public:
        CompletarPalabras(string,tipoEjercicio,string,string);
        ~CompletarPalabras();
        string getFrase();
        string getPalabras_faltantes();
        void setFrase(string);
        void setPalabras_faltantes(string);
        bool estaAprobadoCP(string);
};
