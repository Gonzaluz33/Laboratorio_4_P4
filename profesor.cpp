#include "profesor.hpp"
#include "controlador_usuarios.hpp"

using namespace std;

Profesor::Profesor(string nick,string con, string nom,string desc,TipoUsuario tp,string inst, vector<DTIdioma> dts_idiomas):
    Usuario(nick,con,nom,desc,tp)
{
    this->instituto=inst;
    ControladorUsuarios *cu = ControladorUsuarios::getInstance();
    map<string, Idioma*> idiomas = cu->getIdiomas();
    vector<DTIdioma>::iterator it;
    for(it = dts_idiomas.begin(); it != dts_idiomas.end(); it++) {
        idiomasEsp.push_back(idiomas.find(it->getNombre())->second);
    }
}

Profesor::~Profesor(){}

string Profesor::getInstituto(){
    return this->instituto;
}

void Profesor::setInstituto(string inst){
    this->instituto=inst;
}

vector<DTIdioma> Profesor::getDTidiomas(){
    vector<DTIdioma> id;
    vector<Idioma*>::iterator it;
    it = this->idiomasEsp.begin();
    while(it != this->idiomasEsp.end()){
        id.insert(id.begin(),(*it)->getDataIdioma());
        it++;
    }
    return id;
}

vector<DTEstProfesor> Profesor::listarEstProfesor(){
    vector<DTEstProfesor> dtep;
    for(auto i = this->cursosADar.begin();i != this->cursosADar.end();i++){
        DTEstProfesor dt = DTEstProfesor((*i)->getdataCurso(), (*i)->getPromedioAvance());
        dtep.insert(dtep.begin(),dt);
    }
    return dtep;
}

