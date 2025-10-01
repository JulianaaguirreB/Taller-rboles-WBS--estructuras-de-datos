#include "R3.h"
#include <cmath>

template <class T>
R3<T>::R3() {
    x = 0;
    y = 0;
    z = 0;
}


template <class T>
R3<T>::R3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}


template <class T>
void R3<T>::setX(T nuevoX) { x = nuevoX; }
template <class T>
void R3<T>::setY(T nuevoY) { y = nuevoY; }
template <class T>
void R3<T>::setZ(T nuevoZ) { z = nuevoZ; }


template <class T>
T R3<T>::getX() const { return x; }
template <class T>
T R3<T>::getY() const { return y; }
template <class T>
T R3<T>::getZ() const { return z; }

template <class T>
double R3<T>::distancia(const R3<T> &otro) const {
    double dx = otro.x - x;
    double dy = otro.y - y;
    double dz = otro.z - z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

