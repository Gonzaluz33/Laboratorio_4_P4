#include "controlador_usuarios.hpp"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

ControladorUsuarios * ControladorUsuarios::instancia = nullptr;
ControladorUsuarios* ControladorUsuarios::getInstance(){
        if(this->instancia == nullptr)
        this->instancia = new ControladorUsuarios();
        return this->instancia;
};
void iniciarAltaUsuario (string nickname ,string contraseña,string nombre,string descripción, TipoUsuario tipo){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nickname_recordado = nickname;
    cu->contrasena_recordado = contraseña;
    cu->nombre_recordado = nombre;
    cu->descripcion_recordado = descripción;
    cu->tipo_Usuario_recordado = tipo;
};
void datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nomre_Pais_recordado = nom_Pais;
    cu->fecha_Nacimiento_recordado = fecha_Nacimiento;
};
void datosAdicionalesProfesor(string nom_Instituto){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nombre_Instituto_recordado = nom_Instituto;
};
set <string> listarIdiomas(){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    set <string> idiomas_a_listar;
    vector <DTIdioma*>  idiomas_profesor;
    for(int i = 0; i < cu->Usuarios.size(); i++){
        if(cu->Usuarios[i]->tipo == Profesor){
         idiomas_profesor = cu->Usuarios[i]->getDTIdiomas();
         for(int j = 0; j < idiomas_profesor.size();j++){
            DTIdioma data_idioma = idiomas_profesor[j]->getDataIdioma();
            idiomas_a_listar.insert(data_idioma->getNombre());
         }
        }
    }
    return idiomas_a_listar;
};
void seleccionarIdioma(string nom_Idioma){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->lista_idiomas_recordado.insert(nom_Idioma);
};

 bool altaUsuario(){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    bool ya_esta = false;
    for(int i = 0; i < cu->Usuarios.size();i++){
        ya_esta = (cu->Usuarios[i]->nickname == cu->nickname_recordado);
    }
    if(!(ya_esta)){
        Usuario* nuevo_usuario;
        if(cu->tipo_Usuario_recordado == Profesor){
            nuevo_usuario = new Profesor(cu->lista_idiomas_recordado,cu->nickname_recordado, cu->contrasena_recordado, cu->nombre_recordado, cu->descripcion_recordado,cu->nombre_Instituto_recordado, cu->tipo_Usuario_recordado);

        }else{
            if(cu->tipo_Usuario_recordado == Estudiante){
                nuevo_usuario = new Estudiante(cu->nickname_recordado, cu->contrasena_recordado,cu->nombre_recordado, cu->descripcion_recordado,cu->nomre_Pais_recordado,cu->fecha_Nacimiento_recordado);
            }
        }
        cu->Usuarios.push_back(nuevo_usuario);
    }
    cu->liberarMemoriaRecordada();
    return (!(ya_esta)); // retorna true si se agrego el usuario
 };
 void liberarMemoriaRecordada(){}; // por hacer

vector <string> listarEstudiantes(){
    vector <string> nicknames_a_listar;
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    for(int i = 0; i < cu->Usuarios.size(); i++){
        if(cu->Usuarios[i]->tipo == Estudiante){
           nicknames_a_listar.push_back(cu->Usuarios[i]->getNickname());
        }
    }
    return nicknames_a_listar;
 };