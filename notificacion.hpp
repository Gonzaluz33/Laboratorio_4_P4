#include "dt_notificacion.hpp"
#include <string>

class Notificacion{
    private:
        string nombre_curso;
        string nombre_idioma;
    public:
        DTNotificacion getDataNotificacion();
        string getNombreCurso();
        string getNombreIdioma();
};
