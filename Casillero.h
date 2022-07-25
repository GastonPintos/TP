#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <fstream>

#include "Coordenada.h"
#include "Materiales.h"
#include "Edificio.h"

using namespace std;

const string DECLARACION_CASILLERO_VACIO = "Me encuentro vacío";
const string DECLARACION_CONTENIDO = "Contengo en mi interior un ";

class Casillero
{
    private:
        char data;
        Coordenada ubicacion;
        
    public:
        Casillero( char dato, Coordenada ubi);

        char get_data();
        Coordenada get_ubicacion();

        void set_data( char dato );
        void set_ubicacion( Coordenada ubi );

        bool operator== (const Casillero &aux );
        bool operator!= (const Casillero &aux );
        
        Casillero& operator=( const Casillero & derecha);

        virtual void Mostrar( ostream &outStream ) = 0;

        virtual void set_edificio( Edificio *edif) = 0;
        virtual void set_material( Material *mat) = 0;

        virtual Edificio * get_edificio() = 0;
        virtual Material* get_material() = 0;

        virtual void consultar_casillero() = 0;
        
};

#endif