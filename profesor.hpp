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
<<<<<<< HEAD
        profesor(vector<DTIdioma> idiomas,string nickname,string,string,string,TipoUsuario,string);
        virtual ~profesor();
=======
        Profesor(string,string,string,string,TipoUsuario,string);
        virtual ~Profesor();
>>>>>>> d0bad834e57d6721de264e519e539139d084bf6e
        string getInstituto();
        void setInstituto(string);
        vector<DTIdioma*> getDTidiomas();
        vector<DTEstProfesor*> listarEstProfesor();
        void agregarIdiomaEsp(Idioma);
        void eliminarIdiomaEsp(Idioma);
        void agregarCurso(Curso);
        void eliminarCurso(Curso);
};


