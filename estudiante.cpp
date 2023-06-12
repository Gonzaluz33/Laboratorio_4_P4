#include "estudiante.hpp"
#include "inscripcion.hpp"

Estudiante::Estudiante(string nick, string contr, string nom, string desc,TipoUsuario tu,string pr,DTFecha fn):
    Usuario(nick,contr,nom,desc,tu),
    fecha_nacimiento(fn),
    pais_residencia(pr)
{

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
    map<string, Inscripcion*>::iterator i;
    for(i=this->inscripciones.begin(); i != this->inscripciones.end(); i++) {
        DTEstEstudiante dtee = DTEstEstudiante(i->second->getDataCurso(),
                            i->second->getPorcentajeEjerciciosRealizados());
        dte.push_back(dtee);
    }
    return dte;
}

vector<DTEjercicio*> Estudiante::listarEjerciciosPendientes(string nombre_curso){
    vector<DTEjercicio*> dte;

    Inscripcion *inscripcion = inscripciones.find(nombre_curso)->second;
    return inscripcion->listarEjerciciosPendientes();
}

void Estudiante::actualizarInscripcion(string nombCurso,Ejercicio *ej){
    map<string,Inscripcion*>::iterator it;
    it = this->inscripciones.find(nombCurso);
    it->second->incrementarCantEjRealizados();
    it->second->eliminarDePendientes(ej);
}

Inscripcion *Estudiante::getInscripcionDeCurso(string nombreCurso) {
    return inscripciones.find(nombreCurso)->second;
}

map<string, Inscripcion*> Estudiante::getInscripciones() {
    return inscripciones;
}

void Estudiante::inscribirse(Curso* curso, DTFecha fecha){
    Inscripcion* insc = new Inscripcion(curso,this,fecha);
    this->inscripciones.insert(pair<string,Inscripcion*>(curso->getNombre(), insc));
    curso->agregarInscripcion(insc,this->getNickname());
}
