#include "usuario.hpp"
#include "dt_est_estudiante.hpp"
#include "dt_curso.hpp"
#include "inscripcion.hpp"
#include "dt_ejercicio.hpp"
#include "dt_fecha.hpp"
#include <map>
#include <string>

using namespace std;

class Estudiante:public Usuario {
    private:
        string pais_residencia;
        DTFecha fecha_nacimiento;
        map<string, Inscripcion*> inscripciones;
    public:
        Estudiante(string,string,string,string,TipoUsuario,string,DTFecha);
        virtual ~Estudiante();
        void setPaisResidencia(string);
        string getPaisResidencia();
        void setFechaNaciomiento(DTFecha);
        DTFecha getFechaNacimiento();
        vector<DTEstEstudiante> listarEstEstudiante();
        vector<DTEjercicio> listarEjerciciosPendientes(string);
        void actualizarInscripcion(string);
};
