#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <string>

class NodoArbol
{
    private:
    int id;
    std::string descripcion;
    double costo;
    int tiempo;

    public:
    NodoArbol();
    NodoArbol(int id, const std::string& descripcion, double costo, int tiempo);

    int obtenerId() const;
    const std::string& obtenerDescripcion() const;
    double obtenerCosto() const;
    int obtenerTiempo() const;

    void fijarId(int id);
    void fijarDescripcion(const std::string& descripcion);
    void fijarCosto(double costo);
    void fijarTiempo(int tiempo);

};

#endif // NODOARBOL_H
