#ifndef DT_ESTUDIANTE_HPP
#define DT_ESTUDIANTE_HPP

#include "dt_usuario.hpp"
#include <string>

class DTEstudiante : public DTUsuario {
public:
    DTEstudiante(string nickname, string nombre, string descripcion, string pais);
    ~DTEstudiante();
    string getPais();
private:
    string pais;
};

#endif
