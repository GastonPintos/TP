#include "Obelisco.h"

//Constructor de la clase Obelisco
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Obelisco
Obelisco::Obelisco(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_OBELISCO, piedra, madera, metal, max_cant){}

// Imprime el char caracteristico de la clase Obelisco
// Pre: -
// Post: -
void Obelisco::Mostrar(){ cout << CHAR_OBELISCO; }

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Obelisco::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_OBELISCO;}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Obelisco::Recurso(Registro_Material &lista_de_materiales){
    return;
}