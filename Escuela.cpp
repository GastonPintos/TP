#include "Escuela.h"

//Constructor de la clase Escuela
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Escuela
Escuela::Escuela(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_ESCUELA, piedra, madera, metal, max_cant){}

// Imprime el char caracteristico de la clase Escuela
// Pre: -
// Post: -
void Escuela::Mostrar(){ cout << CHAR_ESCUELA; }

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Escuela::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_ESCUELA;}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Escuela::Recurso(Registro_Material &lista_de_materiales){
    return;
}