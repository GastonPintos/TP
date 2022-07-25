#include "Mina.h"

//Constructor de la clase Mina
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Mina
Mina::Mina(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_MINA, piedra, madera, metal, max_cant){}


// Imprime el char caracteristico de la clase Mina
// Pre: -
// Post: -
void Mina::Mostrar(){ cout << CHAR_MINA; }

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Mina::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_MINA;}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Mina::Recurso(Registro_Material &registro_materiales){
    int pos_piedra = registro_materiales.buscar_pos_material(PIEDRA);
        registro_materiales.get_registro()[pos_piedra]->set_cantidad( registro_materiales.get_registro()[pos_piedra]->get_cantidad() + get_construidos()*CANTIDAD_DE_RECURSOS_MINA );
}