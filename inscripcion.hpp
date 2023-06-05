#ifndef INSCRIPCION_HPP
#define INSCRIPCION_HPP

#include <string>
#include <vector>
#include "dt_fecha.hpp"
#include "estudiante.hpp"
#include "curso.hpp"
#include "estudiante.hpp"
#include "leccion.hpp"
#include "ejercicio.hpp"
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
    map<string, Ejercicio*> ejerciciosPendientes;
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
};

#endif
