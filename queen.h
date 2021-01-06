#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "board.h"

class Queen : public Piece{
    Board *TheBoard= Board::getBoard();

public:
    Queen(int a, int b);
    void DrawIt(QPainter *paintery);
    void Move(int a, int b);
    void InsertList(Queen *queenpiece, int a, int b);
    QString Type();
    void ShowMovements(QPainter *paintery, int a, int b);
};

#endif // QUEEN_H
