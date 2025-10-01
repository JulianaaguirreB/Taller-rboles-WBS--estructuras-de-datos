#include <iostream>
#include "R3.h"
using namespace std;

int main() {
    // ===== Puntos con int =====
    R3<int> p1, p2;
    int xi, yi, zi;

    cout << "=== Puntos tipo int ===\n";
    cout << "Ingrese x, y, z para el primer punto: ";
    cin >> xi >> yi >> zi;
    p1.setX(xi);
    p1.setY(yi);
    p1.setZ(zi);

    cout << "Ingrese x, y, z para el segundo punto: ";
    cin >> xi >> yi >> zi;
    p2.setX(xi);
    p2.setY(yi);
    p2.setZ(zi);

    cout << "Distancia (int): " << p1.distancia(p2) << "\n\n";


    // ===== Puntos con long =====
    R3<long> p3, p4;
    long xl, yl, zl;

    cout << "=== Puntos tipo long ===\n";
    cout << "Ingrese x, y, z para el primer punto: ";
    cin >> xl >> yl >> zl;
    p3.setX(xl);
    p3.setY(yl);
    p3.setZ(zl);

    cout << "Ingrese x, y, z para el segundo punto: ";
    cin >> xl >> yl >> zl;
    p4.setX(xl);
    p4.setY(yl);
    p4.setZ(zl);

    cout << "Distancia (long): " << p3.distancia(p4) << "\n\n";


    // ===== Puntos con double =====
    R3<double> p5, p6;
    double xd, yd, zd;

    cout << "=== Puntos tipo double ===\n";
    cout << "Ingrese x, y, z para el primer punto: ";
    cin >> xd >> yd >> zd;
    p5.setX(xd);
    p5.setY(yd);
    p5.setZ(zd);
 cout << "Ingrese x, y, z para el segundo punto: ";
    cin >> xd >> yd >> zd;
    p6.setX(xd);
    p6.setY(yd);
    p6.setZ(zd);

    cout << "Distancia (double): " << p5.distancia(p6) << "\n";

    return 0;
}

