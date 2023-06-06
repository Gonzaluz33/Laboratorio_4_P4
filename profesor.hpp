#ifndef PROFESOR_HPP
#define PROFESOR_HPP

#include <string>
#include <map>
#include "usuario.hpp"
#include "dt_est_profesor.hpp"
#include "dt_idioma.hpp"
#include "curso.hpp"
#include "dt_profesor.hpp"

using namespace std;

class Profesor : public Usuario{
    private:
        string instituto;
        vector<Idioma*> idiomasEsp;
        vector<Curso*> cursosADar;
    public:
        Profesor(string nick, string con, string nom, string desc, TipoUsuario tp, string inst, vector<DTIdioma> dts_idiomas);
        virtual ~Profesor();
        string getInstituto();
        void setInstituto(string);
        vector<DTIdioma> getDTidiomas();
        vector<DTEstProfesor> listarEstProfesor();
        DTProfesor getDataProfesor();
};

#endif
