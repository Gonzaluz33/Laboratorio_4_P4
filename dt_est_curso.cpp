#include "dt_est_curso.hpp"

DTEstCurso::DTEstCurso(int promedioAvance, DTCurso informacion):
    promedioAvance(promedioAvance),
    informacion(informacion)
{
}

// no se si hay que destruir los elementos del vector o se destruye solo
DTEstCurso::~DTEstCurso() {

}

int DTEstCurso::getPromedioAvance() {
    return promedioAvance;
}

DTCurso DTEstCurso::getInformacion() {
    return informacion;
}

ostream& operator<<(ostream& os, DTEstCurso estCurso){ 
    DTCurso curso = estCurso.getInformacion();
    os << "Nombre del curso: " + curso.getNombre() + "Avance Correspondiente: " + char(estCurso.getPromedioAvance());
    return os;
}
