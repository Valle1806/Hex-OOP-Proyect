#include "Juego.h"
#include "ui_Juego.h"

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);
}

Juego::~Juego()
{
    delete ui;
}
