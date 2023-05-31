#ifndef DT_USUARIO_HPP
#define DT_USUARIO_HPP

#include <string>

using namespace std;

class DTUsuario {
public:
    DTUsuario(string nickname, string nombre, string descripcion);
    virtual ~DTUsuario();
    string getNickname();
    string getNombre();
    string getDescripcion();
private:
    string nickname, nombre, descripcion;
};

#endif
