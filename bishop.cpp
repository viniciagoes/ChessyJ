#include "bishop.h"

//Construtor para obj/  constructor for object
Bishop::Bishop(int a, int b){
    setX(a);
    setY(b);
}

//Metodo para desenha-lo/ Method for drawing it
void Bishop::DrawIt(QPainter *paintery){
    QPixmap Bishop("./bispo.png");
    paintery->drawPixmap(15+65*x,40+65*y,50,50, Bishop);
}

//Metodo para mover/method for moving
void Bishop::Move(int a, int b){
    setX(a);
    setY(b);
}

//Metodo para inserir na lista/ method for inserting in the pieces list
void Bishop::InsertList(Bishop *bishoppiece, int a, int b){
    if(TheBoard->HasPiece(a,b)==false){
        TheBoard->PiecesList.push_back(bishoppiece);
        howmany++;
    }else
        throw "Erro";
}

//Metodo para retornar tipo/ Method for returning type
QString Bishop::Type(){
    QString Type = "Bishop";
    return Type;
}

//Metodo para mostrar possiveis movimentos no tabuleiro/ Method for showing possible movements on board
void Bishop::ShowMovements(QPainter *paintery, int a, int b){
    QColor Marked;
    QBrush Brush;
    QPen pen;
    Marked.setRgb(3, 252, 78);
    Marked.setAlpha(200);
    Brush.setColor(Marked);
    Brush.setStyle(Qt::SolidPattern);
    paintery->setBrush(Brush);
    paintery->setPen(pen);

    //Diagonal pra cima, a direita
    for(int i=1;i<=7;i++){
        paintery->drawRect(10+65*(a+i),35+65*(b-i),65,65);
        if((a>7)or(b<0))
            break;
    }
    //Diagonal pra baixo, a direita
    for(int i=1;i<=7;i++){
        paintery->drawRect(10+65*(a+i),35+65*(b+i),65,65);
        if((a>7)or(b>7))
            break;
    }
    //Diagonal pra cima, a esquerda
    for(int i=1;i<=7;i++){
        paintery->drawRect(10+65*(a-i),35+65*(b-i),65,65);
        if((a<0)or(b<0))
            break;
    }
    //Diagonal pra baixo, a esquerda
    for(int i=1;i<=7;i++){
        paintery->drawRect(10+65*(a-i),35+65*(b+i),65,65);
        if((a<0)or(b<7))
            break;
    }
}
