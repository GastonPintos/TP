#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

using namespace std;

#include "Casillero.h"

const char CASILLERO_INACCESIBLE = 'L';
const string DECLARACION_CASILLERO_INACCESIBLE = "0soy un casillero construible";


class Casillero_Inaccesible : public Casillero
{
    private:
        Edificio *edificio;
        Material *material;

    public:

        Casillero_Inaccesible( char dato, Coordenada ubi ):Casillero(dato, ubi){};

        void Mostrar( ostream &outStream );

        void set_material( Material *mat);
        void set_edificio( Edificio *edif);

        Edificio * get_edificio( );
        Material *get_material();

        void consultar_casillero();
};


#endif