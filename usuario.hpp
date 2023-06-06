#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include <map>
#include "IObserver.hpp"
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "idioma.hpp"
#include "notificacion.hpp"
#include "dt_fecha.hpp"
#include "dt_notificacion.hpp"
#include "IObserver.hpp"
#include "dt_usuario.hpp"

using namespace std;



class Usuario : public IObserver{
    private:
        string nickname;
        string contrasena;
        string nombre;
        string descripcion;
        TipoUsuario tipo;
        vector<Notificacion*> notificaciones;
        map<string,Idioma*> idiomasSuscritos;
    public: 
        Usuario(string,string,string,string,TipoUsuario);
        virtual ~Usuario();
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
        void notificar(string,string);
        void agregarIdioma(Idioma*);
        void eliminarIdioma(Idioma*);
        vector<DTIdioma> listarDTidiomasSuscritos();
        vector<DTNotificacion> getDTNotificaciones();
        void eliminarNotificaciones(string);
        DTUsuario getDataUsuario();
};

#endif
