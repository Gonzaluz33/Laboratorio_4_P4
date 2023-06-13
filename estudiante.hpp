#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include "curso.hpp"
#include "usuario.hpp"
#include "ejercicio.hpp"
#include "dt_est_estudiante.hpp"
#include "dt_curso.hpp"
#include "dt_ejercicio.hpp"
#include "dt_fecha.hpp"
#include <map>
#include <string>

using namespace std;

class Inscripcion;

class Estudiante:public Usuario {
    private:
        string pais_residencia;
        DTFecha fecha_nacimiento;
        map<string, Inscripcion*> inscripciones;
    public:
        Estudiante(string nick, string contr, string nom, string desc,TipoUsuario tu,string pr,DTFecha fn);
        virtual ~Estudiante();
        void setPaisResidencia(string);
        string getPaisResidencia();
        void setFechaNaciomiento(DTFecha);
        DTFecha getFechaNacimiento();
        vector<DTEstEstudiante> listarEstEstudiante();
        vector<DTEjercicio*> listarEjerciciosPendientes(string);
        void actualizarInscripcion(string,Ejercicio *);
        map<string, Inscripcion*> getInscripciones();
        Inscripcion *getInscripcionDeCurso(string nombreCurso);
        void inscribirse(Curso *curso,DTFecha fecha);
        DTUsuario *getDataUsuario();
};

#endif
