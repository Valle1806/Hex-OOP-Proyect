/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T5.cpp                                                                         *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "T5" (Tablero 5x5)                       *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "T5.h"
#include "ui_T5.h"
#include <QTime>
#include <QFileDialog>

//Constructor base:

T5::T5(QWidget *parent, QString modalidad) :
    QDialog(parent),
    ui(new Ui::T5)
{
    //Inicializamos todos los atributos en su forma base:

    ui->setupUi(this);
    this->modalidad = modalidad;
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    T = new Tablero(5);
    pActual = T->leerT();
    pArchivo = "";
    ui->juega->setText("Jugador 1");
}

//Constructor de copia:

T5::T5(QWidget *parent, QString modalidad, int ** T):QDialog(parent),ui(new Ui::T5){
    ui->setupUi(this);
    this->modalidad = "Multijugador";
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    this->T = new Tablero(5);
    //Modificamos cada entrada de la matriz atributo con la de entrada:
    for(int x=0; x<5; x++){
        for(int y=0; y<5; y++){
            switch(T[x][y]){
                case 1:
                    //Realizamos las jugadas correspondientes a la matriz cargada.
                    ui->botones->buttons()[generarBoton(x,y)]->setText("1");
                    J1->setPos(x,y);
                    J1->jugar(this->T);
                    empate += 1;
                    pActual = this->T->leerT();
                    ui->juega->setText("Jugador 2");
                    ui->mensaje->setText(this->T->juzgar(decision,x,y,1,empate));
                    if(!decision){
                        ui->juega->setText("FIN");
                    }
                    break;
                case 2:
                    //Realizamos las jugadas correspondientes a la matriz cargada.
                    ui->botones->buttons()[generarBoton(x,y)]->setText("2");
                    J1->setPos(x,y);
                    J1->jugar(this->T);
                    empate += 1;
                    pActual = this->T->leerT();
                    ui->juega->setText("Jugador 1");
                    ui->mensaje->setText(this->T->juzgar(decision,x,y,2,empate));
                    if(!decision){
                        ui->juega->setText("FIN");
                    }
                    break;
            }
        }
    }
    pActual = this->T->leerT();
    pArchivo = "";
    this->modalidad = modalidad;
    ui->juega->setText("Jugador 1");
}

//Destructor:

T5::~T5()
{
    delete ui;
}

//Genera el número que identifica un botón dentro de un grupo de botones dada su posición.

int T5::generarBoton(int posX, int posY){
    int matriz[5][5];
    int N = -1;
    for(int x=0; x<5; x++){
        for(int y=0; y<5; y++){
            N += 1;
            matriz[x][y] = N;
        }
    }
    return matriz[posX][posY];
}

//Escritura del archivo a guardar.

void T5::guardar(){
    QFile partida(pArchivo); //Creamos la variable del archivo.
    if(partida.open(QFile::WriteOnly)){
        partida.write(pActual.toUtf8()); //Escribimos en el archivo lo contenido en el atributo pActual.
    }
}

//Función general de las jugadas:

