#ifndef UTILES__H
#define UTILES__H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>


#include "colors.h"
#include "materiales.h"
#include "edificios.h"
#include "vector.h"

using namespace std;

const int LISTAR_MATERIALES_DE_CONSTRUCCION = 1;
const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 2;
const int LISTAR_LOS_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_LOS_EDIFICIOS= 4;
const int DEMOLER_UN_EDIFICIO_POR_NOMBRE = 5;
const int GUARDAR_Y_SALIR = 6;
const int ERROR = -1;
const int SALIR = 7;


const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const int CANTIDAD_DE_OPCIONES_VALIDAS = 6;
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";
const string DEMOLER = "demoler";
const string CONSTRUIR = "construir";

//Pre: El menú fue creado
//Post: Se muestra el menú
void mostrar_menu();

//Pre: Recibe un int* opcion_elegida para guardar la opción elegida por el usuario
//Post: Se pide una opción al usuario
void pedir_opcion(int* opcion_elegida);

//Pre: La opción fue previamente elegida
//Post: Se validó la opción elegida
void validar_opcion_elegida(int* opcion_elegida);

//Pre: La lista de materiales fue creada
//Post: Se listaron los materiales de contrucción
void listar_materiales_de_construccion(vector<material*> &lista_de_materiales);

//Pre: Recibe por parámetro un string* nombre_edificio-ingresado para guardar el nombre que inserta el usuario
//Post: Se guardó el nombre del edificio ingresado por el usuario en nombre_edificio_ingresado 
void insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado);

//Pre: La lista de edificios fue creada y se ingresó el nombre del edificio
//Post: Se buscó la posición del edificio ingresado
int buscar_pos_edificio_ingresado(string* nombre_edificio_ingresado, vector<edificio*> &lista_de_edificios);

//Pre: La lista de materiales fue creada, se recibe por parámetro el material del que se desea saber la posición
//Post: Se buscó la posición del material
int buscar_pos_material(string nombre_material_a_buscar,vector<material*> &lista_de_materiales);

//Pre: El usuario decidió construir 
//Post: Se le consultó al usuario si confirmaba la construcción
bool consultar_construccion();

//Pre: Se inserta el nombre del edificio a contruir, la lista de materiales y edificios ya fueron creadas.
//Post: Se construye el edificio si se cumple con las condiciones requeridas para construirlo
void construir_edificio(string* nombre_edificio_cons,  vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios);

//Pre: La lista de edificios fue creada
//Post: Se listan los edificios construídos
void listar_edificios_contruidos(vector<edificio*> &lista_de_edificios);

//Pre: La lista de edificios fue creada
//Post: Se listan todos los edificios 
void listar_edificios_todos(vector<edificio*> &lista_de_edificios);

//Pre: Se inserta el nombre del edificio a demoler, la lista de materiales y edificios ya fueron creadas.
//Post: Se demolió el edificio devolviendo la cantidad de materiales correspondiente
void demoler_edificio(string nombre,vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios);

//Pre: La lista de materiales y edificios ya fueron creadas, el usuario eligió una opción
//Post: Se procesa la opción elegida por el usuario
void procesar_opcion_elegida(vector<material*> &lista_de_materiales, vector<edificio*> &lista_de_edificios, int *opcion);

//Pre: La lista de materiales y edificios ya fueron creadas
//Post: Se guardan los materiales y los edificios
void guardar(vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios);

//Pre: La lista de materiales ya fue creada
//Post: Se guardan los materiales
void guardar_materiales(vector<material*> &lista_de_materiales);

//Pre: La lista de edificios ya fue creada
//Post: Se guardan los edificios
void guardar_edificios(vector<edificio*> &lista_de_edificios);


//Pre: La lista de materiales ya fue creada
//Post: Se carga el material
void cargar_material(vector<material*> &lista);

/*
//Pre: La lista de materiales ya fue creada
//Post: Se agrega el material a la lista
void agregar_material(lista_materiales* lista, material* mat);

//Pre: La lista de edificios ya fue creada
//Post: Se agrega el edificio a la lista
void agregar_edificio(lista_edificios* lista, edificio* Edificio);
*/

//Pre: La lista de edificios ya fue creada
//Post: Se carga el edificio
void cargar_edificio(vector<edificio*> &lista);

#endif



