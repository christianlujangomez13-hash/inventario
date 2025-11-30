#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Producto {
    int clave;
    string nombre;
    int cantidad;
    double precio;
};

//========================================
// Buscar producto por clave o nombre
//========================================
int buscarProducto(vector<Producto>& inv, int clave, string nombre) {
    for (int i = 0; i < inv.size(); i++) {
        if (inv[i].clave == clave || inv[i].nombre == nombre) {
            return i;
        }
    }
    return -1;
}

//========================================
// Mostrar inventario con formato
//========================================
void mostrarInventario(const vector<Producto>& inv) {
    system("cls");

    cout << "====================  INVENTARIO DE PRODUCTOS  ====================\n";
    cout << left << setw(10) << "Clave"
         << setw(20) << "Producto"
         << setw(12) << "Cantidad"
         << "Precio Unitario" << endl;

    cout << "-------------------------------------------------------------------\n";

    for (const auto& p : inv) {
        cout << left << setw(10) << p.clave
             << setw(20) << p.nombre
             << setw(12) << p.cantidad
             << "$ " << fixed << setprecision(2) << p.precio << endl;
    }

    cout << "-------------------------------------------------------------------\n";
    cout << "Presiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

//========================================
// Agregar producto
//========================================
void agregarProducto(vector<Producto>& inv) {
    Producto p;

    cout << "\nClave del producto: ";
    cin >> p.clave;
    cin.ignore();

    cout << "Nombre del producto: ";
    getline(cin, p.nombre);

    cout << "Cantidad: ";
    cin >> p.cantidad;

    cout << "Precio unitario: $";
    cin >> p.precio;

    // Buscar duplicado
    int pos = buscarProducto(inv, p.clave, p.nombre);

    if (pos != -1) {
        cout << "\nProducto ya existe. Se sumará la cantidad.\n";
        inv[pos].cantidad += p.cantidad;
    } else {
        inv.push_back(p);
        cout << "\nProducto agregado correctamente.\n";
    }

    system("pause");
}

//========================================
// Buscar producto
//========================================
void buscar(const vector<Producto>& inv) {
    int opc;
    cout << "\nBuscar por:\n1. Clave\n2. Nombre\nOpcion: ";
    cin >> opc;
    cin.ignore();

    if (opc == 1) {
        int c;
        cout << "Ingrese clave: ";
        cin >> c;

        for (auto& p : inv) {
            if (p.clave == c) {
                cout << "\nEncontrado -> " << p.nombre
                     << ", Cantidad: " << p.cantidad
                     << ", Precio: $" << p.precio << endl;
                system("pause");
                return;
            }
        }
    }

    else if (opc == 2) {
        string nombre;
        cout << "Ingrese nombre: ";
        getline(cin, nombre);

        for (auto& p : inv) {
            if (p.nombre == nombre) {
                cout << "\nEncontrado -> " << p.nombre
                     << ", Cantidad: " << p.cantidad
                     << ", Precio: $" << p.precio << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "\nNo se encontró el producto.\n";
    system("pause");
}

//========================================
// Ordenar inventario
//========================================
void ordenar(vector<Producto>& inv) {
    int opc;
    cout << "\nOrdenar por:\n1. Clave\n2. Nombre\n3. Precio\nOpcion: ";
    cin >> opc;

    if (opc == 1)
        sort(inv.begin(), inv.end(),
             [](auto& a, auto& b){ return a.clave < b.clave; });

    else if (opc == 2)
        sort(inv.begin(), inv.end(),
             [](auto& a, auto& b){ return a.nombre < b.nombre; });

    else if (opc == 3)
        sort(inv.begin(), inv.end(),
             [](auto& a, auto& b){ return a.precio < b.precio; });

    cout << "\nInventario ordenado.\n";
    system("pause");
}

//========================================
// Menu principal
//========================================
int main() {
    vector<Producto> inventario; // empieza vacío

    int opcion;

    do {
        system("cls");
        cout << "========== SISTEMA DE INVENTARIO ==========\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto\n";
        cout << "4. Ordenar inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarProducto(inventario); break;
            case 2: mostrarInventario(inventario); break;
            case 3: buscar(inventario); break;
            case 4: ordenar(inventario); break;
        }

    } while (opcion != 0);

    return 0;
}
