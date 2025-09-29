#ifndef ARBOLGENERAL_H
#define ARBOLGENERAL_H

#include "Nodogeneral.h"
#include "NodoArbol.h"
#include <iostream>
using namespace std;

template <typename T>
class ArbolGeneral {
private:
    Nodogeneral<T>* raiz;

    void destruir(Nodogeneral<T>* nodo);
    int alturaRec(Nodogeneral<T>* nodo) const;
    int tamanoRec(Nodogeneral<T>* nodo) const;
    int ordenRec(Nodogeneral<T>* nodo) const;
    void eliminarRec(Nodogeneral<T>* padre, const T& n, bool& eliminado);


public:
    // Constructores y destructor
    ArbolGeneral();
    ArbolGeneral(T val);
    ArbolGeneral(Nodogeneral<T>* nodo);
    ArbolGeneral(const ArbolGeneral<T>& other);
    ~ArbolGeneral();

    // Operadores
    ArbolGeneral<T>& operator=(const ArbolGeneral<T>& other);

   
    bool esVacio() const;
    T obtenerRaiz() const;
    void fijarRaiz(T val);

    void insertarNodo(const T& padre, const T& n);
    void eliminarNodo(const T& n); 
    ArbolGeneral<T> subArbolN(const T& n); 

    int altura() const;
    int tamano() const;
    int orden() const;

    
    Nodogeneral<T>* getRaiz() const { return raiz; }

   
    Nodogeneral<T>* buscarId(Nodogeneral<T>* nodo, int id) const;
};

#include "ArbolGeneral.cpp"

#endif


