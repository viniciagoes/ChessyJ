#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "board.h"

class Bishop : public Piece{
    Board *TheBoard= Board::getBoard();

public:
    Bishop(int a, int b);
    void DrawIt(QPainter *paintery);
    void Move(int a, int b);
    void InsertList(Bishop *bishoppiece, int a, int b);
    void ShowMovements(QPainter *paintery, int a, int b);
    QString Type();
};

#endif // BISHOP_H
