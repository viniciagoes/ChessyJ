#include <QMenu>
#include <QMenuBar>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QAction>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QFileDialog>
#include <QMouseEvent>

#include <list>

#include "mwindow.h"
#include "board.h"
#include "piece.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "bishop.h"
#include "piece.h"

Board *Board::chessboard = nullptr;

//construtor da janela/ constructor for window
Mwindow::Mwindow(QWidget *parent) : QMainWindow(parent){

        //ajustando posição e tamanho/ setting position and size
        setGeometry(100,100,545,565);

        //barra de menus/ menubar
        QMenuBar *MenuBar = new QMenuBar(this);

        //menus clickáveis/ clickable menu
        QMenu *File = new QMenu("&File", this);
        QMenu *Game = new QMenu("&Game", this);

        //adicionando os menus a barra/ adding menus to menubar
        MenuBar->addMenu(File);
        MenuBar->addMenu(Game);

        //declarando opções de menu/ declaring options for menus
        QAction *newf = new QAction("New", this);
        QAction *open = new QAction("Open", this);
        QAction *save = new QAction("Save", this);
        QAction *Insert = new QAction("Insert", this);
        QAction *Remove = new QAction("Remove", this);
        QAction *Exit = new QAction("Exit", this);

        //adicionando opeções ao menu/ adding options for menu
        File->addAction(newf);
        File->addAction(open);
        File->addAction(save);
        Game->addAction(Insert);
        Game->addAction(Remove);
        Game->addAction(Exit);

        //setando a barra/ setting bar(visible and attaching to window)
        this->setMenuBar(MenuBar);
        MenuBar->setVisible(true);

        //conectando botões e menus/connecting buttons and menus
        connect(Exit, &QAction::triggered, this, &Mwindow::close);
        connect(save, &QAction::triggered, this, &Mwindow::Save);
        connect(newf, &QAction::triggered, this, &Mwindow::New);
        connect(open, &QAction::triggered, this, &Mwindow::Open);
        connect(Insert, &QAction::triggered, this, &Mwindow::InsertPiecesWindow);
        connect(Remove, &QAction::triggered, this, &Mwindow::RemovePiecesWindow);
}

//PaintEvent para o tabuleiro ser printado na janela/ Priting the chessboard on the window
void Mwindow::paintEvent (QPaintEvent *event){

    Board *TheBoard = Board::getBoard();
    QMainWindow::paintEvent(event);

    //Pintor para as formas/ Painter for all forms
    QPainter paintery(this);

    //Caneta para pintar o contorno/ Pen for outlines
    QPen pen;

    //Pincel para preencher as formas/ Brush for filling the forms
    QBrush brush;

    //Método para pintar o tabuleiro/ Method for painting the board
    TheBoard->paintthisshit(&paintery, pen, brush);

    std::list<Piece*>::iterator Mi;
    //desenhando as peças e confirmando se há peças se movimentando(mover)/ drawing pieces and chcking if a piece is moving
    for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
        (*Mi)->DrawIt(&paintery);
        if((*Mi)->IsChecked()==true){
            (*Mi)->ShowMovements(&paintery, (*Mi)->getX(),(*Mi)->getY());
    }}
}

