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
};
