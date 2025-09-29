#ifndef NODOGENERAL_H
#define NODOGENERAL_H
#include <cstddef>

template <class T>
class Nodogeneral {
private:
    T info;
    Nodogeneral<T>* primerHijo;
    Nodogeneral<T>* siguienteHermano;

public:
    
    Nodogeneral();
    Nodogeneral(const T& valor, Nodogeneral<T>* primerHijo = NULL, Nodogeneral<T>* siguienteHermano = NULL);
    ~Nodogeneral();

    const T& obtenerInfo() const;
    T& obtenerInfo();
    void fijarInfo(const T& valor);

    Nodogeneral<T>* obtenerPrimerHijo() const;
    Nodogeneral<T>* obtenerSiguienteHermano() const;
    void fijarPrimerHijo(Nodogeneral<T>* h);
    void fijarSiguienteHermano(Nodogeneral<T>* h);

    bool esHoja() const;
    bool agregarHijoAlFinal(Nodogeneral<T>* h);
};
#include "Nodogeneral.cpp"

#endif // NODOGENERAL_H

