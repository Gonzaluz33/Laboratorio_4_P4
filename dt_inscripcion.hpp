#ifndef DT_INSCRIPCION_HPP
#define DT_INSCRIPCION_HPP

#include <string>
#include "dt_fecha.hpp"

using namespace std;

class DTInscripcion {
public:
    DTInscripcion(string nombreEstudiante, DTFecha fechaInscripcion);
    ~DTInscripcion();
    string getNombreEstudiante();
    DTFecha getFechaInscripcion();
private:
    string nombreEstudiante;
    DTFecha fechaInscripcion;
};

#endif
