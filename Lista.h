#ifndef LISTA__H
#define LISTA__H

using namespace std;

template < class T >
class Nodo:
{
    private:
        T dato;
        Nodo * sig;

    public:
        Nodo(){ T=0; sig = nullptr; };
        Nodo( const Nodo<T> & Nod){ Dato = Nod.dato; sig=Nod.sig; };
        ~Nodo(){ if(dato) delete dato; sig = nullptr; };

        T GetDato(){ return Dato; };
        Nodo* GetSig(){ return sig; };

        


}

template < class T > 
class Lista:
{
    private:
        Nodo *lista;
        size_t cantidad;

    public:
        Lista(){ lista=nullptr; cantidad=0; };
        Lista()(const Lista<T> &aux){ lista = aux.lista; cantidad = aux.cantidad; };
        ~Lista(){   };

}

#endif