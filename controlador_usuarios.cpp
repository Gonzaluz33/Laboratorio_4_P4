#include "controlador_usuarios.hpp"
#include "idioma.hpp"
#include "profesor.hpp"
#include "usuario.hpp"
#include "estudiante.hpp"
#include "inscripcion.hpp"
#include "dt_idioma.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

ControladorUsuarios *ControladorUsuarios::instancia = nullptr;

ControladorUsuarios::ControladorUsuarios():
    fecha_Nacimiento_recordado(0, 0, 0)
{
}

ControladorUsuarios::~ControladorUsuarios() {
    //liberarMemoriaRecordada();
    map<string, Usuario*>::iterator it_u;
    for (it_u = usuarios.begin(); it_u != usuarios.end(); it_u++) {
        delete it_u->second;
    }
    usuarios.clear();
    map<string, Idioma*>::iterator it_i;
    for (it_i = idiomas.begin(); it_i != idiomas.end(); it_i++) {
        delete it_i->second;
    }
    idiomas.clear();
}

ControladorUsuarios *ControladorUsuarios::getInstance()
{
    if (ControladorUsuarios::instancia == nullptr)
        ControladorUsuarios::instancia = new ControladorUsuarios();
    return ControladorUsuarios::instancia;
}

void ControladorUsuarios::iniciarAltaUsuario(string nickname, string contrasenia, string nombre, string descripcion, TipoUsuario tipo)
{
    this->nickname_recordado = nickname;
    this->contrasena_recordado = contrasenia;
    this->nombre_recordado = nombre;
    this->descripcion_recordado = descripcion;
    this->tipo_Usuario_recordado = tipo;
}

void ControladorUsuarios::datosAdicionalesEstudiante(string nom_Pais, DTFecha fecha_Nacimiento)
{
    this->nombre_Pais_recordado = nom_Pais;
    this->fecha_Nacimiento_recordado = fecha_Nacimiento;
}

void ControladorUsuarios::datosAdicionalesProfesor(string nom_Instituto)
{
    this->nombre_Instituto_recordado = nom_Instituto;
}

vector<DTIdioma> ControladorUsuarios::listarIdiomas()
{
    vector<DTIdioma> a_listar;
    map<string,Idioma*>::iterator it;
    for (it = this->idiomas.begin(); it != this->idiomas.end(); ++it)
    {   Idioma* id = it->second;
        DTIdioma dataIdioma = id->getDataIdioma();
        a_listar.push_back(dataIdioma);
    }
    return a_listar;
}

void ControladorUsuarios::seleccionarIdioma(DTIdioma idioma)
{
    bool esta_el_idioma = false;
    vector<DTIdioma>::iterator it;
    for (it = this->lista_idiomas_recordado.begin(); it != this->lista_idiomas_recordado.end(); ++it)
    {
        if (it->getNombre() == idioma.getNombre())
            esta_el_idioma = true;
    }
    if (!esta_el_idioma)
    {
        this->lista_idiomas_recordado.push_back(idioma);
    }
}

bool ControladorUsuarios::altaUsuario()
{
    bool ya_esta_usuario = false;
    string nick = this->nickname_recordado;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nick);
    ya_esta_usuario = this->usuarios.end() != it;
    if (!(ya_esta_usuario))
    {
        Usuario* nuevo_usuario;
        if (this->tipo_Usuario_recordado == Prof)
        {
            nuevo_usuario = new Profesor(this->nickname_recordado, this->contrasena_recordado, this->nombre_recordado, this->descripcion_recordado, this->tipo_Usuario_recordado, this->nombre_Instituto_recordado, this->lista_idiomas_recordado);
        }
        else
        {
            if (this->tipo_Usuario_recordado == Est)
            {
                nuevo_usuario = new Estudiante(this->nickname_recordado, this->contrasena_recordado, this->nombre_recordado, this->descripcion_recordado, this->tipo_Usuario_recordado, this->nombre_Pais_recordado, this->fecha_Nacimiento_recordado);
            }
        }
        this->usuarios.insert(pair<string, Usuario*>(this->nickname_recordado,nuevo_usuario));
    }
    this->liberarMemoriaRecordada();
    return (!(ya_esta_usuario)); // retorna true si se agrego el usuario
}

void ControladorUsuarios::liberarMemoriaRecordada(){
    nickname_recordado.clear();
    contrasena_recordado.clear();
    nombre_recordado.clear();
    descripcion_recordado.clear();
    nombre_Pais_recordado.clear();
    nombre_Instituto_recordado.clear();
    lista_idiomas_recordado.clear();
    nickname_listarIdiomasNoSuscritos_recordado.clear();
}

vector<string> ControladorUsuarios::listarEstudiantes(){
    vector<string> nicknames_a_listar;
    map<string,Usuario*>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        Usuario* user = it->second;
        if (user->getTipo() == Est)
            nicknames_a_listar.push_back(user->getNickname());
    }
    return nicknames_a_listar;
}

vector<string> ControladorUsuarios::listarProfesores(){
    vector<string> nicknames_a_listar;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        Usuario* user = it->second;
        if (user->getTipo() == Prof)
            nicknames_a_listar.push_back(user->getNickname());
    }
    return nicknames_a_listar;
}

vector<DTEstEstudiante> ControladorUsuarios::listarEstEstudiante(string nickname){
    vector<DTEstEstudiante> estadisticas;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
        Estudiante* objetoDerivado = dynamic_cast<Estudiante*>(it->second);
        if(objetoDerivado)
            estadisticas = objetoDerivado->listarEstEstudiante();
    }
    return estadisticas;
}

