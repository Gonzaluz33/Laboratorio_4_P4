class DTCurso{};

class DTEstEstudiante{
    private:
        DTCurso curso_;
        int avance;
    public:
        DTEstEstudiante(DTCurso,int);
        DTCurso getDTCurso();
        int getAvance();
};