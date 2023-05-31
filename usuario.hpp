#include <string>
#include <vector>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"

class Notificacion{};
class idioma{};
class DTFecha{};
class DTNotificacion{};

using namespace std;



class usuario{
    private:
        string nickname;
        string contrasena;
        string nombre;
        string descripcion;
        TipoUsuario tipo;
        vector<Notificacion*> notificaciones;
        vector<idioma*> idiomasSuscritos;
    public: 
        usuario(string,string,string,string,TipoUsuario);
        virtual ~usuario();
        string getNickname();
        void setNickname(string);
        string getContrasena();
        void setContrasena(string);
        string getNombre();
        void setNombre(string);
        string getDescripcion();
        void setDescricpion(string);
        TipoUsuario getTipo();
        void setTipo(TipoUsuario);
        virtual notificar(string,string);
        void agregaridioma(idioma);
        void eliminaridioma(idioma);
        vector<DTIdioma> listarDTidiomasSuscritos();
        vector<DTNotificacion> getDTNotificaciones();
        void eliminarNotificaciones(string);
};
