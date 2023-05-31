#include "usuario.hpp"
#include "ejercicio.hpp"
#include "dt_est_estudiante.hpp"

using namespace std;

class inscripcion{};
class DTCurso{};

class estudiante:public usuario{
    private:
        string pais_residencia;
        DTFecha fecha_nacimiento;
        vector<inscripcion> inscripciones;
    public:
        estudiante(string,string,string,string,TipoUsuario,string,DTFecha);
        virtual ~estudiante();
        void setPaisResidencia(string);
        string getPaisResidencia();
        void setFechaNaciomiento(DTFecha);
        DTFecha getFechaNacimiento();
        vector<DTEstEstudiante> listarEstEstudiante();
        vector<DTEjercicio> listarEjerciciosPendientes(string);
        void actualizarInscripcion(ejercicio);
        virtual notificar(string,string);
};
