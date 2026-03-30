#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo
struct Nodo {
    string accion;
    Nodo* siguiente;
};

// Funcion para insertar en la pila
void push(Nodo*& pila, string texto) {
    Nodo* nuevo = new Nodo;
    nuevo->accion = texto;
    nuevo->siguiente = pila;
    pila = nuevo;
}

// Funcion para sacar de la pila
string pop(Nodo*& pila) {
    if (pila == NULL) {
        return "";
    }

    Nodo* aux = pila;
    string texto = aux->accion;
    pila = pila->siguiente;
    delete aux;

    return texto;
}

// Mostrar una pila
void mostrar(Nodo* pila) {
    if (pila == NULL) {
        cout << "La pila esta vacia." << endl;
        return;
    }

    Nodo* aux = pila;
    int contador = 1;

    while (aux != NULL) {
        cout << contador << ". " << aux->accion << endl;
        aux = aux->siguiente;
        contador++;
    }
}

// Limpiar toda una pila
void limpiarPila(Nodo*& pila) {
    while (pila != NULL) {
        pop(pila);
    }
}

int main() {
    Nodo* acciones = NULL;   // pila principal
    Nodo* rehacer = NULL;    // pila de acciones deshechas

    int opcion;
    string accion;

    cout << "==========================================" << endl;
    cout << "   Nombre: Jorge Eduardo Espel Melgar" << endl;
    cout << "   Carnet: 9941-24-10596" << endl;
    cout << "==========================================" << endl;

    do {
        cout << "\n----------- MENU -----------" << endl;
        cout << "1. Realizar accion" << endl;
        cout << "2. Deshacer ultima accion" << endl;
        cout << "3. Rehacer accion" << endl;
        cout << "4. Mostrar acciones actuales" << endl;
        cout << "5. Mostrar pila de rehacer" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese la accion realizada: ";
                getline(cin, accion);

                push(acciones, accion);

                limpiarPila(rehacer);

                cout << "Accion guardada correctamente." << endl;
                break;

            case 2:
                if (acciones == NULL) {
                    cout << "No hay acciones para deshacer." << endl;
                } else {
                    accion = pop(acciones);
                    push(rehacer, accion);
                    cout << "Se deshizo la accion: " << accion << endl;
                }
                break;

            case 3:
                if (rehacer == NULL) {
                    cout << "No hay acciones para rehacer." << endl;
                } else {
                    accion = pop(rehacer);
                    push(acciones, accion);
                    cout << "Se rehizo la accion: " << accion << endl;
                }
                break;

            case 4:
                cout << "\n--- Acciones actuales ---" << endl;
                mostrar(acciones);
                break;

            case 5:
                cout << "\n--- Pila de rehacer ---" << endl;
                mostrar(rehacer);
                break;

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida. Intente otra vez." << endl;
        }

    } while (opcion != 6);

    // Liberar memoria antes de terminar
    limpiarPila(acciones);
    limpiarPila(rehacer);

    return 0;
}