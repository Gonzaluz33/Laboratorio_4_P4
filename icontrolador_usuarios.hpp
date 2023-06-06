#ifndef ICONTROLADOR_USUARIOS_HPP
#define ICONTROLADOR_USUARIOS_HPP

#include <vector>
#include <map>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "idioma.hpp"
#include "dt_fecha.hpp"
#include "usuario.hpp"
#include "dt_est_estudiante.hpp"
#include "dt_est_profesor.hpp"

using namespace std;

class IControladorUsuarios {
public:
    IControladorUsuarios(){};
    virtual ~IControladorUsuarios(){};
    virtual void liberarMemoriaRecordada()=0;
    virtual void iniciarAltaUsuario (string nickname ,string contrasenia,string nombre,
                                     string descripcion, TipoUsuario tipo)=0;
    virtual void datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento)=0;
    virtual void datosAdicionalesProfesor(string nom_Instituto)=0;
    virtual vector <DTIdioma> listarIdiomas()=0;
    virtual void seleccionarIdioma(DTIdioma Idioma)=0;
    virtual bool altaUsuario()=0;
    virtual Usuario* buscarUsuario(string nickname)=0;//auxiliar
    virtual vector <string> listarEstudiantes()=0;
    virtual vector <DTEstEstudiante> listarEstEstudiante(string nickname)=0; 
    virtual vector <string> listarProfesores()=0; 
    virtual vector <DTEstProfesor> listarEstProfesor(string nickname)=0;
    virtual vector <DTIdioma> listaIdiomasProfesor(string nickname)=0;
    virtual vector <DTCurso> listarCursosNoAprobados(string nickname)=0;
    virtual vector <DTNotificacion> listarNotificaciones(string nickname)=0;
    virtual vector <DTIdioma>listarIdiomasSuscritos(string nickname)=0;
    virtual vector <DTIdioma> listarIdiomasNoSuscritos(string nickname)=0;
    virtual void suscribir(vector <Idioma*> idiomasASuscribir)=0;
    virtual void eliminarSuscripcion(vector <Idioma*>idiomasAEliminar)=0;
    virtual map<string, Idioma*> getIdiomas()=0;
    virtual vector<string> listarNickname()=0;
    virtual bool iniciarAltaIdioma(DTIdioma idioma)=0;
    virtual DTUsuario getDataUsuario(string nickname)=0;
};

#endif
