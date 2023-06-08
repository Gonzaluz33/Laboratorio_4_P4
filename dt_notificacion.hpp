#ifndef DT_NOTIFICACION_HPP
#define DT_NOTIFICACION_HPP

#include <string>

using namespace std;

class DTNotificacion{
    private:
        string nombre_curso;
        string nombre_idioma;
    public:
        DTNotificacion(string nombre_curso, string nombre_idioma);
        ~DTNotificacion();
        string getNombreCurso();
        string getNombreIdioma();
        friend ostream& operator<<(ostream& os, DTNotificacion notificacion);
};

#endif
