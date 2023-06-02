#include <string>
#include "usuario.hpp"
#include "dt_est_profesor.hpp"
#include "dt_idioma.hpp"
#include "curso.hpp"

using namespace std;

class Profesor : public Usuario{
    private:
        string instituto;
        vector<Idioma*> idiomasEsp;
        vector<Curso*> cursosADar;
    public:
        Profesor(string,string,string,string,TipoUsuario,string);
        virtual ~Profesor();
        string getInstituto();
        void setInstituto(string);
        vector<DTIdioma*> getDTidiomas();
        vector<DTEstProfesor*> listarEstProfesor();
        virtual notificar(string,string);
        void agregarIdiomaEsp(Idioma);
        void eliminarIdiomaEsp(Idioma);
        void agregarCurso(Curso);
        void eliminarCurso(Curso);
};


