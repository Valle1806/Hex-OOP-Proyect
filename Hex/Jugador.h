/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Jugador.h                                                                      *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "Jugador" con sus métodos y atributos.                  *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Tablero.h"

class Jugador{
    private:
        int N;
        int posX;
        int posY;
    public:
        Jugador(int N);
        Jugador(int N, int posX, int posY);
        ~Jugador();
        int getPosX();
        int getPosY();
        void setPos(int posX, int posY);
        void jugar(Tablero * &T);
};

#endif

