#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Coordenada.h"
#include "colors.h"
#include "Materiales.h"
#include "Registro_Material.h"

using namespace std;

#define CANT_EDIFICIOS 7

const string DEMOLER = "demoler";
const string CONSTRUIR = "construir";

const string NOMBRE_ASERRADERO = "aserradero";
const string NOMBRE_PLANTA_ELECTRICA = "planta electrica";
const string NOMBRE_MINA = "mina";
const string NOMBRE_YACIMIENTO = "yacimiento";
const string NOMBRE_OBELISCO = "obelisco";
const string NOMBRE_ESCUELA = "escuela";
const string NOMBRE_FABRICA = "fabrica";


const string nombres_edificios[CANT_EDIFICIOS] = 
{
        NOMBRE_ASERRADERO,
        NOMBRE_FABRICA,
        NOMBRE_ESCUELA,
        NOMBRE_YACIMIENTO,
        NOMBRE_OBELISCO,
        NOMBRE_MINA,
        NOMBRE_PLANTA_ELECTRICA
};

typedef enum{

        ASERRADERO,
        FABRICA,
        ESCUELA,
        YACIMIENTO,
        OBELISCO,
        MINA,
        PLANTA_ELECTRICA

}nombres_edificio_t;


class Edificio{
    private:
        string nombre;
        int cantidad_piedra;
        int cantidad_madera;
        int cantidad_metal;
        int cantidad_construidos;
        int maxima_cantidad_permitidos;
        Coordenada* ubicacion;

    public:
        // Contructores:
        Edificio(string nom, int piedra, int madera, int metal, int max_cant);
        Edificio(const Edificio &aux);
        
        // Getters:
        string get_nombre() {return nombre; };
        int get_piedra() { return cantidad_piedra; };
        int get_madera() { return cantidad_madera; };
        int get_metal() { return cantidad_metal; };
        int get_construidos() { return cantidad_construidos;};
        int get_maxpermitida() { return maxima_cantidad_permitidos; };
        Coordenada* get_ubicacion() { return ubicacion; };

        // Setters:
        void set_nombre( string nom ) { nombre = nom; };
        void set_piedra(  int pied ) { cantidad_piedra = pied; };
        void set_madera( int mad ) { cantidad_madera = mad; };
        void set_metal( int met ) { cantidad_metal = met; };
        void set_construidos( int constr ) { cantidad_construidos = constr; };
        void set_maxpermitida( int max_cant) { maxima_cantidad_permitidos = max_cant; };
        void set_ubicacion( Coordenada coord, int cantidad_construidos) { ubicacion[cantidad_construidos] = coord; };

        Edificio& operator=( const Edificio & );

        // Impresion:
        friend ostream& operator<<(ostream& os, const Edificio& edificio);
        //void PrintUbicacion(ostream &outStream){ outStream << nombre << " " << ubicacion; };


        //Metodo Virtual:
        virtual void Mostrar() = 0;
        virtual void cantidad_material_entregado() = 0;
        virtual void Recurso(Registro_Material &registro_materiales) = 0;
};

#endif