#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QtWidgets>
#include <QDialog>

#include "board.h"

class Mwindow : public QMainWindow{
    Q_OBJECT
    QString Type;
    int Xposition;
    int Yposition;

public:
    explicit Mwindow(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    void ErrorDialog();
signals:


public slots:
    void InsertPiecesWindow();
    void RemovePiecesWindow();
    void Save();
    void Open();
    void New();

private slots:

protected:

};

#endif // MWINDOW_H
