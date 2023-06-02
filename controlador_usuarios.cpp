#include "controlador_usuarios.hpp"
#include "dt_idioma.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Usuario;
class Profesor;

ControladorUsuarios *ControladorUsuarios::instancia = nullptr;
ControladorUsuarios *ControladorUsuarios::getInstance()
{
    if (this->instancia == nullptr)
        this->instancia = new ControladorUsuarios();
    return this->instancia;
};
void ControladorUsuarios::iniciarAltaUsuario(string nickname, string contraseña, string nombre, string descripción, TipoUsuario tipo)
{
    this->nickname_recordado = nickname;
    this->contrasena_recordado = contraseña;
    this->nombre_recordado = nombre;
    this->descripcion_recordado = descripción;
    this->tipo_Usuario_recordado = tipo;
};
void ControladorUsuarios::datosAdicionalesEstudiante(string nom_Pais, DTFecha fecha_Nacimiento)
{
    this->nombre_Pais_recordado = nom_Pais;
    this->fecha_Nacimiento_recordado = fecha_Nacimiento;
};
void ControladorUsuarios::datosAdicionalesProfesor(string nom_Instituto)
{
    this->nombre_Instituto_recordado = nom_Instituto;
};

vector<DTIdioma> ControladorUsuarios::listarIdiomas()
{
    vector<DTIdioma> a_listar;
    map<string, Idioma *>::iterator it;
    for (it = this->Idiomas.begin(); it != this->Idiomas.end(); ++it)
    {
        DTIdioma dataIdioma = *it->getDataIdioma();
        string nombre = dataIdioma->getNombre();
        Idiomas.insert(nombre, dataIdioma);
    }
    return a_listar;
};

void ControladorUsuarios::seleccionarIdioma(DTIdioma idioma)
{
    bool esta_el_idioma = false;
    vector<DTIdioma>::iterator it;
    for (it = this->lista_idiomas_recordado.begin(); it != this->lista_idiomas_recordado.end(); ++it)
    {
        if (*it->getNombre() == idioma->getNombre())
            esta_el_idioma = true;
    }
    if (!esta_el_idioma)
    {
        this->lista_idiomas_recordado.push_back(idioma);
    }
};

bool ControladorUsuarios::altaUsuario()
{
    bool ya_esta_usuario = false;
    string nick = this->nickname_recordado;
    map<string, Usuario *>::iterator it;
    it = this->Usuarios.find(nick);
    bool ya_esta_usuario = this->Usuarios.end() != it;
    if (!(ya_esta_usuario))
    {
        Usuario *nuevo_usuario;
        if (this->tipo_Usuario_recordado == Profesor)
        {
            nuevo_usuario = new Profesor(this->lista_idiomas_recordado, this->nickname_recordado, this->contrasena_recordado, this->nombre_recordado, this->descripcion_recordado, this->nombre_Instituto_recordado, this->tipo_Usuario_recordado);
        }
        else
        {
            if (this->tipo_Usuario_recordado == Estudiante)
            {
                nuevo_usuario = new Estudiante(this->nickname_recordado, this->contrasena_recordado, this->nombre_recordado, this->descripcion_recordado, this->nombre_Pais_recordado, this->fecha_Nacimiento_recordado, this->tipo_Usuario_recordado);
            }
        }
        this->Usuarios.insert(this->nickname_recordado, nuevo_usuario);
    }
    this->liberarMemoriaRecordada();
    return (!(ya_esta_usuario)); // retorna true si se agrego el usuario
};

void ControladorUsuarios::liberarMemoriaRecordada(){}; // por hacer

vector<string> ControladorUsuarios::listarEstudiantes(){
    vector<string> nicknames_a_listar;
    map<string, Usuario *>::iterator it;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if (*it->getTipo() == Estudiante)
            nicknames_a_listar.push_back(*it->getNombre());
    }
    return nicknames_a_listar;
};

vector<string> ControladorUsuarios::listarProfesores(){
    vector<string> nicknames_a_listar;
    map<string, Usuario *>::iterator it;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if (*it->getTipo() == Profesor)
            nicknames_a_listar.push_back(*it->getNombre());
    }
    return nicknames_a_listar;
};

vector<DTEstEstudiante> ControladorUsuarios::listarEstEstudiante(string nickname){
    vector<DTEstEstudiante> estadisticas;
    map<string,Usuario*>::iterator it;
    it = this->Usuarios.find(nombre);
    bool esta = this->Usuarios.end() != it;
    if(esta)
    Estudiante* objetoDerivado = dynamic_cast<Estudiante*>(*it);
    if(objetoDerivado)
    estadisticas = objetoDerivado->listarEstEstudiante();
    return estadisticas;
};

vector<DTEstProfesor> ControladorUsuarios::listarEstProfesor(string nickname){
    vector<DTEstProfesor> estadisticas;
    Usuario* prof;
    map<string,Usuario*>::iterator it;
    it = this->Usuarios.find(nombre);
    bool esta = this->Usuarios.end() != it;
    if(esta)
    Profesor* objetoDerivado = dynamic_cast<Profesor*>(*it);
    if(objetoDerivado)
    estadisticas = objetoDerivado->listarEstProfesor();
    return estadisticas;
};

