#include "estudiante.hpp"

Estudiante::Estudiante(string nick, string contr, string nom, string desc,TipoUsuario tu,string pr,DTFecha fn) : Usuario(nick,contr,nom,desc,tu){
    this->pais_residencia=pr;
    this->fecha_nacimiento=fn;
}

Estudiante::~Estudiante(){
    
}

void Estudiante::setPaisResidencia(string pr){
    this->pais_residencia=pr;
}

string Estudiante::getPaisResidencia(){
    return this->pais_residencia;
}

void Estudiante::setFechaNaciomiento(DTFecha fn){
    this->fecha_nacimiento=fn;
}

DTFecha Estudiante::getFechaNacimiento(){
    return this->fecha_nacimiento;
}

vector<DTEstEstudiante> Estudiante::listarEstEstudiante(){
    vector<DTEstEstudiante> dte;
    for(auto i=this->inscripciones.begin();i != this->inscripciones.end();i++){
        DTEstEstudiante dtee = DTEstEstudiante(*i->curso,*i->getEjerciciosRealizados());
        dte.insert(dte.begin(),dtee);
    }
    return dte;
}

vector<DTEjercicio> Estudiante::listarEjerciciosPendientes(string nombre_curso){
    vector<DTEjercicio> dte;
    map<string,inscripcion*>::iterator it;
    it = this->inscripciones.begin();
    while(it != this->inscripciones.end()){
        vector<DTEjercicio> dte1;
        dte1 = *it->listarEjerciciosPendientes();
        dte = dte + dte1;
    }
    return dte;
}

void Estudiante::actualizarInscripcion(string nombCurso,Ejercicio ej){
    map<string,inscripcion*>::iterator it;
    it = this->inscripciones.find(nombCurso);
    *it.incrementarCantEjRealizados();
    *it.eliminarDePendientes(ej);
}
