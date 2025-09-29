#include "WBS.h"
#include <unordered_map>
#include <vector>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

WBS::WBS() {}

void WBS::CargarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    unordered_map<int, NodoArbol> nodos;
    vector<pair<int,int>> relaciones;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        int id, idPadre, tiempo;
        double costo;
        string descripcion;

        ss >> id >> idPadre;

        
        string resto;
        getline(ss, resto);
        stringstream ss2(resto);

        vector<string> partes;
        string token;
        while (ss2 >> token) partes.push_back(token);

        if (partes.size() < 3) continue; 

        
        tiempo = stoi(partes.back());
        partes.pop_back();
        costo = stod(partes.back());
        partes.pop_back();

       
        descripcion.clear();
        for (size_t i = 0; i < partes.size(); i++) {
            if (i > 0) descripcion += " ";
            descripcion += partes[i];
        }

        NodoArbol nodo(id, descripcion, costo, tiempo);
        nodos[id] = nodo;
        relaciones.push_back(make_pair(id, idPadre));
    }
    archivo.close();

    
    for (auto& rel : relaciones) {
        int id = rel.first;
        int idPadre = rel.second;

        if (idPadre == -1) {
            arbolGeneral.fijarRaiz(nodos[id]);
        } else {
            arbolGeneral.insertarNodo(nodos[idPadre], nodos[id]);
        }
    }
}


double WBS::calcularCostoRec(Nodogeneral<NodoArbol>* nodo) {
    if (!nodo) return 0;
    double suma = nodo->obtenerInfo().obtenerCosto();

    for (Nodogeneral<NodoArbol>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        suma += calcularCostoRec(h);
    }
    return suma;
}

int WBS::calcularTiempoRec(Nodogeneral<NodoArbol>* nodo) {
    if (!nodo) return 0;
    int suma = nodo->obtenerInfo().obtenerTiempo();

    for (Nodogeneral<NodoArbol>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        suma += calcularTiempoRec(h);
    }
    return suma;
}


double WBS::costoNodo(int id) {
    Nodogeneral<NodoArbol>* nodo = arbolGeneral.buscarId(arbolGeneral.getRaiz(), id);
    if (!nodo) {
        cout << "Nodo con id " << id << " no encontrado" << endl;
        return 0;
    }
    return calcularCostoRec(nodo);
}

int WBS::tiempoNodo(int id) {
    Nodogeneral<NodoArbol>* nodo = arbolGeneral.buscarId(arbolGeneral.getRaiz(), id);
    if (!nodo) {
        cout << "Nodo con id " << id << " no encontrado" << endl;
        return 0;
    }
    return calcularTiempoRec(nodo);
}

double WBS::costoProyecto() {
    return calcularCostoRec(arbolGeneral.getRaiz());
}

int WBS::tiempoProyecto() {
    return calcularTiempoRec(arbolGeneral.getRaiz());
}


bool WBS::buscarCamino(Nodogeneral<NodoArbol>* nodo, int idObjetivo, vector<NodoArbol>& camino) {
    if (!nodo) return false;

    
    camino.push_back(nodo->obtenerInfo());

   
    if (nodo->obtenerInfo().obtenerId() == idObjetivo) {
        return true;
    }

  
    for (Nodogeneral<NodoArbol>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        if (buscarCamino(h, idObjetivo, camino)) return true;
    }

    
    camino.pop_back();
    return false;
}

void WBS::mostrarCamino(int id) {
    vector<NodoArbol> camino;
    if (buscarCamino(arbolGeneral.getRaiz(), id, camino)) {
        cout << "Camino desde la raiz hasta la actividad " << id << ":\n";
        for (const auto& nodo : camino) {
            cout << " -> " << nodo.obtenerDescripcion()
                 << " (Costo: " << nodo.obtenerCosto() << ")\n";
        }
    } else {
        cout << "No se encontró la actividad con id " << id << endl;
    }
}

