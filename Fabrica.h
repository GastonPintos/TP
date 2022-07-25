#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"
#include "Registro_Material.h"

using namespace std;


#define CHAR_FABRICA 'F'
#define CANTIDAD_DE_RECURSOS_FABRICA 40
const string TIPO_MATERIAL_ENTREGADO_FABRICA = "Brinda 40 metales";


class Fabrica: public Edificio{
    private:

    public:
        Fabrica(int piedra, int madera, int metal, int max_cant);
        void Mostrar();

        void cantidad_material_entregado();

        void Recurso(Registro_Material &registro_materiales);
};

#endif