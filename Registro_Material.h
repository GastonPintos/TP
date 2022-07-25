#ifndef REGISTRO_MATERIAL_H
#define REGISTRO_MATERIAL_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "colors.h"
#include "Materiales.h"

const string RUTA_MATERIALES = "materiales.txt";

const int ERROR = -1;

class Registro_Material
{
    private:
        Material** registro_material;
        int cantidad;

    public:
        Registro_Material(){ registro_material=nullptr; cantidad =0; };
        Registro_Material( int cant){ cantidad=cant; registro_material = new Material*[cantidad]; };

        ~Registro_Material() { if(cantidad){ delete [] registro_material;} }; 

        Material** get_registro(){ return registro_material; };
        int get_cantidad(){ return cantidad; };

        void resize();
        void cargar_material(const string &input);
        void guardar(const string &output);
        int buscar_pos_material(string nombre_material);
        void listar_materiales_de_construccion();
};

#endif