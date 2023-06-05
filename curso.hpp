#ifndef CURSO_HPP
#define CURSO_HPP

#include <string>
#include <vector>
#include "dificultad.hpp"
#include "dt_est_curso.hpp"
#include "dt_idioma.hpp"
#include "dt_profesor.hpp"
#include "dt_curso.hpp"
#include "controlador_usuarios.hpp"
#include "leccion.hpp"
#include "ejercicio.hpp"
#include "dt_estudiante.hpp"
using namespace std;

class Inscripcion;
class Profesor;

class Curso{
private:
    string nombre;
    string descripcion;
    Dificultad dificultad;
    map <string, Inscripcion*> Inscripciones;
    vector <Leccion*> Lecciones;
    Profesor* profesorAsignado;

public:
    Curso(string nombre, string descripcion, Dificultad dificultad);
    virtual ~Curso();
    string getNombre();
    string getDescripcion();
    Dificultad getDificultad();
    DTCurso getdataCurso();
    int getTotalEjercicios();
    void crearLeccion(string nombreTema, string objetivo);
    DTEstCurso listarEstCurso(string nickname);
    int getPromedioAvance();
};

#endif
