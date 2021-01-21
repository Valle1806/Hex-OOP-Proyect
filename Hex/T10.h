/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T10.h                                                                          *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "T10" (Tablero 10x10) con sus métodos y atributos.      *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef T10_H
#define T10_H

#include <QDialog>
#include "Jugador.h"

namespace Ui {
class T10;
}

class T10 : public QDialog
{
    Q_OBJECT

public:
    explicit T10(QWidget *parent, QString modalidad);
    explicit T10(QWidget *parent, QString modalidad, int ** T);
    ~T10();
    int generarBoton(int posX, int posY);
    void marcar(int id, int posX, int posY);
    void guardar();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_55_clicked();
    void on_pushButton_56_clicked();
    void on_pushButton_57_clicked();
    void on_pushButton_58_clicked();
    void on_pushButton_59_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_61_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_63_clicked();
    void on_pushButton_64_clicked();
    void on_pushButton_65_clicked();
    void on_pushButton_66_clicked();
    void on_pushButton_67_clicked();
    void on_pushButton_68_clicked();
    void on_pushButton_69_clicked();
    void on_pushButton_70_clicked();
    void on_pushButton_71_clicked();
    void on_pushButton_72_clicked();
    void on_pushButton_73_clicked();
    void on_pushButton_74_clicked();
    void on_pushButton_75_clicked();
    void on_pushButton_76_clicked();
    void on_pushButton_77_clicked();
    void on_pushButton_78_clicked();
    void on_pushButton_79_clicked();
    void on_pushButton_80_clicked();
    void on_pushButton_81_clicked();
    void on_pushButton_82_clicked();
    void on_pushButton_83_clicked();
    void on_pushButton_84_clicked();
    void on_pushButton_85_clicked();
    void on_pushButton_86_clicked();
    void on_pushButton_87_clicked();
    void on_pushButton_88_clicked();
    void on_pushButton_89_clicked();
    void on_pushButton_90_clicked();
    void on_pushButton_91_clicked();
    void on_pushButton_92_clicked();
    void on_pushButton_93_clicked();
    void on_pushButton_94_clicked();
    void on_pushButton_95_clicked();
    void on_pushButton_96_clicked();
    void on_pushButton_97_clicked();
    void on_pushButton_98_clicked();
    void on_pushButton_99_clicked();
    void on_pushButton_100_clicked();

    void on_G_clicked();

private:
    Ui::T10 *ui;
    QString modalidad;
    int empate;
    bool decision;
    Jugador * J1;
    Jugador * J2;
    Tablero * T;
    QString pActual;
    QString pArchivo;
};

#endif // T10_H
