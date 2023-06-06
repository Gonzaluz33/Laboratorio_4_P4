#ifndef CONTROLADOR_USUARIOS_HPP
#define CONTROLADOR_USUARIOS_HPP

#include <iostream>
#include <vector>
#include <map>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "idioma.hpp"
#include "dt_fecha.hpp"
#include "usuario.hpp"
#include "dt_est_estudiante.hpp"
#include "dt_est_profesor.hpp"
#include "icontrolador_usuarios.hpp"

using namespace std;

class ControladorUsuarios : public IControladorUsuarios {
    private:
        ControladorUsuarios();
        ~ControladorUsuarios();
        static ControladorUsuarios* instancia;
        map<string, Usuario*> usuarios;
        map<string,Idioma*> Idiomas;        
        string nickname_recordado;
        string contrasena_recordado;
        string nombre_recordado;
        string descripcion_recordado;
        TipoUsuario tipo_Usuario_recordado;
        string nombre_Pais_recordado;
        DTFecha fecha_Nacimiento_recordado;
        string nombre_Instituto_recordado;
        vector<DTIdioma> lista_idiomas_recordado;
        string nickname_listarIdiomasNoSuscritos_recordado;
    public:
        void liberarMemoriaRecordada();
        static ControladorUsuarios* getInstance();
        void iniciarAltaUsuario (string nickname ,string contrasenia,string nombre,
                                 string descripcion, TipoUsuario tipo);
        void datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento);
        void datosAdicionalesProfesor(string nom_Instituto);
        vector <DTIdioma> listarIdiomas();
        void seleccionarIdioma(DTIdioma Idioma);
        bool altaUsuario();
        Usuario* buscarUsuario(string nickname);//auxiliar
        vector <string> listarEstudiantes();
        vector <DTEstEstudiante> listarEstEstudiante(string nickname); 
        vector <string> listarProfesores(); 
        vector <DTEstProfesor> listarEstProfesor(string nickname);
        vector <DTIdioma> listaIdiomasProfesor(string nickname);
        vector <DTCurso> listarCursosNoAprobados(string nickname);
        vector <DTNotificacion> listarNotificaciones(string nickname);
        vector <DTIdioma>listarIdiomasSuscritos(string nickname);
        vector <DTIdioma> listarIdiomasNoSuscritos(string nickname);
        void suscribir(vector <Idioma*> idiomasASuscribir);
        void eliminarSuscripcion(vector <Idioma*>idiomasAEliminar);
        map<string, Idioma*> getIdiomas();
        vector<string> listarNickname();
        bool iniciarAltaIdioma(DTIdioma idioma);
        DTUsuario getDataUsuario(string nickname);
};

#endif
