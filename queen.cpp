#include "queen.h"

//Construtor para o obj/ constructor for object
Queen::Queen(int a, int b){
    setX(a);
    setY(b);
}

//Metodo para desenha-lo/ Method for drawing it
void Queen::DrawIt(QPainter *paintery){
    QPixmap Queen("./dama.png");
    paintery->drawPixmap(15+65*x,40+65*y,50,50, Queen);
}

//Metodo para mover/ Method for moving
void Queen::Move(int a, int b){
    this->setX(a);
    this->setY(b);
}

//Metodo para retornar tipo/ Method for returning type
QString Queen::Type(){
    QString Type ="Queen";
    return Type;
}

//Metodo para inserir na lista/ method for inserting in the pieces list
void Queen::InsertList(Queen *queenpiece, int a, int b){
    if(TheBoard->HasPiece(a,b)==false){
        TheBoard->PiecesList.push_back(queenpiece);
        howmany++;
    }else
        throw "Erro";
}

//Metodo para mostrar possiveis movimentos no tabuleiro/ Method for showing possible movements on board
void Queen::ShowMovements(QPainter *paintery, int a, int b){}
