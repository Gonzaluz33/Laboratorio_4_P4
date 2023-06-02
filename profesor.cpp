#include "profesor.hpp"

Profesor::Profesor(string nick,string con, string nom,string desc,TipoUsuario tp,string inst) : Usuario(nick,con,nom,desc,tp){
    this->instituto=inst;
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
    map<string,idioma*>::iterator it;
    it = this->idiomasEsp.begin();
    while(it <= this->idiomasEsp.end()){
        id.insert(id.begin(),*it->getDataIdioma());
        it++;
    }
    return id;
}

vector<DTEstProfesor> Profesor::listarEstProfesor(){
    vector<DTEstProfesor> dtep;
    for(auto i = this->cursosADar.begin();i != this->cursosADar.end();i++){
        DTEstProfesor dt = DTEstProfesor(*i,*i->getPromedioAvance());
        dtep.insert(dtep.begin(),dt);
    }
    return dtep;
}

void Profesor::agregarIdiomaEsp(Idioma id){
    this->idiomasEsp.insert(par<string,Idioma*>(this->idiomasEsp.begin(),id));
}

void Profesor::eliminarIdiomaEsp(Idioma id){
    if(this->idiomasEsp.count(id.getNombre())){
        this->idiomasEsp.erase(id.getNombre());
    }
}

void Profesor::agregarCurso(Curso c){
    this->cursosADar.insert(par<string,Curso*>(this->cursosADar.begin(),c));
}

void Profesor::eliminarCurso(Curso c){
    if(this->cursosADar.count(c.getNombre())){
        this->cursosADar.erase(c.getNombre());
    }
}