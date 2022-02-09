#include <iostream>
#include "main.h"

using namespace std;

int main(){
    Cubo cubo;
    //while(!cubo.resuelto())
    while (1)  
        cubo.menu_mover();


    return 0;
}

bool Cubo::resuelto(){
    return (this->roja->resuelto() &&
            this->amarilla->resuelto() &&
            this->naranja->resuelto() &&
            this->azul->resuelto() &&
            this->verde->resuelto() &&
            this->blanca->resuelto());
}

char Cara::devolver_color(int pos){
    return this->color[pos];
}

void Cara::rotar(){
    Cara * aux;
    for (int i=0; i<8 ;i++){
        if(i>6)
            aux->cambiar_color(i+2,this->color[i]);
        if(i==7)
            aux->cambiar_color(1,this->color[7]);
        if(i==6)
            aux->cambiar_color(0,this->color[6]);
    }
    this->color=aux->devolver_array();
}

Cara::Cara(char color){
    this->color_cara=color;
    char array[8];
    this->color=array;
    for (int i=0; i<8; i++)
        this->color[i]=color;
}

Cubo::Cubo(){
    Cara amarilla('y');
    this->amarilla=&amarilla;
    Cara roja('r');
    this->roja=&roja;
    Cara naranja('o');
    this->naranja=&naranja;
    Cara blanca('w');
    this->blanca=&blanca;
    Cara azul('b');
    this->azul=&azul;
    Cara verde('g');
    this->verde=&verde;
}

char* Cara::devolver_array(){
    return this->color;
}

bool Cara::resuelto(){
    for(int i=0; i<8; i++){
        if(color[i]!=color_cara)
            return false;
    }
    return true;
}

void Cubo::menu_mover(){
    int vueltas=1;
    cout << "inserte el caracter del color de la cara" <<endl;
    char cara;
    cin>>cara;
    cout << "inserte el sentido (+ o -)" <<endl;
    char sentido;
    cin>>sentido;
    if(sentido=='-')
        vueltas=3;
    for(int i=0; i<vueltas; i++)
        mover(cara);
}

void Cubo::mover(char cara){
    if(cara=='r'){
        roja->rotar();
        movimiento_roja();
    }
    if(cara=='y'){
        amarilla->rotar();
        movimiento_amarilla();
    }
    if(cara=='w'){
        blanca->rotar();
        movimiento_blanca();
    }
    if(cara=='b'){
        azul->rotar();
        movimiento_azul();
    }
    if(cara=='o'){
        naranja->rotar();
        movimiento_naranja();
    }
    if(cara=='g'){
        verde->rotar();
        movimiento_verde();
    }
}

void Cubo::intercambiar(char c1, char c2){
    int a = c1;
    c1 = c2;
    c2 = a;
}

void Cubo::movimiento_roja(){
    EL_HACEDOR_DE_MOVIMIENTOS(verde,blanca,2,3,4,2,3,4);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,azul,2,3,4,6,7,0);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,amarilla,2,3,4,2,3,4);
}

void Cubo::EL_HACEDOR_DE_MOVIMIENTOS(Cara* salida, Cara* llegada, int p1s, int p2s, int p3s, int p1l, int p2l, int p3l){
    char* array_salida = salida->devolver_array();
    char* array_llegada = llegada->devolver_array();
    intercambiar(array_salida[p1s],array_llegada[p1l]);
    intercambiar(array_salida[p2s],array_llegada[p2l]);
    intercambiar(array_salida[p3s],array_llegada[p3l]);
}

void Cubo::imprimir(){
    cout << blanca->prnt(0) << blanca->prnt(1) << blanca->prnt(2) << endl;
    cout << "    " << blanca->prnt(7) << 'w' << blanca->prnt(3) << endl;
    cout << "    " << blanca->prnt(6) << blanca->prnt(5) << blanca->prnt(4) << endl;











}