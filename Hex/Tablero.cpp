/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: Tablero.cpp                                                                    *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define los métodos de la clase "Tablero".                               *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#include "Tablero.h"

//Constructor:

Tablero::Tablero(int dimension){
    this->dimension = dimension;
    //De acuerdo a la dimensión se define el tamaño de la matriz de enteros y la de booleanos.
    matriz = new int * [this->dimension];
    B = new bool * [this->dimension];
    for(int x=0; x<this->dimension; x++){
        matriz[x] = new int [this->dimension];
        B[x] = new bool [this->dimension];
    }
    for(int x=0; x<this->dimension; x++){
        for(int y=0; y<this->dimension; y++){
            matriz[x][y] = 0;
            B[x][y] = false;
        }
    }
}

//Destructor:

Tablero::~Tablero(){}

//Obtener elemento de la matriz dada una posición.

int Tablero::getPos(int posX, int posY){
    return matriz[posX][posY];
}

//Cambiar elemento de la matriz dada una posición.

void Tablero::setPos(int posX, int posY, int N){
    matriz[posX][posY] = N;
}

//Verificar si una posición de la matriz está ocupada.

bool Tablero::ocupada(int posX, int posY){
    if ((matriz[posX][posY] == 1)||(matriz[posX][posY] == 2)){
        return true;
    }
    else {
        return false;
    }
}

//Extraer información de la matriz y guardarla en un QString.

QString Tablero::leerT(){
    QString lectura = QString::number(dimension) + "\n"; //Añadimos la dimensión al texto.
    for(int x=0; x<dimension; x++){
        for(int y=0; y<dimension; y++){
            lectura += QString::number(matriz[x][y]) + " "; //Añadimos los elementos separados por espacios.
        }
        lectura += "\n"; //Añadimos un salto de línea en cada fila.
    }
    return lectura;
}

//Verificar si un número está o no dentro de un vector de enteros.

bool Tablero::dentro(vector<int> V, int N){
    for(int x=0; x<(int)V.size(); x++){
        if(V[x] == N){
            return true;
        }
    }
    return false;
}

//Validar si hay un ganador:

QString Tablero::juzgar(bool &decision, int x, int y, int N, int empate){
    if(empate == dimension*dimension){ //Verificamos si ya se jugaron todas las posiciones.
        //Cambiamos los elementos de la matriz booleana por false.
        for(int x=0; x<dimension; x++){
            for(int y=0; y<dimension; y++){
                B[x][y] = false;
            }
        }
        V.clear(); //Limpiamos el vector.
        decision = false; //Cambiamos el booleano para indicar que el juego acabó.
        return "Empate";
    }
    if(matriz[x][y] == N &&  B[x][y] == 0){ //Verificamos si la posición contiene el número ingresado.
        B[x][y] = true; //Cambiamos la posición a true en la matriz de booleanos.
        //Almacenamos la posición X o Y en el vector dependiendo del jugador que marcó.
        switch(N){
            case 1:
                V.push_back(x);
                break;
            case 2:
                V.push_back(y);
                break;
        }
        //Verificamos que la posición no esté en el borde superior o izquierdo.
        if(x != 0 && y != 0){
            //Revisamos si la casilla diagonal superior izquierda sirve para ganar.
            if(matriz[x-1][y-1] == N &&  B[x-1][y-1] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x-1,y-1,N,empate);
                }
            }
        //Verificamos que la posición no esté en el borde izquierdo.
        if(y != 0){
            //Revisamos si la casilla izquierda sirve para ganar.
            if(matriz[x][y-1] == N &&  B[x][y-1] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x,y-1,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde inferior o izquierdo.
        if(x != (dimension - 1) && y != 0){
            //Revisamos si la casilla diagonal inferior izquierda sirve para ganar.
            if(matriz[x+1][y-1] == N &&  B[x+1][y-1] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x+1,y-1,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde inferior.
        if(x != (dimension - 1)){
            //Revisamos si la casilla inferior sirve para ganar.
            if(matriz[x+1][y] == N &&  B[x+1][y] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x+1,y,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde inferior ni derecho.
        if(x != (dimension - 1) && y != (dimension - 1)){
            //Revisamos si la casilla diagonal inferior derecha sirve para ganar.
            if(matriz[x+1][y+1] == N &&  B[x+1][y+1] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x+1,y+1,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde derecho.
        if(y != (dimension - 1)){
            //Revisamos si la casilla derecha sirve para ganar.
            if(matriz[x][y+1] == N &&  B[x][y+1] == 0){
                //Hacemos la recursión con dicha casilla.
                return juzgar(decision,x,y+1,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde superior ni derecho.
        if(x != 0 && y != (dimension - 1)){
            //Revisamos si la casilla diagonal superior derecha sirve para ganar.
            if(matriz[x-1][y+1] == N &&  B[x-1][y+1] == 0){
                //Hacemos la recursión con dicha casilla.
                return juzgar(decision,x-1,y+1,N,empate);
            }
        }
        //Verificamos que la posición no esté en el borde superior.
        if(x != 0){
            //Revisamos si la casilla superior sirve para ganar.
            if(matriz[x-1][y] == N &&  B[x-1][y] == 0){
                //Hacemos recursión con dicha casilla.
                return juzgar(decision,x-1,y,N,empate);
            }
        }
    }
    //Verificamos si en el vector se guardaron las posiciones válidas para ganar.
    if(dentro(V,0) && dentro(V,(dimension - 1))){
        switch(N){
            case 1:
                //Cambiamos los elementos de la matriz booleana por false.
                for(int x=0; x<dimension; x++){
                    for(int y=0; y<dimension; y++){
                        B[x][y] = false;
                    }
                }
                V.clear(); //Limpiamos el vector.
                decision = false; //Cambiamos el booleano para indicar que el juego acabó.
                return "Gana el jugador 1";
                break;
            case 2:
                //Cambiamos los elementos de la matriz booleana por false.
                for(int x=0; x<dimension; x++){
                    for(int y=0; y<dimension; y++){
                        B[x][y] = false;
                    }
                }
                V.clear(); //Limpiamos el vector.
                decision = false; //Cambiamos el booleano para indicar que el juego acabó.
                return "Gana el jugador 2";
                break;
        }
    }
    else{
        V.clear(); //Limpiamos el vector.
        //Cambiamos los elementos de la matriz booleana por false.
        for(int x=0; x<dimension; x++){
            for(int y=0; y<dimension; y++){
                B[x][y] = false;
            }
        }
        return "";
    }
}

