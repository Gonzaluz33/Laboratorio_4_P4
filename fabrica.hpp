#ifndef FABRICA_HPP
#define FABRICA_HPP

#include "icontrolador_cursos.hpp"
#include "icontrolador_usuarios.hpp"

class Fabrica {
public:
    Fabrica();
    ~Fabrica();
    IControladorCursos *getIControladorCursos();
    IControladorUsuarios *getIControladorUsuarios();
private:
    IControladorCursos *controladorCursos;
    IControladorUsuarios *controladorUsuarios;
};

#endif
