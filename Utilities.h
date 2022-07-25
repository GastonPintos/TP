#ifndef UTILITIES_H
#define UTILITIES_H

#include "Aserradero.h"
#include "Planta_Electrica.h"
#include "Mina.h"
#include "Yacimiento.h"
#include "Obelisco.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Edificio.h"

const string RUTA_DATA_EDIFICIOS = "edificios.txt";
const string RUTA_UBICACION_EDIFICIOS = "ubicacion.txt";


void insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado);
int buscar_pos_edificio_ingresado(string nombre_edificio_ingresado, vector<Edificio*> &lista_de_edificios );
bool consultar_construccion();
void construir_edificio(string nombre_edificio_cons, vector<Material*> &lista_de_materiales,  vector<Edificio*> &lista_de_edificios);
void listar_edificios_contruidos(vector<Edificio*> &lista_de_edificios);
void listar_edificios_todos(vector<Edificio*> &lista_de_edificios);
void demoler_edificio(string nombre,vector<Material*> &lista_de_materiales,  vector<Edificio*> &lista_de_edificios);
void guardar_edificios( vector<Edificio*> &lista_de_edificios );
void cargar_data_edificio(vector<Edificio*> &lista);
void cargar_ubicacion_edificio(vector<Edificio*> &lista);


#endif