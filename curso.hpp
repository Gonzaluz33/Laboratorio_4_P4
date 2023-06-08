#ifndef CURSO_HPP
#define CURSO_HPP

#include <string>
#include <vector>
#include "dificultad.hpp"
#include "dt_est_curso.hpp"
#include "dt_idioma.hpp"
#include "dt_profesor.hpp"
#include "dt_curso.hpp"
#include "dt_leccion.hpp"
#include "controlador_usuarios.hpp"
#include "leccion.hpp"
#include "ejercicio.hpp"
#include "dt_estudiante.hpp"
#include "idioma.hpp"

using namespace std;

class Inscripcion;
class Profesor;

class Curso {
private:
    string nombre;
    string descripcion;
    Dificultad dificultad;
    map <string, Inscripcion*> inscripciones;
    vector <Leccion*> lecciones;
    Profesor* profesorAsignado;
    Idioma *idioma;
    vector<Curso*> cursosPrevios;
    bool estaHabilitado;

public:
    Curso(string nombre, string descripcion, Dificultad dificultad, Profesor *profesor, Idioma *idioma, vector<Curso*> cursosPrevios);
    virtual ~Curso();
    string getNombre();
    string getDescripcion();
    Dificultad getDificultad();
    DTCurso getdataCurso();
    int getTotalEjercicios();
    Leccion *crearLeccion(string nombreTema, string objetivo);
    DTEstCurso listarEstCurso();
    int getPromedioAvance();
    vector<Leccion*> getLecciones();
    Idioma *getIdioma();
    vector<DTLeccion> listarLeccionesOrdenado();
    Leccion *seleccionarLeccion(string nombreTema);
    vector<Curso*> getCursosPrevios();
    void setEstaHabilitado(bool valor);
};

#endif
