/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Hex.h                                                                          *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "Hex" (Ventana principal) con sus métodos y atributos.  *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef HEX_H
#define HEX_H

#include <QMainWindow>
#include <QString>
#include "T5.h"
#include "T10.h"
#include "T15.h"

namespace Ui {
class Hex;
}

class Hex : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hex(QWidget *parent = 0);
    ~Hex();
    void setModalidad(QString modalidad);

private slots:
    void on_x5_clicked();

    void on_x10_clicked();

    void on_x15_clicked();

    void on_actionCargar_partida_triggered();

private:
    Ui::Hex *ui;
    QString modalidad;
    QString archivo;
    int ** T;
};

#endif // HEX_H
