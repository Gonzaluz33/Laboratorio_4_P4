#ifndef ICONTROLADOR_CURSOS_HPP
#define ICONTROLADOR_CURSOS_HPP

#include <string>
#include <vector>
#include "dt_curso.hpp"
#include "dt_idioma.hpp"
#include "dt_leccion.hpp"
#include "dt_ejercicio.hpp"
#include "dt_est_curso.hpp"
#include "dificultad.hpp"
#include "tipo_ejercicio.hpp"
#include "ejercicio.hpp"

using namespace std;

class IControladorCursos {
public:
    virtual ~IControladorCursos(){};

    virtual vector<string> listarProfesores()=0;
    virtual void iniciarAltaCurso(string nickname, string nombreCurso, string descripcion, Dificultad dificultad)=0;
    virtual vector<DTIdioma> listaIdiomasProfesor(string nickname)=0;
    virtual void seleccionarIdiomaCurso(DTIdioma idioma)=0;
    virtual vector<DTCurso> listarCursosHabilitados()=0;
    virtual void seleccionarCursosPrevios(string nombre)=0;
    virtual void crearCurso()=0;
    virtual void darAltaCurso()=0;
    virtual vector<DTCurso> listarCursosNoHabilitados()=0;
    virtual void seleccionarCurso(string nombreCurso)=0;
    virtual void crearLeccion(string nombreTema, string objetivo)=0;
    virtual void altaLeccion()=0;
    virtual vector<DTLeccion> listarLeccionesOrdenado()=0;
    virtual void seleccionarLeccion(string nombreTema)=0;
    virtual void crearEjercicio(TipoEjercicio tipo, string descripcion)=0;
    virtual void agregarDatosCP(string fraseACompletar, string solucion)=0;
    virtual void agregarDatosTR(string fraseATraducir, string traduccion)=0;
    virtual void altaEjercicio()=0;
    virtual vector<DTCurso> listarCursos()=0;
    virtual void eliminarCurso(string curso)=0;
    virtual vector<DTCurso> listarCursosNoAprobados(string nickname)=0;
    virtual vector<DTEjercicio*> listarEjerciciosPendientes(string nombreCurso)=0;
    virtual void seleccionarEjercicio(DTEjercicio ejercicio)=0;
    virtual void ingresarSolucionCP(string sol)=0;
    virtual void ingresarSolucionT(string sol)=0;
    virtual bool ejercicioAprobado()=0;
    virtual DTEstCurso listarEstCurso(string nombreCurso)=0;
    virtual bool habilitarCurso()=0;
    virtual Ejercicio *getEjercicioRecordado()=0;
    virtual vector<DTCurso> listarCursosDisponibles(string nickname)=0;
    virtual void inscribirseACurso(DTCurso curso)=0;
    virtual void agregarCursoPrevio(string nombreCurso, string nombreCursoPrevio)=0;
};

#endif
