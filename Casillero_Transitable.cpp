#include "Casillero_Transitable.h"

// Retorna el valor del material contenido en el casillero
// Pre: -
// Post: el material que contiene el casillero
Material* Casillero_Transitable::get_material(){ return material; }

// Retorna el valor del edificio contenido en el casillero
// Pre: -
// Post: el edificio que contiene el casillero
Edificio * Casillero_Transitable::get_edificio( ){ return nullptr; }

// Setea el valor del material contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Transitable::set_material( Material *mat){ material = mat;}

// Setea el valor del edificio contenido en el casillero
// Pre: El valor que desea guardar en el casillero
// Post: -
void Casillero_Transitable::set_edificio( Edificio *edif){ edificio = nullptr; }

// Imprime por el flujo de salida  pasado por parametro el char que identifica al casillero construible
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Transitable::Mostrar( ostream &outStream ){ outStream << CASILLERO_TRANSITABLE; }

// Imprime por el flujo de salida estandar el contenido del casillero
// Pre: Un flujo de salida abierto
// Post: -
void Casillero_Transitable::consultar_casillero(){ 
    cout << DECLARACION_CASILLERO_TRANSITABLE<< endl; 
    if(material == nullptr) 
        cout << DECLARACION_CASILLERO_VACIO << endl;
    else
        cout << DECLARACION_CONTENIDO << material->get_nombre() << endl;
}