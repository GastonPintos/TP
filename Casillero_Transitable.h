#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

using namespace std;

#include "Casillero.h"
#include "Materiales.h"


const char CASILLERO_TRANSITABLE = 'C';
const string DECLARACION_CASILLERO_TRANSITABLE = "Soy un casillero Transitable";

class Casillero_Transitable : public Casillero
{
    private:
        Edificio *edificio;
        Material *material;
    public:

        Casillero_Transitable( char dato, Coordenada ubi, Material * mat = nullptr ):Casillero(dato, ubi){ material=mat; };
        Material* get_material();
        Edificio * get_edificio( );

        void set_material( Material *mat);
        void set_edificio( Edificio *edif);

        void Mostrar( ostream &outStream );
        void consultar_casillero();

};



#endif