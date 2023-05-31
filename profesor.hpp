#include <string>
#include "usuario.hpp"
#include "dt_est_profesor.hpp"
#include "dt_idioma.hpp"

class curso{};

class profesor : public usuario{
    private:
        string instituto;
        vector<idioma*> idiomasEsp;
        vector<curso*> cursosADar;
    public:
        profesor(string,string,string,string,TipoUsuario,string);
        virtual ~profesor();
        string getInstituto();
        void setInstituto(string);
        vector<DTIdioma*> getDTidiomas();
        vector<DTEstProfesor*> listarEstProfesor();
        virtual notificar(string,string);
        void agregarIdiomaEsp(idioma);
        void eliminarIdiomaEsp(idioma);
        void agregarCurso(curso);
        void eliminarCurso(curso);
};


