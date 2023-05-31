#ifndef CONTROLADOR_CURSOS_HPP
#define CONTROLADOR_CURSOS_HPP

#include <string>
#include <vector>
#include <map>
#include "icontrolador_cursos.hpp"

class ControladorCursos : public IControladorCursos {
public:
    ControladorCursos();
    ~ControladorCursos();

    vector<string> listarProfesores();
    void iniciarAltaCurso(string nickname, string nombreCurso, string descripcion, Dificultad dificultad);
    vector<DTIdioma> listaIdiomasProfesor(string nickname);
    void seleccionarIdiomaCurso(DTIdioma idioma);
    vector<DTCurso> listarCursosHabilitados();
    void seleccionarCursosPrevios(string nombre);
    void crearCurso();
    void darAltaCurso();
    vector<DTCurso> listarCursosNoHabilitados();
    void seleccionarCurso(string nombreCurso);
    void crearLeccion(string nombreTema, string objetivo);
    void altaLeccion();
    vector<DTLeccion> listarLeccionesOrdenado();
    void seleccionarLeccion(string nombreTema);
    void crearEjercicio(TipoEjercicio tipo, string descripcion);
    void agregarDatosCP(string fraseACompletar, string solucion);
    void agregarDatosTR(string fraseATraducir, string traduccion);
    void altaEjercicio();
    vector<DTCurso> listarCursos();
    void eliminarCurso(string curso);
    vector<DTCurso> listarCursosNoAprobados(string nickname);
    vector<DTEjercicio> listarEjerciciosPendientes(string nombreCurso);
    void seleccionarEjercicio(DTEjercicio ejercicio);
    void ingresarSolucionCP(string sol);
    void ingresarSolucionT(string sol);
    bool ejercicioAprobado();
    DTEstCurso listarEstCurso(string nombreCurso);
private:
    string nickname_recordado, nombreCurso_recordado, descripcion_recordado;
    Dificultad dificultad_recordado;
    DTIdioma idioma_recordado;
    map<string, Curso *> cursosHabilitados, cursosNoHabilitados;
    vector<Curso *> cursos; // Parece que esto no se usa
    vector<string> cursosPrevios;
    Curso *curso_recordado;
};

#endif
