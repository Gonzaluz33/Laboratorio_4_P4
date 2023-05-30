#include "controlador_usuarios.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

ControladorUsuarios * ControladorUsuarios::instancia = nullptr;
ControladorUsuarios* ControladorUsuarios::getInstance(){
        if(this->instancia == nullptr)
        this->instancia = new ControladorUsuarios();
        return this->instancia;
};
void ControladorUsuarios::iniciarAltaUsuario (string nickname ,string contraseña,string nombre,string descripción, TipoUsuario tipo){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nickname_recordado = nickname;
    cu->contrasena_recordado = contraseña;
    cu->nombre_recordado = nombre;
    cu->descripcion_recordado = descripción;
    cu->tipo_Usuario_recordado = tipo;
};
void ControladorUsuarios::datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nombre_Pais_recordado = nom_Pais;
    cu->fecha_Nacimiento_recordado = fecha_Nacimiento;
};
void ControladorUsuarios::datosAdicionalesProfesor(string nom_Instituto){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    cu->nombre_Instituto_recordado = nom_Instituto;
};

bool estaElIdioma(vector <DTIdioma*> idiomas, DTIdioma* idioma){//auxiliar
    bool esta_idioma = false;
    int i = 0;
    while(i < idiomas.size() && !esta_idioma){
        if(idiomas[i] == idioma)
        esta_idioma = true;
        i++;
    }
    return esta_idioma;
};

vector <DTIdioma*> ControladorUsuarios::listarIdiomas(){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    vector <DTIdioma*> idiomas_a_listar;
    vector <DTIdioma*>  idiomas_profesor;
    for(int i = 0; i < cu->Usuarios.size(); i++){
        if(cu->Usuarios[i]->tipo == Profesor){

         idiomas_profesor = cu->Usuarios[i]->getDTIdiomas();//devuelve un vector con punteros de DTIdioma

         for(int j = 0; j < idiomas_profesor.size();j++){

            if(!estaElIdioma(idiomas_a_listar,idiomas_profesor[j])){
            DTIdioma* agregar = new DTIdioma(idiomas_profesor[j]);
            idiomas_a_listar.push_back(agregar);
            }

         }

        }
    }
    return idiomas_a_listar;
};
void ControladorUsuarios::seleccionarIdioma(DTIdioma* Idioma){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    if(!estaElIdioma(cu->lista_idiomas_recordado,idioma)){
            DTIdioma* agregar = new DTIdioma(idioma);
            cu->lista_idiomas_recordado.push_back(agregar);
    }
};

bool ControladorUsuarios::altaUsuario(){
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
                nuevo_usuario = new Estudiante(cu->nickname_recordado, cu->contrasena_recordado,cu->nombre_recordado, cu->descripcion_recordado,cu->nombre_Pais_recordado,cu->fecha_Nacimiento_recordado,cu->tipo_Usuario_recordado);
            }
        }
        cu->Usuarios.push_back(nuevo_usuario);
    }
    cu->liberarMemoriaRecordada();
    return (!(ya_esta)); // retorna true si se agrego el usuario
 };

 void ControladorUsuarios::liberarMemoriaRecordada(){}; // por hacer

vector <string> ControladorUsuarios::listarEstudiantes(){
    vector <string> nicknames_a_listar;
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    for(int i = 0; i < cu->Usuarios.size(); i++){
        if(cu->Usuarios[i]->tipo == Estudiante){
           nicknames_a_listar.push_back(cu->Usuarios[i]->getNickname());
        }
    }
    return nicknames_a_listar;
 };

 vector <string> ControladorUsuarios::listarProfesores(){
     vector <string> nicknames_a_listar;
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    for(int i = 0; i < cu->Usuarios.size(); i++){
        if(cu->Usuarios[i]->tipo == Profesor){
           nicknames_a_listar.push_back(cu->Usuarios[i]->getNickname());
        }
    }
    return nicknames_a_listar;
 };

 vector <DTEstEstudiante*> ControladorUsuarios::listarEstEstudiante(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* est_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && est_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        est_seleccionado = cu->Usuarios[i];
        i++;
    }
    Estudiante* objetoDerivado = dynamic_cast<Estudiante*>(est_seleccionado);

    if(est_seleccionado != nullptr && objetoDerivado){
        return objetoDerivado->listarEstEstudiante();
    }else{
        return vector <DTEstEstudiante*> vacio;
    }
 };
 vector <DTEstProfesor*> ControladorUsuarios::listarEstProfesor(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* prof_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && prof_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        prof_seleccionado = cu->Usuarios[i];
        i++;
    }
    Profesor* objetoDerivado = dynamic_cast<Profesor*>(prof_seleccionado);

    if(prof_seleccionado != nullptr && objetoDerivado){
        return objetoDerivado->listarEstProfesor();
    }else{
        return vector <DTEstProfesor*> vacio;
    }
 };

