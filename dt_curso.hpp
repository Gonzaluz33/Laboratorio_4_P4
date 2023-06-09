#ifndef DT_CURSO_HPP
#define DT_CURSO_HPP

#include <string>
#include "dificultad.hpp"
#include "dt_idioma.hpp"
#include "dt_profesor.hpp"

using namespace std;

class DTCurso {
public:
    DTCurso(string nombre, string descripcion, Dificultad dificultad, DTIdioma idioma,
            int cantidadLecciones, int cantidadEjercicios, DTProfesor profesor);
    ~DTCurso();
    string getNombre();
    string getDescripcion();
    Dificultad getDificultad();
    DTIdioma getIdioma();
    int getCantidadLecciones();
    int getCantidadEjercicios();
    DTProfesor getProfesor();
private:
    string nombre, descripcion;
    Dificultad dificultad;
    DTIdioma idioma;
    int cantidadLecciones, cantidadEjercicios;
    DTProfesor profesor;
};

#endif
