#ifndef R3_H
#define R3_H

template <class T>
class R3 {
private:
    T x, y;
    T z;
public:
    R3();
    R3(T x, T y, T z);
    double distancia(const R3<T> &otro) const;
    T getX() const;
    T getY() const;
    T getZ() const;
    void setX(T nuevoX);
    void setY(T nuevoY);
    void setZ(T nuevoZ);
};

#include "R3.cpp"

#endif

