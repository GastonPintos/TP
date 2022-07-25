#include "Casillero_Construible.h"

// Retorna el valor del edificio contenido en el casillero
// Pre: -
// Post: el edificio que contiene el casillero
Edificio *Casillero_Construible::get_edificio(){ return edificio; }

// Retorna el valor del material contenido en el casillero
// Pre: -
// Post: el material que contiene el casillero
Material *Casillero_Construible::get_material(){ return nullptr;}

// Setea el valor del material contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Construible::set_material( Material *mat){ material = nullptr;}

// Setea el valor del edificio contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Construible::set_edificio( Edificio *edif){ edificio = edif; }

// Imprime por el flujo de salida  pasado por parametro el char que identifica al casillero construible
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Construible::Mostrar( ostream &outStream ){ outStream << CASILLERO_CONSTRUIBLE;}

// Imprime por el flujo de salida estandar el contenido del casillero
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Construible::consultar_casillero(){ 
    cout << DECLARACION_CASILLERO_CONSTRUIBLE<< endl; 
    if(edificio == nullptr) 
        cout << DECLARACION_CASILLERO_VACIO << endl;
    else
        cout << DECLARACION_CONTENIDO << edificio->get_nombre() << endl;
}