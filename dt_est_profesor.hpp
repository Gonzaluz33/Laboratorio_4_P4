#ifndef DT_EST_PROFESOR_HPP
#define DT_EST_PROFESOR_HPP

#include "dt_curso.hpp"

class DTEstProfesor {
    private:
        DTCurso curso;
        int promedio_avance;
    public:
        DTEstProfesor(DTCurso,int);
        ~DTEstProfesor();
        DTCurso getCurso();
        int getPromedioAvance();
        friend ostream& operator<<(ostream& os, DTEstProfesor estProfesor);
};

#endif
