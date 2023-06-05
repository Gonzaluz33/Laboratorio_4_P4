#include <string>
#include <vector>
#include "DTFecha"
#include "dt_est_curso.hpp"
#include "dt_est_estudiante.hpp"
using namespace std;

class Inscripcion{
private:
    DTFecha fechaInscripcion;
    int porcentajeEjerciciosRealizados;
    int cantidadEjerciciosRealizados;
    bool cursoAprobado;
    Curso* cursoAsignado;
    Estudiante* estudianteAsignado;
    Leccion* leccionAsignada;
    map<string, Ejercicio*> Ejercicios;
public:
    Inscripcion(DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal, bool cursoAprobado);
    virtual~Inscripcion();
    DTFecha getFechaInscripcion();
    DTCurso getDataCurso();
    int getPorcentajeEjerciciosRealizados();
    int getCantidadEjerciciosRealizados();
    bool getCursoAprobado();
    DTEstEstudiante getEstEstudiante();
    Leccion* getLeccionActual();
    vector<DTEjercicio> listarEjerciciosPendientes();
    void incrementarCantEjRealizados();
    void eliminarDePendientes(Ejercicio *ej);
    bool leccionTerminada(int cantEjActualizado, int totalEj);
    int getPorcentajeEjerciciosRealizados();
};


