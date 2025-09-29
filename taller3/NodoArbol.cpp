#include "NodoArbol.h"


NodoArbol::NodoArbol(){
    this->id=0;
    this->descripcion="";
    this->costo=0.0;
    this->tiempo=0;
    }

NodoArbol::NodoArbol(int id, const std::string& descripcion, double costo, int tiempo){
    this->id=id;
    this->descripcion=descripcion;
    this->costo=costo;
    this->tiempo=tiempo;
    }

int NodoArbol::obtenerId() const { return id; }
const std::string& NodoArbol::obtenerDescripcion() const { return descripcion; }
double NodoArbol::obtenerCosto() const { return costo; }
int NodoArbol::obtenerTiempo() const { return tiempo; }


void NodoArbol::fijarId(int id) { id = id; }
void NodoArbol::fijarDescripcion(const std::string& descri) { descripcion = descri; }
void NodoArbol::fijarCosto(double c) { costo = c; }
void NodoArbol::fijarTiempo(int t) { tiempo = t; }
