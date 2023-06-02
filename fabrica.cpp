#include "fabrica.hpp"
#include "controlador_cursos.hpp"
#include "controlador_usuarios.hpp"

Fabrica::Fabrica() {
    controladorCursos = new ControladorCursos();
    controladorUsuarios = ControladorUsuarios::getInstance();
}
