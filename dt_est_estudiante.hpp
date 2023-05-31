#ifndef dt_est_estudiante
#define dt_est_estudiante
#include "dt_curso"

class DTEstEstudiante{
    private:
        DTCurso curso_;
        int avance;
    public:
        DTEstEstudiante(DTCurso,int);
        ~DTEstEstudiante();
        DTCurso getDTCurso();
        int getAvance();
};
