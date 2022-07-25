#ifndef VECTOR_H
#define VECTOR_H

#define INIT_SIZE 4
#define PLUS_SIZE 1

using namespace std;


template< class T>
class vector{
    private:
        int cantidad;
        T *datos;
    public:
        vector();
        vector(const vector<T> &);
        ~vector();
        
        int get_cantidad();
        void resize();
        int get_posicion( string nombre);

        vector<T>& operator=( const vector<T> & );
        bool operator== (const vector<T> &);
        T& operator[] (int);
};

template<class T>
vector<T>::vector(){
    datos = new T[ INIT_SIZE ];
    cantidad = INIT_SIZE;
}

template<class T>
vector<T>::vector(const vector<T> &inicial){
    cantidad = inicial.cantidad;
    datos = new T[ cantidad ];
    for(int i=0; i<cantidad; i++)
        datos[i] = inicial.datos[i];
}

template<class T>
vector<T>::~vector(){
    if(datos)
        delete [] datos;
}

template<class T>
int vector<T>::get_cantidad(){
    return cantidad;
}

template<class T>
void vector<T>::resize(){

    int j, aux_cantidad;
    T *aux_datos;

    aux_cantidad = cantidad + PLUS_SIZE;
    aux_datos = new T[aux_cantidad];
            
    for( j=0; j < cantidad; j++){
        aux_datos[j] = datos[j];
    }
            
    cantidad = aux_cantidad;
    delete [] datos;
    datos = aux_datos;
}


template<class T>
vector<T>& vector<T>::operator=( const vector<T> & derecha){

    if(&derecha != this){
        
        if( cantidad != derecha.cantidad){

            T* aux;

            aux = new T[ derecha.cantidad];
            delete [] datos;
            cantidad = derecha.cantidad;
            datos = aux;

            for(int i=0; i< cantidad; i++)
            {
                datos[i] = derecha.datos[i];
            }
            return *this;
        }
        else
        {
            for(int i=0; i< cantidad; i++)
            {
                datos[i] = derecha.datos[i];
            }
            return *this;
        }
    }
    return *this;
}


template<class T>
bool vector<T>::operator== (const vector<T> & derecha){

    if( cantidad != derecha.cantidad)
        return false;
    else
    {
        for(int i=0; i< cantidad; i++)
            if( datos[i] != derecha.datos[i] )
                return false;
    }
    
    return true;
}

template<class T>
T& vector<T>::operator[] (int indice)
{
    return datos[ indice];
}


#endif