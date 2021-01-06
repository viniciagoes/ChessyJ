#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "board.h"

class Knight : public Piece{
    Board *TheBoard= Board::getBoard();

public:
    Knight(int a, int b);
    void DrawIt(QPainter *paintery);
    void Move(int a, int b);
    void InsertList(Knight *knightpiece, int a, int b);
    void ShowMovements(QPainter *paintery, int a, int b);
    QString Type();
};

#endif // KNIGHT_H
