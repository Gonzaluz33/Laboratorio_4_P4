#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
class DTIdioma;
class DTFecha;
class DTEstEstudiante;
class DTEstProfesor;
class DTCurso;
class DTNotificacion;
class Usuario;
enum TipoUsuario {Prof,Est};

class ControladorUsuarios {
    private: 
        ~ControladorUsuarios();
        static ControladorUsuarios* instancia;
        ControladorUsuarios();
        map<string, Usuario*> Usuarios;
        map<string,Idioma*> Idiomas;        
        string nickname_recordado;
        string contrasena_recordado;
        string nombre_recordado;
        string descripcion_recordado;
        TipoUsuario tipo_Usuario_recordado;
        string nombre_Pais_recordado;
        DTFecha fecha_Nacimiento_recordado;
        string nombre_Instituto_recordado;
        vector <DTIdioma> lista_idiomas_recordado;
        string nickname_listarIdiomasNoSuscritos_recordado;
    public:
    void liberarMemoriaRecordada();
    static ControladorUsuarios* getInstance();
    void iniciarAltaUsuario (string nickname ,string contraseña,string nombre,string descripción);
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
};