//Janela para irerir peças/ Window for inserting pieces
void Mwindow::InsertPiecesWindow(){

    //Declarando elementos  da janela/ Declaring window elements
    QDialog *newdial=new QDialog;
    QLabel *Typeofpiece = new QLabel("&Piece");
    QComboBox *WhichPiece = new QComboBox();
    QLabel *Labelxpos = new QLabel("&X Position");
    QSpinBox *xbox = new QSpinBox();
    QLabel *Labelypos = new QLabel("&Y Position");
    QSpinBox *ybox = new QSpinBox();
    QPushButton *ok = new QPushButton("&OK");
    QPushButton *cancel = new QPushButton("&Cancel");
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    QGridLayout *layout = new QGridLayout();
    QStandardItemModel *model;
    QStringListModel *typemodel;

    //Definindo opeções para a ComboBox/ Defining ComboBox options
    QStringList Pieces;
    Pieces << ("Rook") << ("Knight") << ("Bishop") << ("Queen");
    typemodel = new QStringListModel(Pieces, this);

    //Definindo comportamento/ Defining behavior
    model = new QStandardItemModel(5,3,this);

    xbox->setMaximum(7);
    ybox->setMaximum(7);

    Typeofpiece->setBuddy(WhichPiece);
    Labelxpos->setBuddy(xbox);
    Labelypos->setBuddy(ybox);
    WhichPiece->setModel(typemodel);

    mapper->setModel(model);
    mapper->addMapping(WhichPiece,0,"currentIndex");
    mapper->addMapping(xbox,1);
    mapper->addMapping(ybox,2);

    connect(ok,&QAbstractButton::clicked, newdial, &QDialog::accept);
    connect(cancel, &QAbstractButton::clicked, newdial, &QDialog::reject);

    layout->addWidget(Typeofpiece, 0,0,1,1);
    layout->addWidget(WhichPiece,0,1,1,1);
    layout->addWidget(Labelxpos,1,0,1,1);
    layout->addWidget(xbox,1,1,1,1);
    layout->addWidget(Labelypos,2,0,1,1);
    layout->addWidget(ybox,2,1,1,1);
    layout->addWidget(ok,0,2,1,1);
    layout->addWidget(cancel,1,2,1,1);

    newdial->setLayout(layout);
    newdial->setWindowTitle("Insert Piece");
    mapper->toFirst();

    //Confirmando qual peça deve ser inserida/ Checking which piece should be inserted
    if(newdial->exec() == QDialog::Accepted){
        Xposition=xbox->value();
        Yposition=ybox->value();
        Type=WhichPiece->currentText();

        if(Type == "Rook"){
            Rook* rookpiece= new Rook(Xposition,Yposition);
            try{
            rookpiece->InsertList(rookpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }

        else if(Type == "Knight"){
            Knight* knightpiece= new Knight(Xposition,Yposition);
            try{
            knightpiece->InsertList(knightpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
        else if(Type == "Bishop"){
            Bishop* bishoppiece= new Bishop(Xposition, Yposition);
            try{
            bishoppiece->InsertList(bishoppiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
        else if(Type == "Queen"){
            Queen* queenpiece= new Queen(Xposition, Yposition);
            try{
            queenpiece->InsertList(queenpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
    }
    else if(cancel->isChecked()){
        newdial->close();
    }
    this->update();
}

//Janela para remover peças/ Window for removing pieces
void Mwindow::RemovePiecesWindow(){

    //Declarando elementos  da janela/ Declaring window elements
    QDialog *newdial= new QDialog;
    QLabel *Labelxpos = new QLabel("&X Position");
    QSpinBox *xbox = new QSpinBox();
    QLabel *Labelypos = new QLabel("&Y Position");
    QSpinBox *ybox = new QSpinBox();
    QPushButton *ok = new QPushButton("&OK");
    QPushButton *cancel = new QPushButton("&Cancel");
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    QGridLayout *layout = new QGridLayout();
    QStandardItemModel *model;

    //Definindo comportamento/ Defining behavior
    model = new QStandardItemModel(5,3,this);

    xbox->setMaximum(7);
    ybox->setMaximum(7);

    Labelxpos->setBuddy(xbox);
    Labelypos->setBuddy(ybox);

    mapper->setModel(model);
    mapper->addMapping(xbox,1);
    mapper->addMapping(ybox,2);

    connect(ok,&QAbstractButton::clicked, newdial, &QDialog::accept);
    connect(cancel, &QAbstractButton::clicked, newdial, &QDialog::reject);

    layout->addWidget(Labelxpos,0,0,1,1);
    layout->addWidget(xbox,0,1,1,1);
    layout->addWidget(Labelypos,1,0,1,1);
    layout->addWidget(ybox,1,1,1,1);
    layout->addWidget(ok,0,2,1,1);
    layout->addWidget(cancel,1,2,1,1);

    newdial->setLayout(layout);
    newdial->setWindowTitle("Remove Piece");
    mapper->toFirst();

    Board *TheBoard= Board::getBoard();

    //Confirmando qual peça deve ser removida/ Checking which piece should be removed
    if(newdial->exec() == QDialog::Accepted){
        Xposition=xbox->value();
        Yposition=ybox->value();
        try{
        TheBoard->RemoveList(Xposition,Yposition);
        }catch(...){
            Mwindow::ErrorDialog();
        }
    }
    this->update();
}

//Janela para Dialogo de Erro/ Window for Error Dialog
void Mwindow::ErrorDialog(){
    QMessageBox *newdial=new QMessageBox(this);
    newdial->setText("Sorry... This function is either not possible or not yet available (cof.. cof..)");
    newdial->exec();
    }

//Método para salvar a configuração atual do tabuleiro/ Method for saving actual state of the board
void Mwindow::Save(){
    FILE *ptr;
    Board *TheBoard = Board::getBoard();
    std::list<Piece*>::iterator Mi;

    //Mostrando janela de salvar/  Showing saving window
    QString filename= QFileDialog::getSaveFileName(this, tr("Save FIle"), "/home/mojito", tr("Text Files (*.txt"));

    //Criando arquivo/ Creating archive
    ptr=fopen(filename.toStdString().c_str(), "w");

    //Salvando quantas peças ha/ Saving how many pieces there are
    fprintf(ptr, "%d", Piece::howmany);
    fprintf(ptr, "\n");

    //Salvando qual e onde cada peça esta/ Saving which and where each piece is
    for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
        std::string Type =(*Mi)->Type().toStdString();
        if(Type=="Rook"){
            fprintf(ptr, "%s ", Type.c_str());
            fprintf(ptr, "%d ", (*Mi)->getX());
            fprintf(ptr, "%d \n", (*Mi)->getY());
        }
        else if(Type=="Knight"){
            fprintf(ptr, "%s ", Type.c_str());
            fprintf(ptr, "%d ", (*Mi)->getX());
            fprintf(ptr, "%d \n", (*Mi)->getY());
        }
        else if(Type=="Bishop"){
            fprintf(ptr, "%s ", Type.c_str());
            fprintf(ptr, "%d ", (*Mi)->getX());
            fprintf(ptr, "%d \n", (*Mi)->getY());
        }
        else if(Type=="Queen"){
            fprintf(ptr, "%s ", Type.c_str());
            fprintf(ptr, "%d ", (*Mi)->getX());
            fprintf(ptr, "%d \n", (*Mi)->getY());
        }
    }
    fclose(ptr);
}

//Metodo para abrir arquivo/ Method for Opening a file
void Mwindow::Open(){
    FILE *ptr;
    std::list<Piece*>::iterator Mi;
    int a, b;
    char TypeOf[7];

    //Mostrando janela de abrir/ Showing opening window
    QString filename= QFileDialog::getOpenFileName(this, tr("Open File"), "/home/mojito", tr("Text Files (*.txt"));
    ptr=fopen(filename.toStdString().c_str(), "r");

    //Pegando quantas peças ha/ getting how many pieces there are
    fscanf(ptr, "%d", &Piece::howmany);

    //Pegando quais e onde estão/ getting which and where they are
    for(int i=0;i<Piece::howmany;i++){
        fscanf(ptr, "%s", TypeOf);
        QString TypeString= TypeOf;
        if(TypeString=="Rook"){
            fscanf(ptr, "%d", &a);
            fscanf(ptr, "%d", &b);
            Rook* rookpiece= new Rook(a,b);
            try{
            rookpiece->InsertList(rookpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
        else if(TypeString=="Kinght"){
            fscanf(ptr, "%d", &a);
            fscanf(ptr, "%d", &b);
            Knight* knightpiece= new Knight(a,b);
            try{
            knightpiece->InsertList(knightpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
        else if(TypeString == "Bishop"){
            fscanf(ptr, "%d", &a);
            fscanf(ptr, "%d", &b);
            Bishop* bishoppiece= new Bishop(a,b);
            try{
            bishoppiece->InsertList(bishoppiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }s
        }
        else if(TypeString == "Queen"){
            fscanf(ptr, "%d", &a);
            fscanf(ptr, "%d", &b);
            Queen* queenpiece= new Queen(a,b);
            try{
            queenpiece->InsertList(queenpiece,Xposition,Yposition);
            }catch(...){
                Mwindow::ErrorDialog();
            }
        }
    }
fclose(ptr);
}

//Metodo para resetar o jogo/ Method for reseting the game
void Mwindow::New(){
    Board *TheBoard = Board::getBoard();
    TheBoard->PiecesList.clear();
    this->update();
}

//Metodo que cuida de eventos de mouse/ Method for handling mouse events
void Mwindow::mousePressEvent(QMouseEvent *event){
    QMainWindow::mousePressEvent(event);
    Board *TheBoard = Board::getBoard();
    std::list<Piece*>::iterator Mi;
    int Xpos, Ypos;
    bool CheckedPiece=false;

    //Calculando a posição do mouse no tabuleiro/ calculating which position in the board the mouse is
    Xpos=((event->x())-10)/65;
    Ypos=((event->y())-35)/65;
    for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
        if((*Mi)->IsChecked()==true){
            CheckedPiece=true;
            break;
        }
    }
    //Confirmando qual peça deve ser marcada/ Checking which piece should be checked
    if(CheckedPiece==false){
        for(Mi=TheBoard->PiecesList.begin(); Mi!=TheBoard->PiecesList.end(); Mi++){
            if((*Mi)->getX()==Xpos and (*Mi)->getY()==Ypos){
                (*Mi)->SetChecked(true);
                break;
            }
        }
    }
    //Movendo a peça/ Moving piece
    else if(CheckedPiece==true){
        try{
        (*Mi)->Move(Xpos,Ypos);
        (*Mi)->SetChecked(false);
        }catch(...){
            Mwindow::ErrorDialog();
        }
    }
this->update();

}
