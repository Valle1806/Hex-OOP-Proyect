/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T15.cpp                                                                        *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "T15" (Tablero 15x15)                    *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "T15.h"
#include "ui_T15.h"
#include <QTime>
#include <QFileDialog>

//Constructor base:

T15::T15(QWidget *parent, QString modalidad) :
    QDialog(parent),
    ui(new Ui::T15)
{
     //Inicializamos todos los atributos en su forma base:

    ui->setupUi(this);
    this->modalidad = modalidad;
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    T = new Tablero(15);
    pActual = T->leerT();
    pArchivo = "";
    ui->juega->setText("Jugador 1");
}

//Constructor de copia:

T15::T15(QWidget *parent, QString modalidad, int ** T):QDialog(parent),ui(new Ui::T15){
    ui->setupUi(this);
    this->modalidad = "Multijugador";
    empate = 0;
    decision = true;
    J1 = new Jugador(1);
    J2 = new Jugador(2);
    this->T = new Tablero(15);
    //Modificamos cada entrada de la matriz atributo con la de entrada:
    for(int x=0; x<15; x++){
        for(int y=0; y<15; y++){
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

T15::~T15()
{
    delete ui;
}

//Genera el número que identifica un botón dentro de un grupo de botones dada su posición.

int T15::generarBoton(int posX, int posY){
    int matriz[15][15];
    int N = -1;
    for(int x=0; x<15; x++){
        for(int y=0; y<15; y++){
            N += 1;
            matriz[x][y] = N;
        }
    }
    return matriz[posX][posY];
}

//Escritura del archivo a guardar.

void T15::guardar(){
    QFile partida(pArchivo); //Creamos la variable del archivo.
    if(partida.open(QFile::WriteOnly)){
        partida.write(pActual.toUtf8()); //Escribimos en el archivo lo contenido en el atributo pActual.
    }
}

//Función general de las jugadas:

void T15::marcar(int id, int posX, int posY){
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
                   if(empate <= 224 && decision){
                       do{
                           //Definimos una posición al azar en el tablero.
                           N1 = rand() % 15;
                           N2 = rand() % 15;
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

void T15::on_pushButton_clicked(){marcar(0,0,0);}
void T15::on_pushButton_2_clicked(){marcar(1,0,1);}
void T15::on_pushButton_3_clicked(){marcar(2,0,2);}
void T15::on_pushButton_4_clicked(){marcar(3,0,3);}
void T15::on_pushButton_5_clicked(){marcar(4,0,4);}
void T15::on_pushButton_6_clicked(){marcar(5,0,5);}
void T15::on_pushButton_7_clicked(){marcar(6,0,6);}
void T15::on_pushButton_8_clicked(){marcar(7,0,7);}
void T15::on_pushButton_9_clicked(){marcar(8,0,8);}
void T15::on_pushButton_10_clicked(){marcar(9,0,9);}
void T15::on_pushButton_11_clicked(){marcar(10,0,10);}
void T15::on_pushButton_12_clicked(){marcar(11,0,11);}
void T15::on_pushButton_13_clicked(){marcar(12,0,12);}
void T15::on_pushButton_14_clicked(){marcar(13,0,13);}
void T15::on_pushButton_15_clicked(){marcar(14,0,14);}
void T15::on_pushButton_16_clicked(){marcar(15,1,0);}
void T15::on_pushButton_17_clicked(){marcar(16,1,1);}
void T15::on_pushButton_18_clicked(){marcar(17,1,2);}
void T15::on_pushButton_19_clicked(){marcar(18,1,3);}
void T15::on_pushButton_20_clicked(){marcar(19,1,4);}
void T15::on_pushButton_21_clicked(){marcar(20,1,5);}
void T15::on_pushButton_22_clicked(){marcar(21,1,6);}
void T15::on_pushButton_23_clicked(){marcar(22,1,7);}
void T15::on_pushButton_24_clicked(){marcar(23,1,8);}
void T15::on_pushButton_25_clicked(){marcar(24,1,9);}
void T15::on_pushButton_26_clicked(){marcar(25,1,10);}
void T15::on_pushButton_27_clicked(){marcar(26,1,11);}
void T15::on_pushButton_28_clicked(){marcar(27,1,12);}
void T15::on_pushButton_29_clicked(){marcar(28,1,13);}
void T15::on_pushButton_30_clicked(){marcar(29,1,14);}
void T15::on_pushButton_31_clicked(){marcar(30,2,0);}
void T15::on_pushButton_32_clicked(){marcar(31,2,1);}
void T15::on_pushButton_33_clicked(){marcar(32,2,2);}
void T15::on_pushButton_34_clicked(){marcar(33,2,3);}
void T15::on_pushButton_35_clicked(){marcar(34,2,4);}
void T15::on_pushButton_36_clicked(){marcar(35,2,5);}
void T15::on_pushButton_37_clicked(){marcar(36,2,6);}
void T15::on_pushButton_38_clicked(){marcar(37,2,7);}
void T15::on_pushButton_39_clicked(){marcar(38,2,8);}
void T15::on_pushButton_40_clicked(){marcar(39,2,9);}
void T15::on_pushButton_41_clicked(){marcar(40,2,10);}
void T15::on_pushButton_42_clicked(){marcar(41,2,11);}
void T15::on_pushButton_43_clicked(){marcar(42,2,12);}
void T15::on_pushButton_44_clicked(){marcar(43,2,13);}
void T15::on_pushButton_45_clicked(){marcar(44,2,14);}
void T15::on_pushButton_46_clicked(){marcar(45,3,0);}
void T15::on_pushButton_47_clicked(){marcar(46,3,1);}
void T15::on_pushButton_48_clicked(){marcar(47,3,2);}
void T15::on_pushButton_49_clicked(){marcar(48,3,3);}
void T15::on_pushButton_50_clicked(){marcar(49,3,4);}
void T15::on_pushButton_51_clicked(){marcar(50,3,5);}
void T15::on_pushButton_52_clicked(){marcar(51,3,6);}
void T15::on_pushButton_53_clicked(){marcar(52,3,7);}
void T15::on_pushButton_54_clicked(){marcar(53,3,8);}
void T15::on_pushButton_55_clicked(){marcar(54,3,9);}
void T15::on_pushButton_56_clicked(){marcar(55,3,10);}
void T15::on_pushButton_57_clicked(){marcar(56,3,11);}
void T15::on_pushButton_58_clicked(){marcar(57,3,12);}
void T15::on_pushButton_59_clicked(){marcar(58,3,13);}
void T15::on_pushButton_60_clicked(){marcar(59,3,14);}
void T15::on_pushButton_61_clicked(){marcar(60,4,0);}
void T15::on_pushButton_62_clicked(){marcar(61,4,1);}
void T15::on_pushButton_63_clicked(){marcar(62,4,2);}
void T15::on_pushButton_64_clicked(){marcar(63,4,3);}
void T15::on_pushButton_65_clicked(){marcar(64,4,4);}
void T15::on_pushButton_66_clicked(){marcar(65,4,5);}
void T15::on_pushButton_67_clicked(){marcar(66,4,6);}
void T15::on_pushButton_68_clicked(){marcar(67,4,7);}
void T15::on_pushButton_69_clicked(){marcar(68,4,8);}
void T15::on_pushButton_70_clicked(){marcar(69,4,9);}
void T15::on_pushButton_71_clicked(){marcar(70,4,10);}
void T15::on_pushButton_72_clicked(){marcar(71,4,11);}
void T15::on_pushButton_73_clicked(){marcar(72,4,12);}
void T15::on_pushButton_74_clicked(){marcar(73,4,13);}
void T15::on_pushButton_75_clicked(){marcar(74,4,14);}
void T15::on_pushButton_76_clicked(){marcar(75,5,0);}
void T15::on_pushButton_77_clicked(){marcar(76,5,1);}
void T15::on_pushButton_78_clicked(){marcar(77,5,2);}
void T15::on_pushButton_79_clicked(){marcar(78,5,3);}
void T15::on_pushButton_80_clicked(){marcar(79,5,4);}
void T15::on_pushButton_81_clicked(){marcar(80,5,5);}
void T15::on_pushButton_82_clicked(){marcar(81,5,6);}
void T15::on_pushButton_83_clicked(){marcar(82,5,7);}
void T15::on_pushButton_84_clicked(){marcar(83,5,8);}
void T15::on_pushButton_85_clicked(){marcar(84,5,9);}
void T15::on_pushButton_86_clicked(){marcar(85,5,10);}
void T15::on_pushButton_87_clicked(){marcar(86,5,11);}
void T15::on_pushButton_88_clicked(){marcar(87,5,12);}
void T15::on_pushButton_89_clicked(){marcar(88,5,13);}
void T15::on_pushButton_90_clicked(){marcar(89,5,14);}
void T15::on_pushButton_91_clicked(){marcar(90,6,0);}
void T15::on_pushButton_92_clicked(){marcar(91,6,1);}
void T15::on_pushButton_93_clicked(){marcar(92,6,2);}
void T15::on_pushButton_94_clicked(){marcar(93,6,3);}
void T15::on_pushButton_95_clicked(){marcar(94,6,4);}
void T15::on_pushButton_96_clicked(){marcar(95,6,5);}
void T15::on_pushButton_97_clicked(){marcar(96,6,6);}
void T15::on_pushButton_98_clicked(){marcar(97,6,7);}
void T15::on_pushButton_99_clicked(){marcar(98,6,8);}
void T15::on_pushButton_100_clicked(){marcar(99,6,9);}
void T15::on_pushButton_101_clicked(){marcar(100,6,10);}
void T15::on_pushButton_102_clicked(){marcar(101,6,11);}
void T15::on_pushButton_103_clicked(){marcar(102,6,12);}
void T15::on_pushButton_104_clicked(){marcar(103,6,13);}
void T15::on_pushButton_105_clicked(){marcar(104,6,14);}
void T15::on_pushButton_106_clicked(){marcar(105,7,0);}
void T15::on_pushButton_107_clicked(){marcar(106,7,1);}
void T15::on_pushButton_108_clicked(){marcar(107,7,2);}
void T15::on_pushButton_109_clicked(){marcar(108,7,3);}
void T15::on_pushButton_110_clicked(){marcar(109,7,4);}
void T15::on_pushButton_111_clicked(){marcar(110,7,5);}
void T15::on_pushButton_112_clicked(){marcar(111,7,6);}
void T15::on_pushButton_113_clicked(){marcar(112,7,7);}
void T15::on_pushButton_114_clicked(){marcar(113,7,8);}
void T15::on_pushButton_115_clicked(){marcar(114,7,9);}
void T15::on_pushButton_116_clicked(){marcar(115,7,10);}
void T15::on_pushButton_117_clicked(){marcar(116,7,11);}
void T15::on_pushButton_118_clicked(){marcar(117,7,12);}
void T15::on_pushButton_119_clicked(){marcar(118,7,13);}
void T15::on_pushButton_120_clicked(){marcar(119,7,14);}
void T15::on_pushButton_121_clicked(){marcar(120,8,0);}
void T15::on_pushButton_122_clicked(){marcar(121,8,1);}
void T15::on_pushButton_123_clicked(){marcar(122,8,2);}
void T15::on_pushButton_124_clicked(){marcar(123,8,3);}
void T15::on_pushButton_125_clicked(){marcar(124,8,4);}
void T15::on_pushButton_126_clicked(){marcar(125,8,5);}
void T15::on_pushButton_127_clicked(){marcar(126,8,6);}
void T15::on_pushButton_128_clicked(){marcar(127,8,7);}
void T15::on_pushButton_129_clicked(){marcar(128,8,8);}
void T15::on_pushButton_130_clicked(){marcar(129,8,9);}
void T15::on_pushButton_131_clicked(){marcar(130,8,10);}
void T15::on_pushButton_132_clicked(){marcar(131,8,11);}
void T15::on_pushButton_133_clicked(){marcar(132,8,12);}
void T15::on_pushButton_134_clicked(){marcar(133,8,13);}
void T15::on_pushButton_135_clicked(){marcar(134,8,14);}
void T15::on_pushButton_136_clicked(){marcar(135,9,0);}
void T15::on_pushButton_137_clicked(){marcar(136,9,1);}
void T15::on_pushButton_138_clicked(){marcar(137,9,2);}
void T15::on_pushButton_139_clicked(){marcar(138,9,3);}
void T15::on_pushButton_140_clicked(){marcar(139,9,4);}
void T15::on_pushButton_141_clicked(){marcar(140,9,5);}
void T15::on_pushButton_142_clicked(){marcar(141,9,6);}
void T15::on_pushButton_143_clicked(){marcar(142,9,7);}
void T15::on_pushButton_144_clicked(){marcar(143,9,8);}
void T15::on_pushButton_145_clicked(){marcar(144,9,9);}
void T15::on_pushButton_146_clicked(){marcar(145,9,10);}
void T15::on_pushButton_147_clicked(){marcar(146,9,11);}
void T15::on_pushButton_148_clicked(){marcar(147,9,12);}
void T15::on_pushButton_149_clicked(){marcar(148,9,13);}
void T15::on_pushButton_150_clicked(){marcar(149,9,14);}
void T15::on_pushButton_151_clicked(){marcar(150,10,0);}
void T15::on_pushButton_152_clicked(){marcar(151,10,1);}
void T15::on_pushButton_153_clicked(){marcar(152,10,2);}
void T15::on_pushButton_154_clicked(){marcar(153,10,3);}
void T15::on_pushButton_155_clicked(){marcar(154,10,4);}
void T15::on_pushButton_156_clicked(){marcar(155,10,5);}
void T15::on_pushButton_157_clicked(){marcar(156,10,6);}
void T15::on_pushButton_158_clicked(){marcar(157,10,7);}
void T15::on_pushButton_159_clicked(){marcar(158,10,8);}
void T15::on_pushButton_160_clicked(){marcar(159,10,9);}
void T15::on_pushButton_161_clicked(){marcar(160,10,10);}
void T15::on_pushButton_162_clicked(){marcar(161,10,11);}
void T15::on_pushButton_163_clicked(){marcar(162,10,12);}
void T15::on_pushButton_164_clicked(){marcar(163,10,13);}
void T15::on_pushButton_165_clicked(){marcar(164,10,14);}
void T15::on_pushButton_166_clicked(){marcar(165,11,0);}
void T15::on_pushButton_167_clicked(){marcar(166,11,1);}
void T15::on_pushButton_168_clicked(){marcar(167,11,2);}
void T15::on_pushButton_169_clicked(){marcar(168,11,3);}
void T15::on_pushButton_170_clicked(){marcar(169,11,4);}
void T15::on_pushButton_171_clicked(){marcar(170,11,5);}
void T15::on_pushButton_172_clicked(){marcar(171,11,6);}
void T15::on_pushButton_173_clicked(){marcar(172,11,7);}
void T15::on_pushButton_174_clicked(){marcar(173,11,8);}
void T15::on_pushButton_175_clicked(){marcar(174,11,9);}
void T15::on_pushButton_176_clicked(){marcar(175,11,10);}
void T15::on_pushButton_177_clicked(){marcar(176,11,11);}
void T15::on_pushButton_178_clicked(){marcar(177,11,12);}
void T15::on_pushButton_179_clicked(){marcar(178,11,13);}
void T15::on_pushButton_180_clicked(){marcar(179,11,14);}
void T15::on_pushButton_181_clicked(){marcar(180,12,0);}
void T15::on_pushButton_182_clicked(){marcar(181,12,1);}
void T15::on_pushButton_183_clicked(){marcar(182,12,2);}
void T15::on_pushButton_184_clicked(){marcar(183,12,3);}
void T15::on_pushButton_185_clicked(){marcar(184,12,4);}
void T15::on_pushButton_186_clicked(){marcar(185,12,5);}
void T15::on_pushButton_187_clicked(){marcar(186,12,6);}
void T15::on_pushButton_188_clicked(){marcar(187,12,7);}
void T15::on_pushButton_189_clicked(){marcar(188,12,8);}
void T15::on_pushButton_190_clicked(){marcar(189,12,9);}
void T15::on_pushButton_191_clicked(){marcar(190,12,10);}
void T15::on_pushButton_192_clicked(){marcar(191,12,11);}
void T15::on_pushButton_193_clicked(){marcar(192,12,12);}
void T15::on_pushButton_194_clicked(){marcar(193,12,13);}
void T15::on_pushButton_195_clicked(){marcar(194,12,14);}
void T15::on_pushButton_196_clicked(){marcar(195,13,0);}
void T15::on_pushButton_197_clicked(){marcar(196,13,1);}
void T15::on_pushButton_198_clicked(){marcar(197,13,2);}
void T15::on_pushButton_199_clicked(){marcar(198,13,3);}
void T15::on_pushButton_200_clicked(){marcar(199,13,4);}
void T15::on_pushButton_201_clicked(){marcar(200,13,5);}
void T15::on_pushButton_202_clicked(){marcar(201,13,6);}
void T15::on_pushButton_203_clicked(){marcar(202,13,7);}
void T15::on_pushButton_204_clicked(){marcar(203,13,8);}
void T15::on_pushButton_205_clicked(){marcar(204,13,9);}
void T15::on_pushButton_206_clicked(){marcar(205,13,10);}
void T15::on_pushButton_207_clicked(){marcar(206,13,11);}
void T15::on_pushButton_208_clicked(){marcar(207,13,12);}
void T15::on_pushButton_209_clicked(){marcar(208,13,13);}
void T15::on_pushButton_210_clicked(){marcar(209,13,14);}
void T15::on_pushButton_211_clicked(){marcar(210,14,0);}
void T15::on_pushButton_212_clicked(){marcar(211,14,1);}
void T15::on_pushButton_213_clicked(){marcar(212,14,2);}
void T15::on_pushButton_214_clicked(){marcar(213,14,3);}
void T15::on_pushButton_215_clicked(){marcar(214,14,4);}
void T15::on_pushButton_216_clicked(){marcar(215,14,5);}
void T15::on_pushButton_217_clicked(){marcar(216,14,6);}
void T15::on_pushButton_218_clicked(){marcar(217,14,7);}
void T15::on_pushButton_219_clicked(){marcar(218,14,8);}
void T15::on_pushButton_220_clicked(){marcar(219,14,9);}
void T15::on_pushButton_221_clicked(){marcar(220,14,10);}
void T15::on_pushButton_222_clicked(){marcar(221,14,11);}
void T15::on_pushButton_223_clicked(){marcar(222,14,12);}
void T15::on_pushButton_224_clicked(){marcar(223,14,13);}
void T15::on_pushButton_225_clicked(){marcar(224,14,14);}

//Al pulsar el botón guardar:

void T15::on_G_clicked()
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
