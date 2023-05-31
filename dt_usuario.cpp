#include "dt_usuario.hpp"

DTUsuario::DTUsuario(string nickname, string nombre, string descripcion):
    nickname(nickname),
    nombre(nombre),
    descripcion(descripcion)
{
}

DTUsuario::~DTUsuario() {

}

string DTUsuario::getNickname() {
    return nickname;
}

string DTUsuario::getNombre() {
    return nombre;
}

string DTUsuario::getDescripcion() {
    return descripcion;
}