vector <DTIdioma*> ControladorUsuarios::listaIdiomasProfesor(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* prof_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && prof_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        prof_seleccionado = cu->Usuarios[i];
        i++;
    }
    Profesor* objetoDerivado = dynamic_cast<Profesor*>(prof_seleccionado);
    if(prof_seleccionado != nullptr && objetoDerivado){
        return objetoDerivado->getDTIdiomas();
    }else{
        return vector <DTIdioma*> vacio;
    }
};

vector <DTCurso*> ControladorUsuarios::listarCursosNoAprobados(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* est_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && est_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        est_seleccionado = cu->Usuarios[i];
        i++;
    }
    Estudiante* objetoDerivado = dynamic_cast<Estudiante*>(est_seleccionado);
    vector <DTCurso*> cursos_a_listar;

    if(est_seleccionado != nullptr && objetoDerivado){
        vector<Inscripcion*> inscripciones_del_estuadiante = objetoDerivado->getInscripciones();
        for(int j = 0; j < inscripciones_del_estuadiante.size();j++){
            bool esta_aprobado = inscripciones_del_estuadiante[i]->getCursoAprobado();
            if(!esta_aprobado){
                cursos_a_listar.push_back(inscripciones_del_estuadiante[i]->getDataCurso());
            }
        }
    }
    return cursos_a_listar;

};

vector <DTNotificacion*> ControladorUsuarios::listarNotificaciones(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* usr_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && usr_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        usr_seleccionado = cu->Usuarios[i];
        i++;
    }
    if(usr_seleccionado != nullptr){
        return usr_seleccionado->getNotificaciones();
    }
    else 
        return vector <DTNotificacion*> vacio;
};

vector <DTIdioma*> ControladorUsuarios::listarIdiomasSuscritos(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* usr_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && usr_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        usr_seleccionado = cu->Usuarios[i];
        i++;
    }
    if(usr_seleccionado != nullptr){
        return usr_seleccionado->listarDTIdiomasSuscritos();
    }
    else 
        return vector <DTIdioma*> vacio;

};

Usuario* ControladorUsuarios::buscarUsuario(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* usr_seleccionado = nullptr;
    int i = 0;
    while(i < cu->Usuarios.size() && usr_seleccionado == nullptr){
        if(cu->Usuarios[i]->getNickname() == nickname)
        usr_seleccionado = cu->Usuarios[i];
        i++;
    }
    return usr_seleccionado;
}

static void quitarIdioma(vector <DTIdioma*> idiomas, DTIdioma* idioma){
    for(it = idiomas.begin(); it != idiomas.end(); ++it){
        if(*it == idioma){
            DTIdioma* borrar = *it;
            delete borrar;
            idiomas.erase(it);
        }
    }   
}

vector <DTIdioma*> ControladorUsuarios::listarIdiomasNoSuscritos(string nickname){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    vector<DTIdioma*> idiomas_suscritos = cu->listarIdiomasSuscritos(nickname);
    vector<DTIdioma*> idiomas_todos = cu->listarIdiomas();
    vector<DTIdioma*>::iterator it;
    for(it = idiomas_suscritos.begin(); it != idiomas_suscritos.end(); ++it){
        quitarIdioma(idiomas_todos,*it);
    }
    cu->nickname_listarIdiomasNoSuscritos_recordado = nickname;
    return idiomas_todos;
};

void suscribir(vector <Idioma*> idiomasASuscribir){
    ControladorUsuarios* cu ControladorUsuarios::getInstance();
    Usuario* user = cu->buscarUsuario(cu->nickname_listarIdiomasNoSuscritos_recordado);
    vector<Idioma*>::iterator it;
    for(it = idiomasASuscribir.begin(); it != idiomasASuscribir.end(); ++it){
       user->agregarIdioma(*it);
       Idioma* asignar = *it;
       asignar->agregarObservador(user);
    }
};