vector<DTIdioma> ControladorUsuarios::listaIdiomasProfesor(string nickname){
    vector<DTIdioma> listar;
    map<string,Usuario*>::iterator it;
    it = this->Usuarios.find(nombre);
    bool esta = this->Usuarios.end() != it;
    if(esta)
    Profesor* objetoDerivado = dynamic_cast<Profesor*>(*it);
    if(objetoDerivado)
    listar = objetoDerivado->getDTIdiomas();
    return listar;
};

vector<DTCurso *> ControladorUsuarios::listarCursosNoAprobados(string nickname)
{

    Usuario *est_seleccionado = nullptr;
    int i = 0;
    while (i < this->Usuarios.size() && est_seleccionado == nullptr)
    {
        if (this->Usuarios[i]->getNickname() == nickname)
            est_seleccionado = this->Usuarios[i];
        i++;
    }
    Estudiante *objetoDerivado = dynamic_cast<Estudiante *>(est_seleccionado);
    vector<DTCurso *> cursos_a_listar;

    if (est_seleccionado != nullptr && objetoDerivado)
    {
        vector<Inscripcion *> inscripciones_del_estuadiante = objetoDerivado->getInscripciones();
        for (int j = 0; j < inscripciones_del_estuadiante.size(); j++)
        {
            bool esta_aprobado = inscripciones_del_estuadiante[i]->getCursoAprobado();
            if (!esta_aprobado)
            {
                cursos_a_listar.push_back(inscripciones_del_estuadiante[i]->getDataCurso());
            }
        }
    }
    return cursos_a_listar;
};

vector<DTNotificacion *> ControladorUsuarios::listarNotificaciones(string nickname)
{
    Usuario *usr_seleccionado = nullptr;
    int i = 0;
    while (i < this->Usuarios.size() && usr_seleccionado == nullptr)
    {
        if (this->Usuarios[i]->getNickname() == nickname)
            usr_seleccionado = this->Usuarios[i];
        i++;
    }
    if (usr_seleccionado != nullptr)
    {
        return usr_seleccionado->getNotificaciones();
    }
    else
        return vector<DTNotificacion *> vacio;
};

vector<DTIdioma *> ControladorUsuarios::listarIdiomasSuscritos(string nickname)
{
    Usuario *usr_seleccionado = nullptr;
    int i = 0;
    while (i < this->Usuarios.size() && usr_seleccionado == nullptr)
    {
        if (this->Usuarios[i]->getNickname() == nickname)
            usr_seleccionado = this->Usuarios[i];
        i++;
    }
    if (usr_seleccionado != nullptr)
    {
        return usr_seleccionado->listarDTIdiomasSuscritos();
    }
    else
        return vector<DTIdioma *> vacio;
};

Usuario *ControladorUsuarios::buscarUsuario(string nickname)
{

    Usuario *usr_seleccionado = nullptr;
    int i = 0;
    while (i < this->Usuarios.size() && usr_seleccionado == nullptr)
    {
        if (this->Usuarios[i]->getNickname() == nickname)
            usr_seleccionado = this->Usuarios[i];
        i++;
    }
    return usr_seleccionado;
}

static void quitarIdioma(vector<DTIdioma *> idiomas, DTIdioma *idioma)
{
    for (it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        if (*it == idioma)
        {
            DTIdioma *borrar = *it;
            delete borrar;
            idiomas.erase(it);
        }
    }
}

vector<DTIdioma *> ControladorUsuarios::listarIdiomasNoSuscritos(string nickname)
{

    vector<DTIdioma *> idiomas_suscritos = this->listarIdiomasSuscritos(nickname);
    vector<DTIdioma *> idiomas_todos = this->listarIdiomas();
    vector<DTIdioma *>::iterator it;
    for (it = idiomas_suscritos.begin(); it != idiomas_suscritos.end(); ++it)
    {
        quitarIdioma(idiomas_todos, *it);
    }
    this->nickname_listarIdiomasNoSuscritos_recordado = nickname;
    return idiomas_todos;
};

void ControladorUsuarios::suscribir(vector<Idioma *> idiomasASuscribir)
{
    Usuario *user = this->buscarUsuario(this->nickname_listarIdiomasNoSuscritos_recordado);
    vector<Idioma *>::iterator it;
    for (it = idiomasASuscribir.begin(); it != idiomasASuscribir.end(); ++it)
    {
        user->agregarIdioma(*it);
        Idioma *asignar = *it;
        asignar->agregarObservador(user);
    }
};

bool ControladorUsuarios::iniciarAltaIdioma(DTIdioma idioma)
{
    string nombre = idioma->getNombre();
    map<string, DTIdioma>::iterator it;
    it = this->Idiomas.find(nombre);
    bool esta = this->Idiomas.end() != it;
    if (!esta)
        this->Idiomas.insert(nombre, idioma);
    return esta;
}
