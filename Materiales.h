#ifndef MATERIALES_H
#define MATERIALES_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "colors.h"
#include "vector.h"

const string PATH_MATERIALES = "materiales.txt";
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";
const int ERROR = -1;

using namespace std;

class material{
    private:
        string nombre;
        int cantidad;

    public:
        material( string nom, int cant){ nombre=nom; cantidad=cant; };
        material(const material &aux){ nombre = aux.nombre; cantidad = aux.cantidad; };
        
        // Geetters:
        string get_nombre(){ return nombre; };
        int get_cantidad(){ return cantidad; };

        // Setters:
        void set_nombre( string nom ){ nombre=nom; };
        void set_cantidad( int cant){ cantidad = cant; };

        material& operator=( const material & derecha){

            if(&derecha != this){
                
                nombre = derecha.nombre;
                cantidad = derecha.cantidad;
            }
            return *this;
        };

        friend ostream& operator<<(ostream& os, const material& material){
            os << material.nombre << " " << "[" << material.cantidad << "]";
            return os;
        };
};

void listar_materiales_de_construccion(vector<material*> &lista_de_materiales);
int buscar_pos_material(string nombre_material_a_buscar, vector<material*> &lista_de_materiales);
void guardar_materiales(vector<material*> &lista_de_materiales);
void cargar_material(vector<material*> &lista);


#endif