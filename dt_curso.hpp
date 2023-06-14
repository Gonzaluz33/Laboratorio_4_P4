#ifndef DT_CURSO_HPP
#define DT_CURSO_HPP

#include <string>
#include "dificultad.hpp"
#include "dt_idioma.hpp"
#include "dt_profesor.hpp"
#include "dt_leccion.hpp"
#include "dt_inscripcion.hpp"

using namespace std;

class DTCurso {
public:
    DTCurso(string nombre, string descripcion, Dificultad dificultad, DTIdioma idioma,
            int cantidadLecciones, int cantidadEjercicios, DTProfesor *profesor,
            bool estaHabilitado, vector<DTLeccion> lecciones, vector<DTInscripcion> inscripciones,
            vector<DTCurso> cursosPrevios);
    DTCurso(const DTCurso &otro);
    ~DTCurso();
    string getNombre();
    string getDescripcion();
    Dificultad getDificultad();
    DTIdioma getIdioma();
    int getCantidadLecciones();
    int getCantidadEjercicios();
    DTProfesor *getProfesor();
    bool getEstaHabilitado();
    vector<DTLeccion> getLecciones();
    vector<DTInscripcion> getInscripciones();
    vector<DTCurso> getCursosPrevios();
private:
    string nombre, descripcion;
    Dificultad dificultad;
    DTIdioma idioma;
    int cantidadLecciones, cantidadEjercicios;
    DTProfesor *profesor;
    bool estaHabilitado;
    vector<DTLeccion> lecciones;
    vector<DTInscripcion> inscripciones;
    vector<DTCurso> cursosPrevios;
};

#endif
