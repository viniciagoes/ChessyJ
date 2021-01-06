#include "board.h"
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <Qt>

Board::Board(QWidget *parent) : QWidget(parent){
}

//getter para o singleton/ getter for singleton
Board *Board::getBoard(){
    if(chessboard == nullptr)
        chessboard = new Board();
    return chessboard;
}

void Board::paintthisshit(QPainter *paintery, QPen pen, QBrush brush){
    //Setando a caneta e cor ao pintor/ Setting Pen and color for painter
        paintery->setPen(pen);
        QColor PastelP, PastelB;
        PastelP.setRgb(255,209,220);
        PastelB.setRgb(174,198,207);

        int i,j;
        //Setando cor e tipo de padrao/ setting color and pattern
        pen.setStyle(Qt::SolidLine);
        pen.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if((i%2 == 0 and j%2 == 0) or (i%2 == 1 and j%2 == 1)){
                    //(1)-> Setando cor e pincel ao Pintor/ Setting color and Brush for painter
                    brush.setColor(PastelB);
                    paintery->setBrush(brush);
                }
                else if((i%2 == 1 and j%2 == 0) or (i%2 == 0 and j%2 == 1)){
                    //(1)
                    brush.setColor(PastelP);
                    paintery->setBrush(brush);
                }
                //Desenhando retangulo por retangulo/ Drawing square per Square
                paintery->drawRect(10+65*i,35+65*j,65,65);
            }
        }
}

//Metodo para confirmar se ha peça naquela posicao/ Method for checking if there is a piece in that position
bool Board::HasPiece(int a, int b){
    std::list<Piece*>::iterator Mi;
    for(Mi=chessboard->PiecesList.begin(); Mi!=chessboard->PiecesList.end(); Mi++){
        if((*Mi)->getX()==a and (*Mi)->getY()==b)
            return true;
    }
    return false;
}

//Metodo para tentar remover uma peça da lista de peças/ Method for trying to remove a piece from the list
void Board::RemoveList(int a, int b){
    if(chessboard->HasPiece(a,b)==true){
        std::list<Piece*>::iterator Mi;
        for(Mi=chessboard->PiecesList.begin(); Mi!=chessboard->PiecesList.end(); Mi++){
            if(((*Mi)->getX()==a) and ((*Mi)->getY() == b)){
                chessboard->PiecesList.remove((*Mi));
                Piece::howmany--;
                break;
                }
            }
        }
    else
        throw "Erro";
}