vector<DTEstProfesor> ControladorUsuarios::listarEstProfesor(string nickname){
    vector<DTEstProfesor> estadisticas;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
        Profesor* objetoDerivado = dynamic_cast<Profesor*>(it->second);
        if(objetoDerivado)
            estadisticas = objetoDerivado->listarEstProfesor();
    }
    return estadisticas;
}

vector<DTIdioma> ControladorUsuarios::listaIdiomasProfesor(string nickname){
    vector<DTIdioma> listar;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
        Profesor* objetoDerivado = dynamic_cast<Profesor*>(it->second);
        if(objetoDerivado)
            listar = objetoDerivado->getDTidiomas();
    }
    return listar;
}

vector<DTCurso> ControladorUsuarios::listarCursosNoAprobados(string nickname)
{
    vector<DTCurso> cursos_a_listar;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
    Estudiante* objetoDerivado = dynamic_cast<Estudiante*>(it->second);
    if (objetoDerivado)
    {
        map<string, Inscripcion*> inscripciones_del_estudiante = objetoDerivado->getInscripciones();
        map<string, Inscripcion*>::iterator it2;
        for (it2 = inscripciones_del_estudiante.begin(); it2 != inscripciones_del_estudiante.end(); ++it2)
        {
            bool esta_aprobado = it2->second->getCursoAprobado();
            if (!esta_aprobado)
            {
                cursos_a_listar.push_back(it2->second->getDataCurso());
            }
        }
    }
    }
    return cursos_a_listar;
}

vector<DTNotificacion> ControladorUsuarios::listarNotificaciones(string nickname)
{   
    return buscarUsuario(nickname)->getDTNotificaciones();
}

vector<DTIdioma> ControladorUsuarios::listarIdiomasSuscritos(string nickname)
{   
    vector<DTIdioma> salida;
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
        salida = it->second->listarDTidiomasSuscritos();
    }
    return salida;
}

Usuario* ControladorUsuarios::buscarUsuario(string nickname)
{   
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    if(esta){
        return it->second;
    }
    return nullptr;
}

bool ControladorUsuarios::existeUsuario(string nickname)
{   
    map<string,Usuario*>::iterator it;
    it = this->usuarios.find(nickname);
    bool esta = this->usuarios.end() != it;
    return esta;
}

static void quitarIdioma(vector<DTIdioma>& idiomas,DTIdioma idioma)
{   
    vector<DTIdioma>::iterator it;
    for (it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        if ((*it) == idioma)
        {
            idiomas.erase(it);
        }
    }
}

vector<DTIdioma> ControladorUsuarios::listarIdiomasNoSuscritos(string nickname)
{
    vector<DTIdioma> idiomas_suscritos = this->listarIdiomasSuscritos(nickname);
    vector<DTIdioma> idiomas_todos = this->listarIdiomas();
    vector<DTIdioma>::iterator it;
    for (it = idiomas_suscritos.begin(); it != idiomas_suscritos.end(); ++it)
    {
        quitarIdioma(idiomas_todos,(*it));
    }
    this->nickname_listarIdiomasNoSuscritos_recordado = nickname;
    return idiomas_todos;
};

void ControladorUsuarios::suscribir(vector<DTIdioma> idiomasASuscribir)
{
    Usuario* user = this->buscarUsuario(this->nickname_listarIdiomasNoSuscritos_recordado);
    vector<Idioma*> idiomas;
    vector<DTIdioma>::iterator it_dt;

    for (it_dt = idiomasASuscribir.begin(); it_dt != idiomasASuscribir.end(); it_dt++) {
        idiomas.push_back(this->idiomas.find(it_dt->getNombre())->second);
    }

    vector<Idioma*>::iterator it;
    for (it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        user->agregarIdioma(*it);
        Idioma* asignar = (*it);
        IObserver* basePtr = user;
        asignar->agregarObservador(basePtr);
    }
};

void ControladorUsuarios::eliminarSuscripcion(vector<DTIdioma> idiomasAEliminar) {
    Usuario* user = buscarUsuario(nickname_listarIdiomasNoSuscritos_recordado);
    vector<Idioma*> idiomas;
    vector<DTIdioma>::iterator it_dt;

    for (it_dt = idiomasAEliminar.begin(); it_dt != idiomasAEliminar.end(); it_dt++) {
        idiomas.push_back(this->idiomas.find(it_dt->getNombre())->second);
    }

    vector<Idioma*>::iterator it;
    IObserver* observador = user;
    for(it = idiomas.begin();it != idiomas.end();++it){
        user->eliminarIdioma(*it);
        (*it)->eliminarObservador(observador);
    }
}

bool ControladorUsuarios::iniciarAltaIdioma(DTIdioma idioma)
{
    string nombre = idioma.getNombre();
    map<string, Idioma*>::iterator it;
    it = this->idiomas.find(nombre);
    bool esta = this->idiomas.end() != it;
    if (!esta) {
        Idioma *idiomaNuevo = new Idioma(nombre);
        this->idiomas.insert(pair<string, Idioma*>(nombre,idiomaNuevo));
    }
    return esta;
}

vector<string> ControladorUsuarios::listarNickname() {

    vector<string> salida;
    map<string, Usuario*>::iterator it;
    for(it = usuarios.begin(); it != usuarios.end(); it++) {
        salida.push_back(it->second->getNickname());
    }
    return salida;
}

DTUsuario *ControladorUsuarios::getDataUsuario(string nickname) {
    return usuarios.find(nickname)->second->getDataUsuario();
}

map<string, Idioma*> ControladorUsuarios::getIdiomas() {
    return idiomas;
}
