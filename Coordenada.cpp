#include "Coordenada.h"
//Constructor de la clase Coordenada inicilizada en 0
// Pre: -
// Post: Objeto Coordenada
Coordenada::Coordenada(){horizontal=0; vertical=0;}

//Constructor de la clase Coordenada inicilizada en los parametros numericos
// Pre: Valores naturales
// Post: Objeto Coordenada
Coordenada::Coordenada(int horizontal, int vertical) {horizontal=horizontal; vertical=vertical;}

//Constructor de la clase Coordenada inicilizada en los parametros pasados como string
// Pre: Strings con valores numericos
// Post: Objeto Coordenada
Coordenada::Coordenada(string horiz, string vert) {horizontal=stoi(horiz); vertical=stoi(vert);}

// Retorna el valor de la coordenada horizontal
// Pre: -
// Post: el valor de la coordenada horizontal
int Coordenada::GetHorizontal(){ return horizontal; }

// Retorna el valor de la coordenada vertical
// Pre: -
// Post: el valor de la coordenada vertical
int Coordenada::GetVertical() { return vertical; }

// Setea el valor de la coordenada horizontal
// Pre: el valor de la coordenada horizontal
// Post: -
void Coordenada::SetHorizontal(int hor) { horizontal = hor;}

// Setea el valor de la coordenada vertical
// Pre: el valor de la coordenada vertical
// Post: -
void Coordenada::SetVertical(int ver ) { vertical = ver;}

// Sobrecarga del operador == para comparar coordeanada
// Pre: Una Coordenada debe esatr bien formado
// Post: Un booleano que identifica si son iguales
bool Coordenada::operator== (const Coordenada &coord){ if(horizontal!=coord.horizontal || vertical!=coord.vertical) return false; else return true; }

// Sobrecarga del operador != para comparar coordeanada
// Pre: Una Coordenada debe esatr bien formado
// Post: Un booleano que identifica si son distintos
bool Coordenada::operator!= (const Coordenada &coord){ if(horizontal!=coord.horizontal || vertical!=coord.vertical) return true; else return true; }