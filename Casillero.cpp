#include "Casillero.h"

// Constructor de la clase Casillero
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Casillero
Casillero::Casillero( char dato, Coordenada ubi) {data=dato; ubicacion=ubi; }

// Retorna el valor del dato contenido en el casillero
// Pre: -
// Post: char que caracteriza el casillero
char Casillero::get_data(){ return data;}

// Retorna la ubicacion del casillero
// Pre: -
// Post: ubicacion que localiza al casillero
Coordenada Casillero::get_ubicacion(){ return ubicacion; }

// Setea el valor del dato contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero::set_data( char dato ){ data = dato;}

// Retorna la ubicacion del casillero
// Pre: ubicacion que localiza al casillero
// Post: -
void Casillero::set_ubicacion( Coordenada ubi ){ ubicacion = ubi;}

// Sobrecarga del operador == para comparar casilleros
// Pre: El casillero debe estar bien formado
// Post: Un booleano que identifica si son iguales
bool Casillero::operator== (const Casillero &aux ){ 
    if( data != aux.data ) 
        return false; 
    else return true;
}

// Sobrecarga del operador != para comparar casilleros
// Pre: El casillero debe esatr bien formado
// Post: Un booleano que identifica si son distintos
bool Casillero::operator!= (const Casillero &aux ){ 
    if( data != aux.data ) 
        return true; 
    else return true;
}

// Sobrecarga del operador = para formar casilleros
// Pre: El casillero debe esatr bien formado
// Post: Un casillero formado
Casillero& Casillero::operator=( const Casillero & derecha){
    if(&derecha != this){             
        if( data != derecha.data){
            data = derecha.data;
            return *this;
        }
        else
        {
            data = derecha.data;
            return *this;
        }
    }
    return *this;
}