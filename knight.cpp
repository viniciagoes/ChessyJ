#include "knight.h"

//Construtor para obj/  constructor for object
Knight::Knight(int a, int b){
    setX(a);
    setY(b);
}

//Metodo para desenha-lo/ Method for drawing it
void Knight::DrawIt(QPainter *paintery){
    QPixmap Knight("./cavalo.png");
    paintery->drawPixmap(15+65*x,40+65*y,50,50, Knight);
}

//Metodo para mover/method for moving
void Knight::Move(int a, int b){
    std::list<Piece*>::iterator Mi;

    if((a<=7)and(b<=7)){
        if((Knight::x+2==a)and(Knight::y+1==b)){
        //direita 2, pra baixo 1
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a<=7)and(b<=7)){
        if((Knight::x+1==a)and(Knight::y+2==b)){
        //direita 1, pra baixo 2
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a>=0)and(b<=7)){
        if((Knight::x-2==a) and (Knight::y+1==b)){
        //esquerda 2, pra baixo 1
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a>=0)and(b<=7)){
        if((Knight::x-1==a)and(Knight::y+2==b)){
        //esquerda 1, pra baixo 2
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a<=7)and(b>=0)){
        if((Knight::x+2==a)and(Knight::y-1==b)){
        //direita 2, pra cima 1
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a<=7)and(b>=0)){
        if((Knight::x+1==a)and(Knight::y-2==b)){
        //direita 1, pra cima 2
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a>=0)and(b>=0)){
        if((Knight::x-2==a)and(Knight::y-1==b)){
        //esquerda 2, pra cima 1
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
    if((a>=0)and(b>=0)){
        if((Knight::x-1==a)and(Knight::y-2==b)){
        //esquerda 1, pra cima 2
            for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
                if((*Mi)->getX()==a and (*Mi)->getY()==b){
                    TheBoard->PiecesList.erase(Mi);
                    break;
            }}
            setX(a);
            setY(b);
        }
    }
}

//Metodo para inserir na lista/ method for inserting in the pieces list
void Knight::InsertList(Knight *knightpiece, int a, int b){
    if(TheBoard->HasPiece(a,b)==false){
        TheBoard->PiecesList.push_back(knightpiece);
        howmany++;
    }else
        throw "Erro";
}

//Metodo para retornar tipo/ Method for returning type
QString Knight::Type(){
    QString Type = "Knight";
    return Type;
}

//Metodo para mostrar possiveis movimentos no tabuleiro/ Method for showing possible movements on board
void Knight::ShowMovements(QPainter *paintery, int a, int b){
    QColor Marked;
    QBrush Brush;
    QPen pen;
    Marked.setRgb(3, 252, 78);
    Marked.setAlpha(200);
    Brush.setColor(Marked);
    Brush.setStyle(Qt::SolidPattern);
    paintery->setBrush(Brush);
    paintery->setPen(pen);

    if((a+2<=7)and(b+1<=7))
    //direita 2, pra baixo 1
    paintery->drawRect(10+65*(a+2),35+65*(b+1),65,65);

    if((a+1<=7)and(b+2<=7))
    //direita 1, pra baixo 2
    paintery->drawRect(10+65*(a+1),35+65*(b+2),65,65);

    if((a-2>=0)and(b+1<=7))
    //esquerda 2, pra baixo 1
    paintery->drawRect(10+65*(a-2),35+65*(b+1),65,65);

    if((a-1>=0)and(b+2<=7))
    //esquerda 1, pra baixo 2
    paintery->drawRect(10+65*(a-1),35+65*(b+2),65,65);

    if((a+2<=7)and(b-1>=0))
    //direita 2, pra cima 1
    paintery->drawRect(10+65*(a+2),35+65*(b-1),65,65);

    if((a+1<=7)and(b-2>=0))
    //direita 1, pra cima 2
    paintery->drawRect(10+65*(a+1),35+65*(b-2),65,65);

    if((a-2>=0)and(b-1>=0))
    //esquerda 2, pra cima 1
    paintery->drawRect(10+65*(a-2),35+65*(b-1),65,65);

    if((a-1>=0)and(b-2>=0))
    //esquerda 1, pra cima 2
    paintery->drawRect(10+65*(a-1),35+65*(b-2),65,65);


}

