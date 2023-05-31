#include <string>
#include "ejercicio.hpp"

class traduccion : public ejercicio{
    private:
        string frase_a_traducir;
        string traduccion_frase;
    public:
        traduccion(string,tipoEjercicio,string,string);
        ~traduccion();
        void setFrase_a_traducir(string);
        string getFrase_a_traducir();
        void setTraduccion_frase(string);
        string getTraduccion_frase();
        bool estaAprobadoT(string);
};