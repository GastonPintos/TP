#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"

using namespace std;


#define CHAR_PLANTA_ELECTRICA 'p'
const string TIPO_MATERIAL_ENTREGADO_PLANTA = "Este edificio no brinda materiales";
const string PRIMER_NOMBRE_PLANTA_ELECTRICA = "planta";


class Planta_Electrica: public Edificio{
    private:

    public:
        Planta_Electrica(int piedra, int madera, int metal, int max_cant);
        void Mostrar();
        void cantidad_material_entregado();

        void Recurso(Registro_Material &lista_de_materiales);
};

#endif