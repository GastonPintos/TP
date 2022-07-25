#include "Edificio.h"


// Constructor de la clase Edificio
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Edificio
Edificio::Edificio(string nom, int piedra, int madera, int metal, int max_cant)
{
    nombre = nom; 
    cantidad_piedra = piedra; 
    cantidad_madera = madera; 
    cantidad_metal = metal; 
    cantidad_construidos = 0;
    maxima_cantidad_permitidos = max_cant;
    ubicacion = new Coordenada[max_cant];
}

// Constructor de la clase Edificio
// Pre: Objeto Edificio bien formado
// Post: Objeto Edificio
Edificio::Edificio(const Edificio &aux)
{
    nombre = aux.nombre; 
    cantidad_piedra = aux.cantidad_piedra; 
    cantidad_madera = aux.cantidad_madera; 
    cantidad_metal = aux.cantidad_metal; 
    cantidad_construidos = aux.cantidad_construidos;
    maxima_cantidad_permitidos = aux.maxima_cantidad_permitidos;
    ubicacion = aux.ubicacion;
}

// Sobrecarga del operador = para formar Edificios
// Pre: El Edificio debe esatr bien formado
// Post: Un Edificio formado
Edificio& Edificio::operator=( const Edificio & derecha){

    if( &derecha != this){
        
        nombre = derecha.nombre; 
        cantidad_piedra = derecha.cantidad_piedra; 
        cantidad_madera = derecha.cantidad_madera; 
        cantidad_metal = derecha.cantidad_metal; 
        cantidad_construidos = derecha.cantidad_construidos;
        maxima_cantidad_permitidos = derecha.maxima_cantidad_permitidos;
        ubicacion = derecha.ubicacion;
    }
    return *this;
}

// Sobrecarga del operador << para imprimir Edificios en el flujo de salida indicado
// Pre: El Edificio debe esatr bien formado y el flujo de salida abierto previamente
// Post: Un flujo de salida donde se imprimio la informacion de la clase
ostream& operator<<(ostream& os, const Edificio& edificio){
    
    os << edificio.nombre << " "; 
    os << edificio.cantidad_piedra << " "; 
    os << edificio.cantidad_madera << " "; 
    os << edificio.cantidad_metal << " "; 
    os << edificio.maxima_cantidad_permitidos << " "; 
    return os;

}
