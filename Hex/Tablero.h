/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Tablero.h                                                                      *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "Tablero" con sus métodos y atributos.                  *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef TABLERO_H
#define TABLERO_H

#include <QString>
#include <vector>
using std::vector;

class Tablero{
    private:
        int dimension;
        int ** matriz;
        bool ** B;
        vector <int> V;
    public:
        Tablero(int dimension);
        ~Tablero();
        int getPos(int posX, int posY);
        void setPos(int posX, int posY, int N);
        bool ocupada(int posX, int posY);
        QString leerT();
        bool dentro(vector <int> V, int N);
        QString juzgar(bool &decision, int x, int y, int N, int empate);
};

#endif
