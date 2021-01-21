/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T10.cpp                                                                        *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "T10" (Tablero 10x10)                    *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "T10.h"
#include "ui_T10.h"
#include <QTime>
#include <QFileDialog>

//Constructor base:

T10::T10(QWidget *parent, QString modalidad) :
    QDialog(parent),
    ui(new Ui::T10)
{
    ui->setupUi(this);

    //Inicializamos todos los atributos en su forma base:

    this->modalidad = modalidad;
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    T = new Tablero(10);
    pActual = T->leerT();
    pArchivo = "";
    ui->juega->setText("Jugador 1");
}

//Constructor de copia:

T10::T10(QWidget *parent, QString modalidad, int ** T):QDialog(parent),ui(new Ui::T10){
    ui->setupUi(this);
    this->modalidad = "Multijugador";
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    this->T = new Tablero(10);
    //Modificamos cada entrada de la matriz atributo con la de entrada:
    for(int x=0; x<10; x++){
        for(int y=0; y<10; y++){
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

T10::~T10()
{
    delete ui;
}

//Genera el número que identifica un botón dentro de un grupo de botones dada su posición.

int T10::generarBoton(int posX, int posY){
    int matriz[10][10];
    int N = -1;
    for(int x=0; x<10; x++){
        for(int y=0; y<10; y++){
            N += 1;
            matriz[x][y] = N;
        }
    }
    return matriz[posX][posY];
}

//Escritura del archivo a guardar.

void T10::guardar(){
    QFile partida(pArchivo); //Creamos la variable del archivo.
    if(partida.open(QFile::WriteOnly)){
        partida.write(pActual.toUtf8()); //Escribimos en el archivo lo contenido en el atributo pActual.
    }
}

//Función general de las jugadas:

void T10::marcar(int id, int posX, int posY){
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
                   if(empate <= 99 && decision){
                       do{
                           //Definimos una posición al azar en el tablero.
                           N1 = rand() % 10;
                           N2 = rand() % 10;
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

void T10::on_pushButton_clicked(){marcar(0,0,0);}
void T10::on_pushButton_2_clicked(){marcar(1,0,1);}
void T10::on_pushButton_3_clicked(){marcar(2,0,2);}
void T10::on_pushButton_4_clicked(){marcar(3,0,3);}
void T10::on_pushButton_5_clicked(){marcar(4,0,4);}
void T10::on_pushButton_6_clicked(){marcar(5,0,5);}
void T10::on_pushButton_7_clicked(){marcar(6,0,6);}
void T10::on_pushButton_8_clicked(){marcar(7,0,7);}
void T10::on_pushButton_9_clicked(){marcar(8,0,8);}
void T10::on_pushButton_10_clicked(){marcar(9,0,9);}
void T10::on_pushButton_11_clicked(){marcar(10,1,0);}
void T10::on_pushButton_12_clicked(){marcar(11,1,1);}
void T10::on_pushButton_13_clicked(){marcar(12,1,2);}
void T10::on_pushButton_14_clicked(){marcar(13,1,3);}
void T10::on_pushButton_15_clicked(){marcar(14,1,4);}
void T10::on_pushButton_16_clicked(){marcar(15,1,5);}
void T10::on_pushButton_17_clicked(){marcar(16,1,6);}
void T10::on_pushButton_18_clicked(){marcar(17,1,7);}
void T10::on_pushButton_19_clicked(){marcar(18,1,8);}
void T10::on_pushButton_20_clicked(){marcar(19,1,9);}
void T10::on_pushButton_21_clicked(){marcar(20,2,0);}
void T10::on_pushButton_22_clicked(){marcar(21,2,1);}
void T10::on_pushButton_23_clicked(){marcar(22,2,2);}
void T10::on_pushButton_24_clicked(){marcar(23,2,3);}
void T10::on_pushButton_25_clicked(){marcar(24,2,4);}
void T10::on_pushButton_26_clicked(){marcar(25,2,5);}
void T10::on_pushButton_27_clicked(){marcar(26,2,6);}
void T10::on_pushButton_28_clicked(){marcar(27,2,7);}
void T10::on_pushButton_29_clicked(){marcar(28,2,8);}
void T10::on_pushButton_30_clicked(){marcar(29,2,9);}
void T10::on_pushButton_31_clicked(){marcar(30,3,0);}
void T10::on_pushButton_32_clicked(){marcar(31,3,1);}
void T10::on_pushButton_33_clicked(){marcar(32,3,2);}
void T10::on_pushButton_34_clicked(){marcar(33,3,3);}
void T10::on_pushButton_35_clicked(){marcar(34,3,4);}
void T10::on_pushButton_36_clicked(){marcar(35,3,5);}
void T10::on_pushButton_37_clicked(){marcar(36,3,6);}
void T10::on_pushButton_38_clicked(){marcar(37,3,7);}
void T10::on_pushButton_39_clicked(){marcar(38,3,8);}
void T10::on_pushButton_40_clicked(){marcar(39,3,9);}
void T10::on_pushButton_41_clicked(){marcar(40,4,0);}
void T10::on_pushButton_42_clicked(){marcar(41,4,1);}
void T10::on_pushButton_43_clicked(){marcar(42,4,2);}
void T10::on_pushButton_44_clicked(){marcar(43,4,3);}
void T10::on_pushButton_45_clicked(){marcar(44,4,4);}
void T10::on_pushButton_46_clicked(){marcar(45,4,5);}
void T10::on_pushButton_47_clicked(){marcar(46,4,6);}
void T10::on_pushButton_48_clicked(){marcar(47,4,7);}
void T10::on_pushButton_49_clicked(){marcar(48,4,8);}
void T10::on_pushButton_50_clicked(){marcar(49,4,9);}
void T10::on_pushButton_51_clicked(){marcar(50,5,0);}
void T10::on_pushButton_52_clicked(){marcar(51,5,1);}
void T10::on_pushButton_53_clicked(){marcar(52,5,2);}
void T10::on_pushButton_54_clicked(){marcar(53,5,3);}
void T10::on_pushButton_55_clicked(){marcar(54,5,4);}
void T10::on_pushButton_56_clicked(){marcar(55,5,5);}
void T10::on_pushButton_57_clicked(){marcar(56,5,6);}
void T10::on_pushButton_58_clicked(){marcar(57,5,7);}
void T10::on_pushButton_59_clicked(){marcar(58,5,8);}
void T10::on_pushButton_60_clicked(){marcar(59,5,9);}
void T10::on_pushButton_61_clicked(){marcar(60,6,0);}
void T10::on_pushButton_62_clicked(){marcar(61,6,1);}
void T10::on_pushButton_63_clicked(){marcar(62,6,2);}
void T10::on_pushButton_64_clicked(){marcar(63,6,3);}
void T10::on_pushButton_65_clicked(){marcar(64,6,4);}
void T10::on_pushButton_66_clicked(){marcar(65,6,5);}
void T10::on_pushButton_67_clicked(){marcar(66,6,6);}
void T10::on_pushButton_68_clicked(){marcar(67,6,7);}
void T10::on_pushButton_69_clicked(){marcar(68,6,8);}
void T10::on_pushButton_70_clicked(){marcar(69,6,9);}
void T10::on_pushButton_71_clicked(){marcar(70,7,0);}
void T10::on_pushButton_72_clicked(){marcar(71,7,1);}
void T10::on_pushButton_73_clicked(){marcar(72,7,2);}
void T10::on_pushButton_74_clicked(){marcar(73,7,3);}
void T10::on_pushButton_75_clicked(){marcar(74,7,4);}
void T10::on_pushButton_76_clicked(){marcar(75,7,5);}
void T10::on_pushButton_77_clicked(){marcar(76,7,6);}
void T10::on_pushButton_78_clicked(){marcar(77,7,7);}
void T10::on_pushButton_79_clicked(){marcar(78,7,8);}
void T10::on_pushButton_80_clicked(){marcar(79,7,9);}
void T10::on_pushButton_81_clicked(){marcar(80,8,0);}
void T10::on_pushButton_82_clicked(){marcar(81,8,1);}
void T10::on_pushButton_83_clicked(){marcar(82,8,2);}
void T10::on_pushButton_84_clicked(){marcar(83,8,3);}
void T10::on_pushButton_85_clicked(){marcar(84,8,4);}
void T10::on_pushButton_86_clicked(){marcar(85,8,5);}
void T10::on_pushButton_87_clicked(){marcar(86,8,6);}
void T10::on_pushButton_88_clicked(){marcar(87,8,7);}
void T10::on_pushButton_89_clicked(){marcar(88,8,8);}
void T10::on_pushButton_90_clicked(){marcar(89,8,9);}
void T10::on_pushButton_91_clicked(){marcar(90,9,0);}
void T10::on_pushButton_92_clicked(){marcar(91,9,1);}
void T10::on_pushButton_93_clicked(){marcar(92,9,2);}
void T10::on_pushButton_94_clicked(){marcar(93,9,3);}
void T10::on_pushButton_95_clicked(){marcar(94,9,4);}
void T10::on_pushButton_96_clicked(){marcar(95,9,5);}
void T10::on_pushButton_97_clicked(){marcar(96,9,6);}
void T10::on_pushButton_98_clicked(){marcar(97,9,7);}
void T10::on_pushButton_99_clicked(){marcar(98,9,8);}
void T10::on_pushButton_100_clicked(){marcar(99,9,9);}

//Al pulsar el botón guardar:

void T10::on_G_clicked()
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
