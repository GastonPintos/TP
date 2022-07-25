#include "PLanta_Electrica.h"

//Constructor de la clase Planta_Electrica
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Planta_Electrica
Planta_Electrica::Planta_Electrica(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_PLANTA_ELECTRICA, piedra, madera, metal, max_cant){}

// Imprime el char caracteristico de la clase Planta_Electrica
// Pre: -
// Post: -
void Planta_Electrica::Mostrar(){ cout << CHAR_PLANTA_ELECTRICA; }

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Planta_Electrica::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_PLANTA;}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Planta_Electrica::Recurso(Registro_Material &lista_de_materiales){return;}