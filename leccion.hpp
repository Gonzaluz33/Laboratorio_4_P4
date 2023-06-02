#include <string>
#include "tipo_ejercicio.hpp"
#include <vector>
using namespace std;

class Leccion{
private:
    int totalEjercicios;
    int cantEjerciciosHechos;
    string nombreTema;
    string objetivo;
    vector <Ejercicio*> Ejercicios;
public:
    leccion(int totalE, string nomTema, string objetivo);
    int getTotalEjercicios();
    void setTotalEjercicios(int t);
    int getCantEjerciciosHechos();
    void setCantTotalHechos(int t);
    string getNombreTema();
    void setNombreTema(string nom);
    string getObjetivo();
    void setObjetivo(string objetivo);
    void crearCP(string descripcion,string fac, string sol);
    void crearTR(string descripcion, string fat, string trad);
};
