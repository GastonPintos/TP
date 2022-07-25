#ifndef MINA_H
#define MINA_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"

using namespace std;


#define CHAR_MINA 'M'
#define CANTIDAD_DE_RECURSOS_MINA 15
const string TIPO_MATERIAL_ENTREGADO_MINA = "Brinda 15 piedras";


class Mina: public Edificio{
    private:

    public:
        Mina(int piedra, int madera, int metal, int max_cant);
        void Mostrar();
        void cantidad_material_entregado();

         void Recurso(Registro_Material &registro_materiales);
};

#endif