#include "Casillero_Inaccesible.h"

// Imprime por el flujo de salida  pasado por parametro el char que identifica al casillero construible
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Inaccesible::Mostrar( ostream &outStream ){ outStream << CASILLERO_INACCESIBLE;}

// Setea el valor del material contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Inaccesible::set_material( Material *mat){ material = nullptr;}

// Setea el valor del edificio contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Inaccesible::set_edificio( Edificio *edif){ edificio = nullptr; }

// Retorna el valor del edificio contenido en el casillero
// Pre: -
// Post: el edificio que contiene el casillero
Edificio * Casillero_Inaccesible::get_edificio( ){ return nullptr; }

// Retorna el valor del material contenido en el casillero
// Pre: -
// Post: el material que contiene el casillero
Material * Casillero_Inaccesible::get_material(){ return nullptr;}

// Imprime por el flujo de salida estandar el contenido del casillero
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Inaccesible::consultar_casillero(){ 
    cout << DECLARACION_CASILLERO_INACCESIBLE << endl; 
    cout << DECLARACION_CASILLERO_VACIO << endl;
}