#ifndef DT_EST_CURSO_HPP
#define DT_EST_CURSO_HPP

#include "dt_curso.hpp"

class DTEstCurso {
public:
    DTEstCurso(int promedioAvance, DTCurso informacion);
    ~DTEstCurso();
    int getPromedioAvance();
    DTCurso getInformacion();
private:
    int promedioAvance;
    DTCurso informacion;
    friend ostream& operator<<(ostream& os, DTEstCurso estCurso);
};

#endif
