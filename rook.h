#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "board.h"

class Rook : public Piece
{
    Board *TheBoard= Board::getBoard();

public:
    Rook(int a, int b);
    void DrawIt(QPainter *paintery);
    void Move(int a, int b);
    void InsertList(Rook *rookpiece, int a, int b);
    void ShowMovements(QPainter *paintery, int a, int b);
    QString Type();
};

#endif // ROOK_H
