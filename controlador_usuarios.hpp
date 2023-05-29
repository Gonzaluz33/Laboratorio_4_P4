class ControladorUsuarios {
    private: 
        static ControladorUsuarios * instancia;
        ControladorUsuarios();
    public:
    static ControladorUsuarios * getInstance();
};