#include <iostream>
#include "cubo.h"

class Cara;

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
    char aux7 = this->color[7];
    char aux6 = this->color[6];
    cambiar_color(7,this->color[5]);
    cambiar_color(6,this->color[4]);
    cambiar_color(5,this->color[3]);
    cambiar_color(4,this->color[2]);
    cambiar_color(3,this->color[1]);
    cambiar_color(2,this->color[0]);
    cambiar_color(1,aux7);
    cambiar_color(0,aux6);
    
}

void Cara::cambiar_color(int pos, char nuevo_color){
    //if(pos<8)
    this->color[pos]=nuevo_color;
}

Cara::Cara(char centro){
    this->color_cara=centro;
    char *array = new char[8];
    this->color = array;
    for (int i=0; i<8; i++)
        this->color[i]=centro;
    
}

//Cara::~Cara(){
//    delete this->color;
//}
/*
Cara::Cara(char centro, bool nuevo){
    this->color_cara=centro;
    char *array = new char[8];
    this->color = array;
}*/

Cubo::Cubo(){
   this->amarilla = new Cara('y');
   this->verde = new Cara('g');
   this->roja = new Cara('r');
   this->naranja = new Cara('o');
   this->azul = new Cara('b');
   this->blanca = new Cara('w');

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
    imprimir();
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

void Cubo::intercambiar(char & c1, char & c2){
    int a = c1;
    c1 = c2;
    c2 = a;
}

void Cubo::movimiento_roja(){
    EL_HACEDOR_DE_MOVIMIENTOS(verde,blanca,2,3,4,2,3,4);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,azul,2,3,4,6,7,0);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,amarilla,2,3,4,2,3,4);
}

void Cubo::movimiento_amarilla(){
    EL_HACEDOR_DE_MOVIMIENTOS(verde,roja,6,5,4,6,5,4);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,azul,6,5,4,6,5,4);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,naranja,6,5,4,6,5,4);
}

void Cubo::movimiento_verde(){
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,roja,6,5,4,0,7,6);
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,amarilla,6,5,4,2,1,0);
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,naranja,6,5,4,4,3,2);
}

void Cubo::movimiento_azul(){
    EL_HACEDOR_DE_MOVIMIENTOS(roja,blanca,4,3,2,2,1,0);
    EL_HACEDOR_DE_MOVIMIENTOS(roja,naranja,4,3,2,0,7,6);
    EL_HACEDOR_DE_MOVIMIENTOS(roja,amarilla,4,3,2,6,5,4);
}

void Cubo::movimiento_blanca(){
    EL_HACEDOR_DE_MOVIMIENTOS(verde,roja,0,1,2,0,1,2);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,azul,0,1,2,0,1,2);
    EL_HACEDOR_DE_MOVIMIENTOS(verde,naranja,0,1,2,0,1,2);
}

void Cubo::movimiento_naranja(){
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,verde,0,7,6,0,7,6);
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,amarilla,0,7,6,0,7,6);
    EL_HACEDOR_DE_MOVIMIENTOS(blanca,azul,0,7,6,4,3,2);
}

void Cubo::EL_HACEDOR_DE_MOVIMIENTOS(Cara* salida, Cara* llegada, int p1s, int p2s, int p3s, int p1l, int p2l, int p3l){
    char* array_salida = salida->devolver_array();
    char* array_llegada = llegada->devolver_array();
    intercambiar(array_salida[p1s],array_llegada[p1l]);
    intercambiar(array_salida[p2s],array_llegada[p2l]);
    intercambiar(array_salida[p3s],array_llegada[p3l]);
}

void Cubo::imprimir(){
    cout << "    " ; blanca->prnt(0); blanca->prnt(1); blanca->prnt(2); cout<<endl;
    cout << "    " ; blanca->prnt(7); blanca->prnt(8); blanca->prnt(3); cout<<endl;
    cout << "    " ; blanca->prnt(6); blanca->prnt(5); blanca->prnt(4); cout<<endl;

    naranja->prnt(0); naranja->prnt(1); naranja->prnt(2); cout << " ";
    verde->prnt(0); verde->prnt(1); verde->prnt(2); cout << " ";
    roja->prnt(0); roja->prnt(1); roja->prnt(2); cout << " ";
    azul->prnt(0); azul->prnt(1); azul->prnt(2); cout<<endl;

    naranja->prnt(7); naranja->prnt(8); naranja->prnt(3); cout << " ";
    verde->prnt(7); verde->prnt(8); verde->prnt(3); cout << " ";
    roja->prnt(7); roja->prnt(8); roja->prnt(3); cout << " ";
    azul->prnt(7); azul->prnt(8); azul->prnt(3); cout<<endl;

    naranja->prnt(6); naranja->prnt(5); naranja->prnt(4); cout << " ";
    verde->prnt(6); verde->prnt(5); verde->prnt(4); cout << " ";
    roja->prnt(6); roja->prnt(5); roja->prnt(4); cout << " ";
    azul->prnt(6); azul->prnt(5); azul->prnt(4); cout<<endl;

    cout << "    " ; amarilla->prnt(0); amarilla->prnt(1); amarilla->prnt(2); cout<<endl;
    cout << "    " ; amarilla->prnt(7); amarilla->prnt(8); amarilla->prnt(3); cout<<endl;
    cout << "    " ; amarilla->prnt(6); amarilla->prnt(5); amarilla->prnt(4); cout<<endl;

}

void Cara::prnt(int pos){
    char a;
    if (pos==8)
        a = this->color_cara;
    else
        a = color[pos];
    if(a=='b')
        cout <<"\033[34;40mB\033[37;40m";
    if(a=='r')
        cout <<"\033[31;40mR\033[37;40m";
    if(a=='o')
        cout <<"\033[38;5;202mO\033[37;40m";
    if(a=='y')
        cout <<"\033[38;5;11mY\033[37;40m";
    if(a=='w')
        cout <<"\033[37;40mW\033[37;40m";
    if(a=='g')
        cout <<"\033[32;40mG\033[37;40m";
}