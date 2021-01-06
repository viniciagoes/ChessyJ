#include <QApplication>
#include "mwindow.h"

int main(int argc, char **argv){
    QApplication Chess(argc, argv);
    Mwindow w;
    w.show();
    return Chess.exec();
}
