#ifndef REGISTRO_EDIFICIO_H
#define REGISTRO_EDIFICIO_H

#include <iostream>
#include <cstring>
#include <fstream>

#include "Aserradero.h"
#include "Planta_Electrica.h"
#include "Mina.h"
#include "Yacimiento.h"
#include "Obelisco.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Edificio.h"
#include "colors.h"
#include "Registro_Material.h"
#include "Coordenada.h"
#include "Mapa.h"

using namespace std;

const string RUTA_DATA_EDIFICIOS = "edificios.txt";
const string RUTA_UBICACION_EDIFICIOS = "ubicaciones.txt";

class Registro_Edificio{
    private:
        Edificio** registro_edificios;
        int cantidad;

    public:
        Registro_Edificio(){ registro_edificios=nullptr; cantidad =0; };
        Registro_Edificio( int cant){ cantidad=cant; registro_edificios = new Edificio*[cantidad]; };

        ~Registro_Edificio() { if(cantidad) delete [] registro_edificios; }; 


        Edificio** get_registro(){ return registro_edificios; };
        int get_cantidad(){ return cantidad; };
        
        void resize();
        void cargar_data_edificio(const string &input);
        void cargar_ubicacion_edificio(const string &input, Mapa &mapa_edificios);
        int buscar_ubicacion_edificio(Coordenada ubicacion, int pos_edificio);
        int buscar_pos_edificio(string nombre_edificio_ingresado);
        void borrar_ubicacion_edificio(Coordenada ubicacion, int pos_edificio);
        void construir_edificio(string nombre_edificio_cons, Registro_Material &registro_material, Mapa &mapa_edificios);
        void demoler_edificio(Registro_Material &registro_materiales, Mapa &mapa_edificios);
        void listar_edificios_contruidos();
        void listar_edificios_todos();
        void guardar( const string &output );
        void guardar_ubicacion( const string &output );
        bool consultar_construccion();
        void insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado);
        bool consultar_recursos_construccion( Registro_Material &registro_material, int pos_edificio, int pos_piedra, int pos_madera, int pos_metal);
        void recolectar_recursos_producidos(Registro_Material &registro_materiales);
        Edificio* obtener_edificio_por_nombre(string nombre,int cantidad_piedra = 0, int cantidad_madera=0, int cantidad_metal=0, int maxima_cantidad_permitidos=0);

};


#endif