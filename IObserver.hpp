#include "string"

class IObserver{
    public:
        virtual void notificar(string nombre_curso, string nombre_idioma) = 0; //se define en los observadores - va virtual??
        void eliminarNotificaciones(string nombre_curso);
};
