#ifndef MAPA_H
#define MAPA_H

using namespace std;

#include "Vector.h"
#include "Casillero.h"

#include "colors.h"


const string RUTA_CASILLEROS_MAPA = "mapa.txt";
const string RUTA_UBICACION_MAPA = "ubicaciones.txt";

template<class T>
class Mapa
{
    private:
        int cant_filas;
        int cant_columnas;
        T**mapa;

    public:
        Mapa(){ cant_columnas=0; cant_filas=0; mapa=nullptr; };
        Mapa( int filas, int columnas );
        Mapa( const Mapa<T> &);
        ~Mapa();

        int get_filas(){ return cant_filas; };
        int get_columnas(){ return cant_columnas; };
        T** get_mapa() { return mapa; };

        void set_filas( int filas) { cant_filas = filas; };
        void set_columnas( int columnas) { cant_columnas = columnas; };
        void set_mapa(T**map) { mapa = map; };

        Mapa& operator=( const Mapa<T> & );
        bool operator== (const Mapa<T> &);

        void cargar_casilleros( const string &input);
    
};

template<class T>
Mapa<T>::Mapa( int filas, int columnas ){

     mapa = new T*[filas];

    for( int i=0; i < filas; i++)
    {
        mapa[i] = new T[columnas];
        mapa[i] = nullptr;
    }
}

template<class T>
Mapa<T>::Mapa(const Mapa<T> &inicial){
    int i,j;
    cant_columnas = inicial.cant_columnas;
    cant_filas = inicial.cant_filas;

    mapa = new T*[cant_filas];

    for( i=0; i < cant_filas; i++)
    {
        mapa[i] = new T[cant_columnas];
        mapa[i] = nullptr;
    }

    for ( i = 0; i < cant_filas; i++) {
        for ( j = 0; j < cant_columnas; j++) {
                mapa[i][j] = inicial.mapa[i][j];
        }
    }
}

template<class T>
Mapa<T>::~Mapa(){

    for (int i = 0; i < cant_filas; i++) {
        delete [] mapa[i];
    }
    delete [] mapa;

}

template<class T>
Mapa<T>& Mapa<T>::operator=( const Mapa<T> & derecha){

    int i,j;

    if(&derecha != this){
        
        if( cant_filas != derecha.cant_columnas || cant_filas != derecha.cant_columnas){

            T** aux;

            aux = new (T*)[derecha.cant_filas];

            for( i=0; i < derecha.cant_filas; i++)
            {
                aux[i] = new T[derecha.cant_columnas];
                aux[i] = nullptr;
            }

            for ( i = 0; i < cant_filas; i++) {
                delete [] mapa[i];
            }
            delete [] mapa;
           
            cant_filas = derecha.cant_filas;
            cant_columnas = derecha.cant_columnas;
            mapa = aux;

            for ( i = 0; i < cant_filas; i++) {
                for ( j = 0; j < cant_columnas; j++) {
                        mapa[i][j] = derecha.mapa[i][j];
                }
            }
            return *this;
        }
        else
        {
            for ( i = 0; i < cant_filas; i++) {
                for ( j = 0; j < cant_columnas; j++) {
                        mapa[i][j] = derecha.mapa[i][j];
                }
            }
            return *this;
        }
    }
    return *this;
}

template<class T>
bool Mapa<T>::operator== (const Mapa<T> & derecha){

    if( cant_filas != derecha.cant_filas || cant_columnas != derecha.cant_columnas)
        return false;
    else
    {
        for ( int i = 0; i < cant_filas; i++) {
            for (  int j = 0; j < cant_columnas; j++) {
                    if( mapa[i][j] != derecha.mapa[i][j])
                        return false;
            }
        }
    }
    
    return true;
}

template<class T>
void Mapa<T>::cargar_casilleros( const string &input){

    fstream archivo_edificios(input, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << input << END_COLOR << endl;
    }

    char dato;

    archivo_edificios >> cant_filas;
    archivo_edificios >> cant_columnas;

    Mapa aux(cant_filas, cant_columnas);
    
    for ( int i = 0; i < cant_filas; i++) {
        for ( int j = 0; j < cant_columnas; j++) {
                archivo_edificios >> dato;
                aux.mapa[i][j] = T(dato);
        }
    }

    archivo_edificios.close();
}


#endif