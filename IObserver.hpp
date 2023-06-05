#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP 

#include <string>

using namespace std;

class IObserver{
    public:
        virtual void notificar(string nombre_curso, string nombre_idioma) = 0; //se define en los observadores 
        virtual void eliminarNotificaciones(string nombre_curso) = 0;
};

#endif
