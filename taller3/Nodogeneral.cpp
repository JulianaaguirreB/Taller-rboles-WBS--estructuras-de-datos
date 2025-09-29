#include "NodoGeneral.h"
#include "NodoArbol.h"

template <class T>
Nodogeneral<T>::Nodogeneral(){
        this->info=nullptr;
        this->primerHijo=nullptr;
        this->siguienteHermano=nullptr;
    }




template <class T>
Nodogeneral<T>::Nodogeneral(const T& info, Nodogeneral<T>* pHijo, Nodogeneral<T>* sHermano){
        this->info=info;
        this->primerHijo=pHijo;
        this->siguienteHermano=sHermano;
    }

template <class T>
Nodogeneral<T>::~Nodogeneral() = default;

template <class T>
const T& Nodogeneral<T>::obtenerInfo() const { return info; }

template <class T>
T& Nodogeneral<T>::obtenerInfo() { return info; }

template <typename T>
void Nodogeneral<T>::fijarInfo(const T& valor) { info = valor; }

template <class T>
Nodogeneral<T>* Nodogeneral<T>::obtenerPrimerHijo() const { return primerHijo; }

template <class T>
Nodogeneral<T>* Nodogeneral<T>::obtenerSiguienteHermano() const { return siguienteHermano; }

template <class T>
void Nodogeneral<T>::fijarPrimerHijo(Nodogeneral<T>* h) { primerHijo = h; }

template <class T>
void Nodogeneral<T>::fijarSiguienteHermano(Nodogeneral<T>* h) { siguienteHermano = h; }

template <class T>
bool Nodogeneral<T>::esHoja() const { return primerHijo == nullptr; }

template <class T>
bool Nodogeneral<T>::agregarHijoAlFinal(Nodogeneral<T>* h) {
    if (h == nullptr || h == this) return false;
    h->fijarSiguienteHermano(nullptr);
    if (primerHijo == nullptr) { primerHijo = h; return true; }
    Nodogeneral<T>* actual = primerHijo;
    while (actual->obtenerSiguienteHermano() != nullptr) {
        actual = actual->obtenerSiguienteHermano();
    }
    actual->fijarSiguienteHermano(h);
    return true;
}

