#ifndef MAPA_H
#define MAPA_H

using namespace std;

#include "Casillero_Construible.h"
#include "Casillero_Inaccesible.h"
#include "Casillero_Transitable.h"
#include "colors.h"
#include "Materiales.h"


#define CANT_CASILLEROS 3

const string RUTA_CASILLEROS_MAPA = "mapa.txt";
const string RUTA_UBICACION_MAPA = "ubicaciones.txt";

const char diccionario_casilleros[CANT_CASILLEROS] = 
{
        CASILLERO_TRANSITABLE,
        CASILLERO_INACCESIBLE,
        CASILLERO_CONSTRUIBLE
};

typedef enum{

        TRANSITABLE,
        INACCESIBLE,
        CONSTRUIBLE

}casilleros_t;

class Mapa
{
    private:
        int cant_filas;
        int cant_columnas;
        Casillero***mapa;

    public:
        Mapa(){ cant_columnas=0; cant_filas=0; mapa=nullptr; };
        Mapa( int filas, int columnas );
        Mapa( const Mapa &);
        Mapa( const string &input);
        ~Mapa();

        int get_filas(){ return cant_filas; };
        int get_columnas(){ return cant_columnas; };
        Casillero*** get_mapa() { return mapa; };

        void set_filas( int filas) { cant_filas = filas; };
        void set_columnas( int columnas) { cant_columnas = columnas; };
        void set_mapa(Casillero***map) { mapa = map; };

        Mapa& operator=( const Mapa & );
        bool operator== (const Mapa &);
        
        bool consultar_limites_mapa(Coordenada ubicacion);
        bool consultar_ubicacion_construible( Coordenada ubicacion);
        Coordenada obtener_ubicacion();
        
        void consultar_informacion_casillero();
        void lluvia_recursos();

        //void cargar_ubicacion( const string &input);

        // Impresion:
        friend ostream& operator<<(ostream& os, const Mapa& map);
        void guardar(const string &output);
        void guardar_materiales(const string &output);
    
};

#endif