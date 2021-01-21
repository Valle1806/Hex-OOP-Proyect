/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Jugador.cpp                                                                    *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "Jugador".                               *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "Jugador.h"

//Constructor base:

Jugador::Jugador(int N){
    this->N = N;
    posX = 0;
    posY = 0;
}

//Constructor de copia:

Jugador::Jugador(int N, int posX, int posY){
    this->N = N;
    this->posX = posX;
    this->posY = posY;
}

//Destructor:

Jugador::~Jugador(){}

//Obtener posición X:

int Jugador::getPosX(){
    return posX;
}

//Obtener posición Y:

int Jugador::getPosY(){
    return posY;
}

//Cambiar posición X & Y:

void Jugador::setPos(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}

//Cambiar el estado de la matriz de un objeto de la clase -Tablero-.

void Jugador::jugar(Tablero * &T){
    T->setPos(posX, posY, N); //Cambiamos uno de los elementos de la matriz.
}
