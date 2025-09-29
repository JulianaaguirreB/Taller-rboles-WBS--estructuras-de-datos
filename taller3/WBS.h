#ifndef WBS_H
#define WBS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>  
#include "ArbolGeneral.h"
#include "NodoArbol.h"

using namespace std;

class WBS {
private:
    ArbolGeneral<NodoArbol> arbolGeneral;

    // Funciones auxiliares
    double calcularCostoRec(Nodogeneral<NodoArbol>* nodo);
    int calcularTiempoRec(Nodogeneral<NodoArbol>* nodo);
    bool buscarCamino(Nodogeneral<NodoArbol>* nodo, int idObjetivo, vector<NodoArbol>& camino);

public:
    WBS();

    
    void CargarArchivo(const string& nombreArchivo);

    
    double costoNodo(int id);
    int tiempoNodo(int id);
    double costoProyecto();
    int tiempoProyecto();

    
    void mostrarCamino(int id);
};

#endif // WBS_H
