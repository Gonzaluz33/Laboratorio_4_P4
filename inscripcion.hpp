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
#include "dt_inscripcion.hpp"

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
    Inscripcion(Curso *curso, Estudiante *estudiante, DTFecha fechaInscripcion);
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
    Curso *getCurso();
    DTInscripcion getDataInscripcion();
    //bool leccionTerminada(int cantEjActualizado, int totalEj); Parece que no lo usamos
    //int getCantidadEjerciciosPendientes();
};

#endif
