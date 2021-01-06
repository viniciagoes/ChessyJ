#include "piece.h"

int Piece::howmany=0;

Piece::Piece(){}

//Setter e getter para x e y/ getter and setter for x and y
void Piece::setX(int a){
    x=a;
}

void Piece::setY(int a){
    y=a;
}

int Piece::getX(){
    return x;
}

int Piece::getY(){
    return y;
}

//setter e getter para marcar a peça/ setter and getter for checking piece
void Piece::SetChecked(bool test){
    if(test == true)
        Checked=true;
    else
        Checked=false;
}

bool Piece::IsChecked(){
    if(Checked==true)
        return true;
    else
        return false;
}
