#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H


#include <iostream>
#include <fstream>

#include "Casillero.h"


using namespace std;

const char CASILLERO_CONSTRUIBLE = 'T';
const string DECLARACION_CASILLERO_CONSTRUIBLE = "Soy un casillero construible";

class Casillero_Construible : public Casillero
{
    private:
        Edificio *edificio;
        Material *material;

    public:

        Casillero_Construible( char dato, Coordenada ubi, Edificio * edif = nullptr):Casillero(dato, ubi){edificio=edif; };

        Edificio *get_edificio();
        Material *get_material();

        void set_material( Material *mat);
        void set_edificio( Edificio *edif);
        void Mostrar( ostream &outStream );

        void consultar_casillero();
};



#endif