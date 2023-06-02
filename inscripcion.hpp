#include <string>
#include <vector>
#include "DTFecha"
#include "dt_est_curso.hpp"
#include "dt_est_estudiante.hpp"
using namespace std;

class Inscripcion{
private:
    DTFecha fechaInscripcion;
    int porsentajeEjerciciosRealizados;
    int cantidadEjerciciosRealizados;
    bool cursoAprobado;
    Curso* cursoAsignado;
    Estudiante* estudianteAsignado;
    Leccion* leccionAsignada;
    vector <Ejercicio*> Ejercicios;
public:
    Inscripcion(DTFecha fechaInscripcion, int porEjerReal, int cantEjerReal, bool cursoAprobado);
    virtual~Inscripcion();
    DTFecha getFechaInscripcion();
    void setFechaInscripcion(DTFecha f);
    int getPorsentajeEjerciciosRealizados();
    void setPorsentajeEjerciciosRealizados(int p);
    int getCantidadEjerciciosRealizados();
    void setCantidadEjerciciosRealizados(int cant);
    bool getCursoAprobado();
    void setCursoAprobado(bool curso);
    DTEstEstudiante getEstEstudiante();
    Leccion* getLeccionActual();
    vector<DTEjercicio> listarEjerciciosPendientes();
    void incrementarCantEjRealizados();
    void eliminarDePendientes(Ejercicio *ej);
    bool leccionTerminada(int cantEjActualizado, int totalEj);
    int getPorcentajeEjerciciosRealizados();
};


