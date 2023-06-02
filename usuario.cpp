#include <string>
#include <iostream>
#include <vector>
#include "usuario.hpp"

using namespace std;

usuario::usuario(string nick, string contr, string nom, string desc, TipoUsuario tu){
    this->nickname=nick;
    this->contrasena=contr;
    this->nombre=nom;
    this->descripcion=desc;
    this->tipo=tu;
}

usuario::~usuario(){

}

string usuario::getNickname(){
    return this->nickname;
}

string usuario::getContrasena(){
    return this->contrasena;
}

string usuario::getNombre(){
    return this->nombre;
}

string usuario::getDescripcion(){
    return this->descripcion;
}

TipoUsuario usuario::getTipo(){
    return this->tipo;
}

void usuario::setNickname(string nick){
    this->nickname=nick;
}

void usuario::setContrasena(string contr){
    this->contrasena=contr;
}

void usuario::setNombre(string nom){
    this->nombre=nom;
}

void usuario::setDescricpion(string desc){
    this->descripcion=desc;
}

void usuario::setTipo(TipoUsuario tu){
    this->tipo = tu;
}

void usuario::agregaridioma(idioma i){
    idioma *id = new idioma;
    this->idiomasSuscritos.insert(pair<string,idioma*>(i.getNombre(),id));
}

void usuario::eliminaridioma(idioma id){
    if(this->idiomasSuscritos.count(id.getNombre())){
        this->idiomasSuscritos.erase(id.getNombre());
    }
}

vector<DTIdioma> usuario::listarDTidiomasSuscritos(){
    vector<DTIdioma> id_sus;
    map<string,idioma*>::iterator it;
    it = this->idiomasSuscritos.begin();
    while(it <= this->idiomasSuscritos.end()){
        idioma *current = *it;
        id_sus.insert(id_sus.begin(),current->getDataIdioma());
        it++;
    }
    return id_sus;
}

vector<DTNotificacion> usuario::getDTNotificaciones(){
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

void usuario::eliminarNotificaciones(string nombre_curso){
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
