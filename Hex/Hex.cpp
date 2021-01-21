/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Hex.cpp                                                                        *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "Hex" (Ventana principal)                *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "Hex.h"
#include "ui_Hex.h"
#include <QFileDialog>

//Constructor:

Hex::Hex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hex)
{
    ui->setupUi(this);
    modalidad = ui->modo->currentText(); //Seleccionamos el tipo de juego.
    //Seteamos los atributos como vacíos inicialmente.
    archivo = "";
    T = 0;
}

//Destructor:

Hex::~Hex()
{
    delete ui;
}

//Cambia el atributo modalidad por otro ingresado.

void Hex::setModalidad(QString modalidad){
    this->modalidad = modalidad;
}

//Al oprimir el botón 5x5 se genera una nueva ventana, objeto de la clase -T5-.

void Hex::on_x5_clicked()
{
    this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad antes de crear la nueva ventana.
    T5 * ventana5 = new T5(this,modalidad); //Construimos un objeto T5 con la modalidad.
    ventana5->setModal(true); //Esto permite que la ventana creada tenga prioridad sobre la anterior.
    ventana5->show(); //Mostramos la ventana.
}

//Al oprimir el botón 10x10 se genera una nueva ventana, objeto de la clase -T10-.

void Hex::on_x10_clicked()
{
    this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad antes de crear la nueva ventana.
    T10 * ventana10 = new T10(this,modalidad); //Construimos un objeto T10 con la modalidad.
    ventana10->setModal(true); //Esto permite que la ventana creada tenga prioridad sobre la anterior.
    ventana10->show(); //Mostramos la ventana.
}

//Al oprimir el botón 15x15 se genera una nueva ventana, objeto de la clase -T15-.

void Hex::on_x15_clicked()
{
    this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad antes de crear la nueva ventana.
    T15 * ventana15 = new T15(this,modalidad); //Construimos un objeto T15 con la modalidad.
    ventana15->setModal(true); //Esto permite que la ventana creada tenga prioridad sobre la anterior.
    ventana15->show(); //Mostramos la ventana.
}

//Al oprimir el botón de cargar partida:

void Hex::on_actionCargar_partida_triggered()
{
    //Empezamos la búsqueda de acuerdo a una ruta y un tipo de archivo especificado y guardamos.
    QString partida = QFileDialog::getOpenFileName(this, "Hex - Abrir archivo", "/home", "Text files (*.txt);;All files (*.*)");
    //Verificamos si está vacío.
    if(!partida.isEmpty()){
        //Creamos una variable QFile.
        QFile texto(partida);
        if(texto.open(QFile::ReadOnly)){
            //Leemos el texto del archivo y lo guardamos en una variable QString.
            archivo = texto.readAll();
            texto.close(); //Cerramos el archivo.
        }
        texto.close(); //Cerramos el archivo.
    }
    //Separamos el QString donde hayan espacios y saltos de línea y guardamos las partes en un QStringList.
    QStringList digitos = (archivo.split(QRegExp("\\s+"),QString::SkipEmptyParts));
    //Guardamos el primer elemento del QStringList en una variable y la convertimos a entero.
    QString numero;
    numero = digitos.at(0);
    int dimension = numero.toInt();
    //Tomamos el número anterior como la dimensión de la matriz a utilizar y definimos nuestro puntero de punteros.
    T = new int * [dimension];
    for(int x=0; x<dimension; x++){
        T[x] = new int [dimension];
    }
    int contador = 1; //Definimos un contador desde uno para ignorar el primer elemento del QStringList.
    for(int x=0; x<dimension; x++){
        for(int y=0; y<dimension; y++){
            //Convertimos cada elmento del QStringList a entero y lo guardamos en la matriz.
            T[x][y] = (digitos.at(contador)).toInt();
            contador += 1;
        }
    }
    //Si la dimensión es 5:
    if(dimension == 5){
        this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad.
        T5 * ventana5 = new T5(this,modalidad,T); //Creamos una ventana T5 con la modalidad.
        ventana5->setModal(true); //Esto permite que la nueva ventana tenga prioridad sobre la anterior.
        ventana5->show(); //Mostramos la ventana.
    }
    else{
        //Si la dimensión es 10:
        if(dimension == 10){
            this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad.
            T10 * ventana10 = new T10(this,modalidad,T); //Creamos una ventana T10 con la modalidad.
            ventana10->setModal(true); //Esto permite que la nueva ventana tenga prioridad sobre la anterior.
            ventana10->show(); //Mostramos la ventana.
        }
        else{
            //Si la dimensión es 15:
            if(dimension == 15){
                this->setModalidad(ui->modo->currentText()); //Cambiamos la modalidad.
                T15 * ventana15 = new T15(this,modalidad,T); //Creamos una ventana T15 con la modalidad.
                ventana15->setModal(true); //Esto permite que la nueva ventana tenga prioridad sobre la anterior.
                ventana15->show(); //Mostramos la ventana.
            }
        }
    }
}
