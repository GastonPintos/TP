#include "Aserradero.h"

//Constructor de la clase Aserradero
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Aserradro
Aserradero::Aserradero(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_ASERRADERO, piedra, madera, metal, max_cant){}


// Imprime el char caracteristico de la clase Aserradero
// Pre: -
// Post: -
void Aserradero::Mostrar(){ 
    cout << CHAR_ASERRADERO; 
}

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Aserradero::cantidad_material_entregado(){ 
    cout << TIPO_MATERIAL_ENTREGADO_ASERRADERO;
}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Aserradero::Recurso(Registro_Material &registro_materiales){
    int pos_madera = registro_materiales.buscar_pos_material(MADERA);
    registro_materiales.get_registro()[pos_madera]->set_cantidad( registro_materiales.get_registro()[pos_madera]->get_cantidad() + get_construidos()*CANTIDAD_DE_RECURSOS_ASERRADERO );
}