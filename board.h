#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <list>
#include "piece.h"

class Board : public QWidget{
    Q_OBJECT

    //Definindo singleton/ defining singleton
    static Board *chessboard;

    explicit Board(QWidget *parent = nullptr);
    Board(const Board &n);
    Board operator=(Board n);

public:
    virtual void paintthisshit(QPainter *paintery, QPen pen, QBrush brush);
    static Board *getBoard();
    std::list<Piece*> PiecesList;
    bool HasPiece(int a, int b);
    void RemoveList(int a, int b);

signals:

public slots:

};

#endif // BOARD_H
