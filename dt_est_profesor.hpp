#ifndef dt_est_profesor
#define dt_est_profesor
#include "dt_curso.hpp"

class DTEstProfesor {
    private:
        DTCurso curso;
        int promedio_avance;
    public:
        DTCurso getCurso();
        int getPromedioAvance();
        DTEstProfesor(DTCurso,int);
};
