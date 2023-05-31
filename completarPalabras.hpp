#include "ejercicio.hpp"

class completarPalabras : public ejercicio{
    private:
        string frase;
        string Palabras_faltantes;
    public:
        completarPalabras(string,tipoEjercicio,string,string);
        ~completarPalabras();
        string getFrase();
        string getPalabras_faltantes();
        void setFrase(string);
        void setPalabras_faltantes(string);
        bool estaAprobadoCP(string);
};