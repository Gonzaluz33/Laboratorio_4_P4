#include "usuario.hpp"
#include "ejercicio.hpp"
#include "dt_est_estudiante.hpp"
#include "inscripcion.hpp"
#include <string>
#include <map>

using namespace std;

class Inscripcion{};
class DTCurso{};

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
        virtual notificar(string,string);
};
