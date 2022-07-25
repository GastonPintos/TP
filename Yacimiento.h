#ifndef YACIMIENTO_H
#define YACIMIENTO_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"

using namespace std;


#define CHAR_YACIMIENTO 'Y'
const string TIPO_MATERIAL_ENTREGADO_YACIMIENTO = "Este edificio no brinda materiales";


class Yacimiento: public Edificio{
    private:

    public:
        Yacimiento(int piedra, int madera, int metal, int max_cant);
        void Mostrar();
        void cantidad_material_entregado();

        void Recurso(Registro_Material &lista_de_materiales);
};

#endif