#include <string>
#include <iostream>
#include <vector>
#include "usuario.hpp"

using namespace std;

Usuario::Usuario(string nick, string contr, string nom, string desc, TipoUsuario tu){
    this->nickname=nick;
    this->contrasena=contr;
    this->nombre=nom;
    this->descripcion=desc;
    this->tipo=tu;
}

Usuario::~Usuario(){

}

string Usuario::getNickname(){
    return this->nickname;
}

string Usuario::getContrasena(){
    return this->contrasena;
}

string Usuario::getNombre(){
    return this->nombre;
}

string Usuario::getDescripcion(){
    return this->descripcion;
}

TipoUsuario Usuario::getTipo(){
    return this->tipo;
}

void Usuario::setNickname(string nick){
    this->nickname=nick;
}

void Usuario::setContrasena(string contr){
    this->contrasena=contr;
}

void Usuario::setNombre(string nom){
    this->nombre=nom;
}

void Usuario::setDescricpion(string desc){
    this->descripcion=desc;
}

void Usuario::setTipo(TipoUsuario tu){
    this->tipo = tu;
}

void Usuario::agregaridioma(Idioma i){
    Idioma *id = new Idioma;
    this->idiomasSuscritos.insert(pair<string,idioma*>(i.getNombre(),id));
}

void Usuario::eliminaridioma(Idioma id){
    if(this->idiomasSuscritos.count(id.getNombre())){
        this->idiomasSuscritos.erase(id.getNombre());
    }
}

vector<DTIdioma> Usuario::listarDTidiomasSuscritos(){
    vector<DTIdioma> id_sus;
    map<string,Idioma*>::iterator it;
    it = this->idiomasSuscritos.begin();
    while(it <= this->idiomasSuscritos.end()){
        Idioma *current = *it;
        id_sus.insert(id_sus.begin(),current->getDataIdioma());
        it++;
    }
    return id_sus;
}

vector<DTNotificacion> Usuario::getDTNotificaciones(){
    vector<DTNotificacion> n;
    vector<Notificacion*>::iterator it;
    it = this->notificaciones.begin();
    while(it <= this->notificaciones.end()){
        Notificacion *current = *it;
        n.insert(n.begin(),current->getDataNotificacion());
        it++;
    }
    return n;
}

void Usuario::eliminarNotificaciones(string nombre_curso){
    vector<Notificacion*>::iterator it;
    it = this->notificaciones.begin();
    int j = 0;
    while((j == 0) || (it < this->idiomasSuscritos.end())){
        Notificacion *current = *it;
        if(current->getNombreCurso() == nombre_curso){
            j = 1;
        }
        it++;
    }
    if(j == 1){
        this->notificaciones.erase(it);
    }
}

void Usuario::notificar(string nombreCurso, string nombreIdioma){
    Notificacion n = Notificacion(nombreCurso,nombreIdioma);
    this->notificaciones.insert(this->notificaciones.begin(),n);
}
