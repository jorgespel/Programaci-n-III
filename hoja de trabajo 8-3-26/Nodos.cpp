#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    Nodo* head = NULL;
    Nodo* actual = NULL;

    int valor;
    char opcion = 's';

    int contador = 0;
    int suma = 0;

    while(opcion == 's') {

        cout << "Ingrese un numero: ";
        cin >> valor;

        // Crear nodo dinamicamente
        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        // Insertar nodo en la lista
        if(head == NULL){
            head = nuevo;
        } else {
            actual = head;
            while(actual->siguiente != NULL){
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }

        contador++;
        suma += valor;

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> opcion;
    }

    // Recorrer lista
    cout << "\nLista generada:\n";

    actual = head;

    while(actual != NULL){
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout << "NULL\n";

    // Punto extra
    double promedio = 0;

    if(contador > 0){
        promedio = (double)suma / contador;
    }

    cout << "\nCantidad de nodos: " << contador << endl;
    cout << "Suma de valores: " << suma << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}