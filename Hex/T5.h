/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T5.h                                                                           *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "T5" (Tablero 15x15) con sus métodos y atributos.       *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef T5_H
#define T5_H

#include <QDialog>
#include <QButtonGroup>
#include "Tablero.h"
#include "Jugador.h"

namespace Ui {
class T5;
}

class T5 : public QDialog
{
    Q_OBJECT

public:
    explicit T5(QWidget *parent, QString modalidad);
    explicit T5(QWidget *parent, QString modalidad, int ** T);
    ~T5();
    void marcar(int id, int posX, int posY);
    int generarBoton(int posX, int posY);
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

    void on_G_clicked();

private:
    Ui::T5 *ui;
    QString modalidad;
    int empate;
    bool decision;
    Jugador * J1;
    Jugador * J2;
    Tablero * T;
    QString pActual;
    QString pArchivo;
};

#endif // T5_H
