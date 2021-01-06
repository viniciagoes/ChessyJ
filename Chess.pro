TEMPLATE = app
TARGET = Chess

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Main.cpp \
    bishop.cpp \
    board.cpp \
    knight.cpp \
    mwindow.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp

HEADERS += \
    bishop.h \
    board.h \
    knight.h \
    mwindow.h \
    piece.h \
    queen.h \
    rook.h \

