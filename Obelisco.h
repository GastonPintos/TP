#ifndef OBELISCO_H
#define OBELISCO_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "Edificio.h"

using namespace std;


#define CHAR_OBELISCO 'O'

const string TIPO_MATERIAL_ENTREGADO_OBELISCO = "Este edificio no brinda materiales";


class Obelisco: public Edificio{
    private:

    public:
        Obelisco(int piedra, int madera, int metal, int max_cant);
        void Mostrar();
        void cantidad_material_entregado();

        void Recurso(Registro_Material &lista_de_materiales);
};

#endif