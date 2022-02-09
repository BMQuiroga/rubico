class Cubo{
    private:
        Cara *roja;
        Cara *azul;
        Cara *verde;
        Cara *blanca;
        Cara *amarilla;
        Cara *naranja;
    public:
        Cubo();
        bool resuelto();
        void menu_mover();
        void mover(char cara);
        void movimiento_roja();
        void movimiento_amarilla();
        void movimiento_azul();
        void movimiento_verde();
        void movimiento_naranja();
        void movimiento_blanca();
        void EL_HACEDOR_DE_MOVIMIENTOS(Cara* salida, Cara* llegada, int p1s, int p2s, int p3s, int p1l, int p2l, int p3l);
        void intercambiar(char c1, char c2);
        void imprimir();



};

class Cara{
    private:
        char color_cara;
        char * color;
    public:
        Cara(char color);
        void cambiar_color(int pos, char color);
        void rotar();
        char devolver_color(int pos);
        bool resuelto();
        char* devolver_array();
        void prnt(int pos);



};

