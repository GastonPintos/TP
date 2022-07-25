#include "Fabrica.h"

//Constructor de la clase Fabrica
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Fabrica
Fabrica::Fabrica(int piedra, int madera, int metal, int max_cant):Edificio( NOMBRE_FABRICA, piedra, madera, metal, max_cant){}

// Imprime el char caracteristico de la clase Fabrica
// Pre: -
// Post: -
void Fabrica::Mostrar(){ cout << CHAR_FABRICA; }

// Imprime el la cantidad de material que brinda
// Pre: -
// Post: -
void Fabrica::cantidad_material_entregado(){ cout << TIPO_MATERIAL_ENTREGADO_FABRICA;}

// Aumenta la cantidad del material que brinda el edificio al registro de materiales
// Pre: Registro de materiales 
// Post: -
void Fabrica::Recurso(Registro_Material &registro_materiales){
    int pos_metal = registro_materiales.buscar_pos_material(METAL);
        registro_materiales.get_registro()[pos_metal]->set_cantidad( registro_materiales.get_registro()[pos_metal]->get_cantidad() + get_construidos()*CANTIDAD_DE_RECURSOS_FABRICA );
}