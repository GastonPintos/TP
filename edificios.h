#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "coordenada.h"
#include "colors.h"
#include "vector.h"
#include "materiales.h"


const string PATH_EDIFICIOS = "edificios.txt";
const string DEMOLER = "demoler";
const string CONSTRUIR = "construir";

using namespace std;

class edificio{
    private:
        string nombre;
        int cantidad_piedra;
        int cantidad_madera;
        int cantidad_metal;
        int cantidad_construidos;
        int maxima_cantidad_permitidos;
        coordenada ubicacion;

    public:
        // Contructores:
        edificio(string nom, int piedra, int madera, int metal, int max_cant);
        edificio(const edificio &aux);
        
        // Getters:
        string get_nombre() {return nombre; };
        int get_piedra() { return cantidad_piedra; };
        int get_madera() { return cantidad_madera; };
        int get_metal() { return cantidad_metal; };
        int get_construidos() { return cantidad_construidos;};
        int get_maxpermitida() { return maxima_cantidad_permitidos; };
        coordenada get_ubicacion() { return ubicacion; };

        // Setters:
        void set_nombre( string nom ) { nombre = nom; };
        void set_piedra(  int pied ) { cantidad_piedra = pied; };
        void set_madera( int mad ) { cantidad_madera = mad; };
        void set_metal( int met ) { cantidad_metal = met; };
        void set_construidos( int constr ) { cantidad_construidos = constr; };
        void set_maxpermitida( int max_cant) { maxima_cantidad_permitidos = max_cant; };
        void set_ubicacion( coordenada coord) { ubicacion = coord; };

        edificio& operator=( const edificio & );

        // Impresion:
        friend ostream& operator<<(ostream& os, const edificio& edificio);

        //void PrintUbicacion(ostream &outStream){ outStream << nombre << " " << ubicacion; };

};


void insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado);
int buscar_pos_edificio_ingresado(string nombre_edificio_ingresado, vector<edificio*> &lista_de_edificios );
bool consultar_construccion();
void construir_edificio(string nombre_edificio_cons, vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios);
void listar_edificios_contruidos(vector<edificio*> &lista_de_edificios);
void listar_edificios_todos(vector<edificio*> &lista_de_edificios);
void demoler_edificio(string nombre,vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios);
void guardar_edificios( vector<edificio*> &lista_de_edificios );
void cargar_edificio(vector<edificio*> &lista);


#endif