void T5::marcar(int id, int posX, int posY){
    qsrand(QTime::currentTime().msec()); //Definimos la semilla para la parte aleatoria.
    if(decision){ //Verificamos si el juego ya acabó.
        if(!(T->ocupada(posX,posY))){ //Verificamos que la posición ingresada no esté ocupada.
           if(empate%2 == 0){ //Verificamos si el turno es par o no.
               if(modalidad.compare("Individual") == 0){ //Verificamos el tipo de juego.
                   ui->botones->buttons()[id]->setText("1"); //Marcamos el botón pulsado.
                   J1->setPos(posX,posY); //Cambiamos la posición del jugador.
                   J1->jugar(T); //Modificamos la matriz interna.
                   empate += 1; //Contamos el turno.
                   pActual = T->leerT(); //Actualizamos el estado de la matriz para guardarla.
                   ui->juega->setText("Jugador 2"); //Imprimimos el jugador que sigue.
                   ui->mensaje->setText(T->juzgar(decision,posX,posY,1,empate)); //Verificamos si hay ganador.
                   if(!decision){
                       ui->juega->setText("FIN"); //Si el juego acabó se imprime.
                   }
                   int N1;
                   int N2;
                   if(empate <= 24 && decision){
                       do{
                           //Definimos una posición al azar en el tablero.
                           N1 = rand() % 5;
                           N2 = rand() % 5;
                       }while(T->ocupada(N1,N2)); //Se redefine mientras esté ocupada dicha posición.
                       ui->botones->buttons()[generarBoton(N1,N2)]->setText("2"); //Marcamos el botón elegido.
                       J2->setPos(N1,N2); //Cambiamos la posición del jugador máquina.
                       J2->jugar(T); //Modificamos la matriz interna.
                       empate += 1; //Contamos el turno.
                       pActual = T->leerT(); //Actualizamos el estado de la matriz para guardarla.
                       ui->juega->setText("Jugador 1"); //Imprimimos el jugador que sigue.
                       ui->mensaje->setText(T->juzgar(decision,posX,posY,2,empate)); //Verificamos si hay ganador.
                       if(!decision){
                           ui->juega->setText("FIN"); //Si el juego acabó se imprime.
                       }
                   }
               }
               else{
                   ui->botones->buttons()[id]->setText("1"); //Marcamos el botón pulsado.
                   J1->setPos(posX,posY); //Cambiamos la posición del jugador 1.
                   J1->jugar(T); //Modificamos la matriz interna.
                   empate += 1; //Contamos el turno.
                   pActual = T->leerT(); //Actualizamos el estado de la matriz para guardarla.
                   ui->juega->setText("Jugador 2"); //Imprimimos el jugador que sigue.
                   ui->mensaje->setText(T->juzgar(decision,posX,posY,1,empate)); //Verificamos si hay ganador.
                   if(!decision){
                      ui->juega->setText("FIN"); //Si el juego acabó se imprime.
                  }
               }
            }
            else{
               ui->botones->buttons()[id]->setText("2"); //Marcamos el botón pulsado.
               J2->setPos(posX,posY); //Cambiamos la posición del jugador 2.
               J2->jugar(T); //Modificamos la matriz interna.
               empate += 1; //Contamos el turno.
               pActual = T->leerT(); //Actualizamos el estado de la matriz para guardarla.
               ui->juega->setText("Jugador 1"); //Imprimimos el jugador que sigue.
               ui->mensaje->setText(T->juzgar(decision,posX,posY,2,empate)); //Verificamos si hay ganador.
               if(!decision){
                   ui->juega->setText("FIN"); //Si el juego acabó se imprime.
               }
            }
        }
        else{
            ui->mensaje->setText("Posición ocupada"); //Si la posición está ocupada se imprime.
        }
    }
}

//Al pulsar cada botón se llama a la función marcar con sus respectivos parámetros.

void T5::on_pushButton_clicked(){marcar(0,0,0);}
void T5::on_pushButton_2_clicked(){marcar(1,0,1);}
void T5::on_pushButton_3_clicked(){marcar(2,0,2);}
void T5::on_pushButton_4_clicked(){marcar(3,0,3);}
void T5::on_pushButton_5_clicked(){marcar(4,0,4);}
void T5::on_pushButton_6_clicked(){marcar(5,1,0);}
void T5::on_pushButton_7_clicked(){marcar(6,1,1);}
void T5::on_pushButton_8_clicked(){marcar(7,1,2);}
void T5::on_pushButton_9_clicked(){marcar(8,1,3);}
void T5::on_pushButton_10_clicked(){marcar(9,1,4);}
void T5::on_pushButton_11_clicked(){marcar(10,2,0);}
void T5::on_pushButton_12_clicked(){marcar(11,2,1);}
void T5::on_pushButton_13_clicked(){marcar(12,2,2);}
void T5::on_pushButton_14_clicked(){marcar(13,2,3);}
void T5::on_pushButton_15_clicked(){marcar(14,2,4);}
void T5::on_pushButton_16_clicked(){marcar(15,3,0);}
void T5::on_pushButton_17_clicked(){marcar(16,3,1);}
void T5::on_pushButton_18_clicked(){marcar(17,3,2);}
void T5::on_pushButton_19_clicked(){marcar(18,3,3);}
void T5::on_pushButton_20_clicked(){marcar(19,3,4);}
void T5::on_pushButton_21_clicked(){marcar(20,4,0);}
void T5::on_pushButton_22_clicked(){marcar(21,4,1);}
void T5::on_pushButton_23_clicked(){marcar(22,4,2);}
void T5::on_pushButton_24_clicked(){marcar(23,4,3);}
void T5::on_pushButton_25_clicked(){marcar(24,4,4);}

//Al pulsar el botón guardar:

void T5::on_G_clicked()
{
    //Empezamos la búsqueda con la dirección y un tipo de archivo específico.
    QString nombreArchivo = QFileDialog::getSaveFileName(this, "Hex - Guardar como", "/home", "Text files (*.txt);;All files (*.*)");
    //Verificamos si está vacío.
    if(!nombreArchivo.isEmpty()){
        //Guardamos.
        pArchivo = nombreArchivo;
        guardar();
    }
}
