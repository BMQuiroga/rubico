#include <iostream>

class Cara{
    private:
        char color_cara;
        char * color;
    public:
        Cara(char color);
        Cara(char color, bool nuevo);
        //~Cara();
        void cambiar_color(int pos, char nuevo_color);
        void rotar();
        char devolver_color(int pos);
        bool resuelto();
        char* devolver_array();
        void prnt(int pos);
};

