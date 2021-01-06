#ifndef PIECE_H
#define PIECE_H
#include <QPainter>
#include <QString>

class Piece{
protected:
    int x;
    int y;
    bool Checked;

public:
    static int howmany;
    Piece();
    virtual void Move(int x, int y)=0;
    virtual void DrawIt(QPainter *paintery)=0;
    virtual void ShowMovements(QPainter *paintery, int a, int b)=0;
    virtual QString Type()=0;
    bool IsChecked();
    void SetChecked(bool test);
    void setX(int a);
    void setY(int a);
    int getX();
    int getY();
};

#endif // PIECE_H
