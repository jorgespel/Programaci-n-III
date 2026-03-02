#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {
    cout << "Nombre: Jorge Edaurdo Espel Melgar" << endl << endl;

    Nodo* cabeza = nullptr;
    Nodo* ultimo = nullptr;

    // Creacion de 4 nodos
    for (int i = 1; i <= 4; i++) {
        Nodo* nuevo = new Nodo;
        nuevo->siguiente = nullptr;

        cout << "Producto " << i << endl;
        cout << "Codigo: ";
        cin >> nuevo->data.codigo;
        cin.ignore();

        cout << "Nombre: ";
        getline(cin, nuevo->data.nombre);

        cout << "Precio: Q";
        cin >> nuevo->data.precio;

        cout << "--------------------" << endl;

        if (cabeza == nullptr) {
            cabeza = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    cout << endl << "=== LISTA DE PRODUCTOS ===" << endl;

    Nodo* aux = cabeza;
    double total = 0.0;

    while (aux != nullptr) {
        cout << "Codigo: " << aux->data.codigo << endl;
        cout << "Nombre: " << aux->data.nombre << endl;
        cout << fixed << setprecision(2);
        cout << "Precio: Q" << aux->data.precio << endl;
        cout << "--------------------" << endl;

        total += aux->data.precio;
        aux = aux->siguiente;
    }

    cout << fixed << setprecision(2);
    cout << "Total acumulado: Q" << total << endl;

    aux = cabeza;
    while (aux != nullptr) {
        Nodo* temp = aux;
        aux = aux->siguiente;
        delete temp;
    }

    cabeza = nullptr;
    ultimo = nullptr;

    return 0;
}
