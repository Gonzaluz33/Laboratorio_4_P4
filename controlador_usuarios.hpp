#include <iostream>
#include <vector>
using namespace std;

class DTIdioma;
class DTEstEstudiante;
class DTEstProfesor;
class DTCurso;
class DTNotificacion;

class ControladorUsuarios {
    private: 
        static ControladorUsuarios * instancia;
        ControladorUsuarios();
    public:
    static ControladorUsuarios * getInstance();
    void iniciarAltaUsuario (string nickname ,string contraseña,string nombre,string descripción);
    void datosAdicionalesEstudiante(string nom_Pais,DTFecha fecha_Nacimiento);
    void datosAdicionalesProfesor(string nom_Instituto);
    vector <DTIdioma*> listaIdiomas();
    void seleccionarIdioma(string nom_Idioma);
    bool altaUsuario();
    vector <string> listarEstudiantes();
    vector <DTEstEstudiante*> listarEstEstudiante(string nickname);
    vector <string> listarProfesores();
    vector <DTEstProfesor*> listarEstProfesor(string nickname);
    vector <DTIdioma*> listaIdiomasProfesor(string nickname);
    vector <DTCurso*> listarCursosNoAprobados(string nickname);
    vector <DTIdioma*>listarIdiomasSuscritos(string nickname);
    vector <DTIdioma*> listarIdiomasNoSuscritos(string nickname);
    void suscribir(vector <Idioma*> idiomasASuscribir);
    void eliminarSuscripcion(vector <Idioma*>idiomasAEliminar);
};