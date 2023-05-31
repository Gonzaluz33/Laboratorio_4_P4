#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "dificultad.hpp"
#include "dt_est_curso.hpp"
#include "dt_idioma.hpp"
#include "dt_profesor.hpp"
#include "dt_curso.hpp"
#include "controlador_usuarios.hpp"
#include "inscripcion.hpp"
#include "leccion.hpp"
#include "ejercicio.hpp"
#include "profesor.hpp"
#include "dt_estudiante.hpp"


class Curso{
private:
    string nombre;
    string descripcion;
    Dificultad dificultad;
    vector <Inscripcion*> Inscripciones;
    vector <Leccion*> Lecciones;
    vector <Ejercicio*> Ejercicios;
    Profesor* profesorAsignado;

public:
    Curso(string nombre, string descripcion, Dificultad dificultad);
    virtual ~Curso();
    string getNombre();
    void setNombre(string nom);
    string getDescripcion();
    void setDescripcion(string des);
    Dificultad getDificultad();
    void setDificultad(Dificultad dif);
    DTCurso getdataCurso();
    int getTotalEjercicios();
    void crearLeccion(string nombreTema, string objetivo);
    set(DTEstCurso) listarEstCurso();
    int getPromedioAvance();
};