#include <iostream>
#include <vector>
using namespace std;

class Idioma;
class DTEstEstudiante;
class DTEstProfesor;
class Curso;
class Notificacion;

class ControladorUsuarios {
    private: 
        static ControladorUsuarios * instancia;
        ControladorUsuarios();
    public:
    static ControladorUsuarios * getInstance();
    void iniciarAltaUsuario (string nickname ,string contraseña,string nombre,string descripción);
    void datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento);
    void datosAdicionalesProfesor(string nom_Instituto);
    vector <Idioma*> listaIdiomas();
    void seleccionarIdioma(string nom_Idioma);
    bool altaUsuario();
    vector <string> listarEstudiantes();
    vector <DTEstEstudiante*> listarEstEstudiante(string nickname);
    vector <string> listarProfesores();
    vector <DTEstProfesor*> listarEstProfesor(string nickname);
    vector <Idioma*> listaIdiomasProfesor(string nickname);
    vector <Curso*> listarCursosNoAprobados(string nickname);
    vector <Notificacion*> listarNotificaciones(string nickname);
    vector <Idioma*>listarIdiomasSuscritos(string nickname);
    vector <Idioma*> listarIdiomasNoSuscritos(string nickname);
    void suscribir(vector <Idioma*> idiomasASuscribir);
    void eliminarSuscripcion(vector <Idioma*>idiomasAEliminar);
};