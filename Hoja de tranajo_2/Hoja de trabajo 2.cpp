#include <iostream>
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


    cout << "Nombre: Jorge Eduardo Espel Melgar" << endl;


    //Crear el primer nodo
    Nodo* primero = new Nodo;
    primero->data.codigo = 101;
    primero->data.nombre = "Laptop";
    primero->data.precio = 5500.50;
    primero->siguiente = nullptr;

    // Crear el segundo nodo
    Nodo* segundo = new Nodo;
    segundo->data.codigo = 102;
    segundo->data.nombre = "Mouse";
    segundo->data.precio = 150.75;
    segundo->siguiente = nullptr;

    // Enlazar primero con el segundo
    primero->siguiente = segundo;

    // Crear el tercer nodo
    Nodo* tercero = new Nodo;
    tercero->data.codigo = 103;
    tercero->data.nombre = "Teclado";
    tercero->data.precio = 300.00;
    tercero->siguiente = nullptr;

    // Enlazar segundo -> tercero
    segundo->siguiente = tercero;

    // Recorrer e imprimir la lista
    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << "Codigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "--------------------------" << endl;

        actual = actual->siguiente;
    }

    // Liberar memoria
    actual = primero;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    primero = nullptr;

    return 0;
}
