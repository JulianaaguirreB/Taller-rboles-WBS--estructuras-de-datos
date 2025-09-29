#include "ArbolGeneral.h"

template <typename T>
ArbolGeneral<T>::ArbolGeneral() : raiz(nullptr) {}

template <typename T>
ArbolGeneral<T>::ArbolGeneral(T val) {
    raiz = new Nodogeneral<T>(val);
}

template <typename T>
ArbolGeneral<T>::ArbolGeneral(Nodogeneral<T>* nodo) {
    raiz = nodo;
}

template <typename T>
ArbolGeneral<T>::ArbolGeneral(const ArbolGeneral<T>& other) {
    
    raiz = other.raiz;
}

template <typename T>
ArbolGeneral<T>::~ArbolGeneral() {
    destruir(raiz);
}

template <typename T>
void ArbolGeneral<T>::destruir(Nodogeneral<T>* nodo) {
    if (!nodo) return;
    destruir(nodo->obtenerPrimerHijo());
    destruir(nodo->obtenerSiguienteHermano());
    delete nodo;
}


template <typename T>
ArbolGeneral<T>& ArbolGeneral<T>::operator=(const ArbolGeneral<T>& other) {
    if (this != &other) {
        destruir(raiz);
        raiz = other.raiz;
    }
    return *this;
}


template <typename T>
bool ArbolGeneral<T>::esVacio() const {
    return raiz == nullptr;
}

template <typename T>
T ArbolGeneral<T>::obtenerRaiz() const {
    if (!raiz) throw runtime_error("Árbol vacío");
    return raiz->obtenerInfo();
}

template <typename T>
void ArbolGeneral<T>::fijarRaiz(T val) {
    if (raiz) {
        raiz->fijarInfo(val);
    } else {
        raiz = new Nodogeneral<T>(val);
    }
}

template <typename T>
void ArbolGeneral<T>::insertarNodo(const T& padre, const T& n) {
    Nodogeneral<T>* nodoPadre = buscarId(raiz, padre.obtenerId());
    if (!nodoPadre) return;

    Nodogeneral<T>* nuevo = new Nodogeneral<T>(n);
    nodoPadre->agregarHijoAlFinal(nuevo);
}


template <typename T>
void ArbolGeneral<T>::eliminarNodo(const T& n) {
    if (!raiz) return;

    
    if (raiz->obtenerInfo().obtenerId() == n.obtenerId()) {
        destruir(raiz);
        raiz = nullptr;
        return;
    }

    bool eliminado = false;
    eliminarRec(raiz, n, eliminado);
}

template <typename T>
void ArbolGeneral<T>::eliminarRec(Nodogeneral<T>* padre, const T& n, bool& eliminado) {
    if (!padre || eliminado) return;

    Nodogeneral<T>* hijo = padre->obtenerPrimerHijo();
    Nodogeneral<T>* anterior = nullptr;

    while (hijo && !eliminado) {
        if (hijo->obtenerInfo().obtenerId() == n.obtenerId()) {
          
            if (anterior) {
                anterior->fijarSiguienteHermano(hijo->obtenerSiguienteHermano());
            } else {
                padre->fijarPrimerHijo(hijo->obtenerSiguienteHermano());
            }
            destruir(hijo);
            eliminado = true;
            return;
        }
        anterior = hijo;
        hijo = hijo->obtenerSiguienteHermano();
    }

   
    for (Nodogeneral<T>* h = padre->obtenerPrimerHijo(); h && !eliminado; h = h->obtenerSiguienteHermano()) {
        eliminarRec(h, n, eliminado);
    }
}



template <typename T>
ArbolGeneral<T> ArbolGeneral<T>::subArbolN(const T& n) {
    Nodogeneral<T>* nodo = buscarId(raiz, n.obtenerId());
    if (!nodo) {
        throw runtime_error("Nodo no encontrado");
    }
    return ArbolGeneral<T>(nodo);
}


template <typename T>
int ArbolGeneral<T>::altura() const {
    return alturaRec(raiz);
}

template <typename T>
int ArbolGeneral<T>::alturaRec(Nodogeneral<T>* nodo) const {
    if (!nodo) return 0;
    int maxAltura = 0;
    for (Nodogeneral<T>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        maxAltura = max(maxAltura, alturaRec(h));
    }
    return 1 + maxAltura;
}

template <typename T>
int ArbolGeneral<T>::tamano() const {
    return tamanoRec(raiz);
}

template <typename T>
int ArbolGeneral<T>::tamanoRec(Nodogeneral<T>* nodo) const {
    if (!nodo) return 0;
    int suma = 1;
    for (Nodogeneral<T>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        suma += tamanoRec(h);
    }
    return suma;
}

template <typename T>
int ArbolGeneral<T>::orden() const {
    return ordenRec(raiz);
}

template <typename T>
int ArbolGeneral<T>::ordenRec(Nodogeneral<T>* nodo) const {
    if (!nodo) return 0;
    int cuenta = 0;
    for (Nodogeneral<T>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        cuenta++;
    }
    int maxOrden = cuenta;
    for (Nodogeneral<T>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        maxOrden = max(maxOrden, ordenRec(h));
    }
    return maxOrden;
}


template <typename T>
Nodogeneral<T>* ArbolGeneral<T>::buscarId(Nodogeneral<T>* nodo, int id) const {
    if (!nodo) return nullptr;
    if (nodo->obtenerInfo().obtenerId() == id) return nodo;

    for (Nodogeneral<T>* h = nodo->obtenerPrimerHijo(); h; h = h->obtenerSiguienteHermano()) {
        Nodogeneral<T>* res = buscarId(h, id);
        if (res) return res;
    }
    return nullptr;
}


template class ArbolGeneral<NodoArbol>;

