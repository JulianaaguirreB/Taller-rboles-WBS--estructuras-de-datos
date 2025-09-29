#include <iostream>
#include "WBS.h"
using namespace std;

int main() {
    WBS proyecto;

   
    string archivo = "wbs.txt";   
    proyecto.CargarArchivo(archivo);

    cout << "==== Proyecto WBS ====" << endl;
    cout << "costo total del proyecto: " << proyecto.costoProyecto() << endl;
    cout << "tiempo total del proyecto: " << proyecto.tiempoProyecto() << " dias" << endl;

    cout << "\n=== Consultas por nodo ===" << endl;
    int id;
    cout << "Ingrese id del nodo para calcular costo y tiempo: ";
    cin >> id;

    cout << "Costo del nodo " << id << ": " << proyecto.costoNodo(id) << endl;
    cout << "Tiempo del nodo " << id << ": " << proyecto.tiempoNodo(id) << " dias" << endl;

    cout << "\n=== Camino hasta una actividad terminal ===" << endl;
    int idActividad;
    cout << "Ingrese id de la actividad terminal: ";
    cin >> idActividad;
    proyecto.mostrarCamino(idActividad);

    return 0;
}

