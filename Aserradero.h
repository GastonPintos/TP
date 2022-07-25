#ifndef ASERRADERO_H
#define ASERRADERO_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"
#include "Registro_Material.h"

using namespace std;


#define CHAR_ASERRADERO 'A'
#define CANTIDAD_DE_RECURSOS_ASERRADERO 25

const string TIPO_MATERIAL_ENTREGADO_ASERRADERO = "Brinda 25 maderas";



class Aserradero :public Edificio{
    private:

    public:
        Aserradero(int piedra, int madera, int metal, int max_cant);
        
        void Mostrar();

        void cantidad_material_entregado();
        
        void Recurso(Registro_Material &registro_materiales);
};

#endif