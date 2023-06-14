#ifndef DT_ESTUDIANTE_HPP
#define DT_ESTUDIANTE_HPP
#include "dt_usuario.hpp"
#include "dt_fecha.hpp"
#include <string>

class DTEstudiante : public DTUsuario {
public:
    DTEstudiante(string nickname, string nombre, string descripcion, string pais,DTFecha fecha);
    ~DTEstudiante();
    string getPais();
    DTFecha getDTFecha();
private:
    string pais;
    DTFecha fecha;
};

#endif
