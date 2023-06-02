
class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        DTFecha(int,int,int);
        ~DTFecha();
         bool operator==(const DTFecha& other) const {
        return (dia == other.dia && mes == other.mes && anio == other.anio);
        };
        int getDia();
        int getMes();
        int getAnio();
};

