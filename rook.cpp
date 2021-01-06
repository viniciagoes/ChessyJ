#include "rook.h"
#include "piece.h"
#include <QPixmap>
#include <QPainter>
#include <iostream>

//Construtor para o obj/ constructor for object
Rook::Rook(int a, int b){
    x=a;
    y=b;
}

//Metodo para desenha-lo/ Method for drawing it
void Rook::DrawIt(QPainter *paintery){
    QPixmap Rook("./torre.png");
    paintery->drawPixmap(15+65*x,40+65*y,50,50, Rook);
}

//Metodo para mover/ Method for moving
void Rook::Move(int a, int b){
    int MinXL=0;
    int MinXR=7;
    int MinYU=0;
    int MinYD=7;
    std::list<Piece*>::iterator Mi;
    for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
        if((*Mi)->getX()==a and (*Mi)->getY()<b){
            if((*Mi)->getY()>MinYU)
                MinYU=(*Mi)->getY();
        }
        if((*Mi)->getX()==a and (*Mi)->getY()>b){
            if((*Mi)->getY()<MinYD)
                MinYD=(*Mi)->getY();
        }
        if((*Mi)->getX()<a and (*Mi)->getY()==b){
            if((*Mi)->getX()>MinXL)
                MinXL=(*Mi)->getX();
        }
        if((*Mi)->getX()>a and (*Mi)->getY()==b){
            if((*Mi)->getX()<MinXR)
                MinXR=(*Mi)->getX();
        }
        if((*Mi)->IsChecked()==true){
            setX((*Mi)->getX());
            setY((*Mi)->getY());
        }
    }

    if((MinXL<=a and MinXR>=a and Rook::y==b) or (MinYU<=b and MinYD>=b and Rook::x==a)){
        for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
            if((*Mi)->getX()==a and (*Mi)->getY()==b){
                TheBoard->PiecesList.erase(Mi);
                break;
            }
        }
        setX(a);
        setY(b);
    }
    else
        throw "Erro";
}

//Metodo para inserir na lista/ method for inserting in the pieces list
void Rook::InsertList(Rook *rookpiece, int a, int b){
    if(TheBoard->HasPiece(a,b)==false){
        TheBoard->PiecesList.push_back(rookpiece);
        howmany++;
    }
    else
        throw "Erro";
}

//Metodo para retornar tipo/ Method for returning type
QString Rook::Type(){
    QString Type ="Rook";
    return Type;
}

//Metodo para mostrar possiveis movimentos no tabuleiro/ Method for showing possible movements on board
void Rook::ShowMovements(QPainter *paintery, int a, int b){
    int MinXL=0;
    int MinXR=7;
    int MinYD=7;
    int MinYU=0;
    QColor Marked;
    QBrush Brush;
    QPen pen;
    Marked.setRgb(3, 252, 78);
    Marked.setAlpha(200);
    Brush.setColor(Marked);
    Brush.setStyle(Qt::SolidPattern);
    paintery->setBrush(Brush);
    paintery->setPen(pen);
    Board *TheBoard= Board::getBoard();
    std::list<Piece*>::iterator Mi;
    for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
            if((*Mi)->getX()==a and (*Mi)->getY()<b){
                if((*Mi)->getY()>MinYU)
                    MinYU=(*Mi)->getY();
            }
            if((*Mi)->getX()==a and (*Mi)->getY()>b){
                if((*Mi)->getY()<MinYD)
                    MinYD=(*Mi)->getY();
            }
            if((*Mi)->getX()<a and (*Mi)->getY()==b){
                if((*Mi)->getX()>MinXL)
                    MinXL=(*Mi)->getX();
            }
            if((*Mi)->getX()>a and (*Mi)->getY()==b){
                if((*Mi)->getX()<MinXR)
                    MinXR=(*Mi)->getX();
            }
    }
    for(int i=MinYU; i<=MinYD; i++){
        if(i!=b)
        paintery->drawRect(10+65*a,35+65*i,65,65);
    }
    for(int j=MinXL; j<=MinXR; j++){
        if(j!=a)
        paintery->drawRect(10+65*j,35+65*b,65,65);
    }
}
