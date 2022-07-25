#ifndef MENU__H
#define MENU__H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "colors.h"
#include "Registro_Edificio.h"
#include "Registro_Material.h"

#define CANTIDAD_INICIAL 4

using namespace std;

const int CANTIDAD_DE_OPCIONES_VALIDAS = 10;
const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_LOS_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_LOS_EDIFICIOS= 3;
const int DEMOLER_UN_EDIFICIO_POR_COORDENADA = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
const int LLUVIA_DE_RECURSOS = 9;
const int GUARDAR_Y_SALIR = 10;
const int SALIR = 11;




void mostrar_menu();
void pedir_opcion(int* opcion_elegida);
void validar_opcion_elegida(int* opcion_elegida);
void procesar_opcion_elegida(Registro_Material &registro_material, Registro_Edificio &registro_edificio, int *opcion,Mapa &mapa_edificios);

#endif