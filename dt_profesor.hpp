#ifndef DT_PROFESOR_HPP
#define DT_PROFESOR_HPP

#include "dt_usuario.hpp"
#include <string>
#include "dt_idioma.hpp"
#include <vector>

using namespace std;

class DTProfesor : public DTUsuario {
public:
    DTProfesor(string nickname, string nombre, string descripcion,
               string instituto, vector<DTIdioma> idiomas);
    ~DTProfesor();
    string getInstituto();
    vector<DTIdioma> getIdiomas();
private:
    string instituto;
    vector<DTIdioma> idiomas;
};

#endif
