#include "Yacimiento.h"

//Constructor de la clase Yacimiento
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Yacimiento
Yacimiento::Yacimiento(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_YACIMIENTO, piedra, madera, metal, max_cant){}

// Imprime el char caracteristico de la clase Yacimiento
// Pre: -
// Post: -
void Yacimiento::Mostrar(){ cout << CHAR_YACIMIENTO; }


// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Yacimiento::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_YACIMIENTO;}


// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Yacimiento::Recurso(Registro_Material &lista_de_materiales){return;}