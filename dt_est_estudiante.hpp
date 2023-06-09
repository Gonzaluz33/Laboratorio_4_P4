#ifndef DT_EST_ESTUDIANTE_HPP
#define DT_EST_ESTUDIANTE_HPP

#include "dt_curso.hpp"

class DTEstEstudiante{
    private:
        DTCurso curso_;
        int avance;
    public:
        DTEstEstudiante(DTCurso,int);
        ~DTEstEstudiante();
        DTCurso getDTCurso();
        int getAvance();
        friend ostream& operator<<(ostream& os, DTEstEstudiante estEstudiante);
};

#endif
