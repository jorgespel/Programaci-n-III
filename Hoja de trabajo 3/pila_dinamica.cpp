#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// insertar en la pila
void push(Nodo*& tope, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Elemento agregado correctamente.\n";
}

// eliminar el tope
void pop(Nodo*& tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia, no se puede eliminar nada.\n";
        return;
    }

    Nodo* aux = tope;
    cout << "Elemento eliminado: " << tope->dato << endl;
    tope = tope->siguiente;
    delete aux;
}

// mostrar el tope
void peek(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia, no hay elemento en el tope.\n";
        return;
    }

    cout << "El elemento en el tope es: " << tope->dato << endl;
}

// mostrar toda la pila
void mostrar(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "Elementos de la pila:\n";
    Nodo* aux = tope;
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
}

// contar elementos
int contarElementos(Nodo* tope) {
    int contador = 0;
    Nodo* aux = tope;

    while (aux != NULL) {
        contador++;
        aux = aux->siguiente;
    }

    return contador;
}

// buscar un valor en la pila
void buscarElemento(Nodo* tope, int valor) {
    if (tope == NULL) {
        cout << "La pila esta vacia, no se puede buscar.\n";
        return;
    }

    Nodo* aux = tope;
    int posicion = 1;
    bool encontrado = false;

    while (aux != NULL) {
        if (aux->dato == valor) {
            cout << "Elemento encontrado en la posicion: " << posicion << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "El elemento no se encuentra en la pila.\n";
    }
}

// vaciar la pila
void vaciarPila(Nodo*& tope) {
    if (tope == NULL) {
        cout << "La pila ya esta vacia.\n";
        return;
    }

    while (tope != NULL) {
        Nodo* aux = tope;
        tope = tope->siguiente;
        delete aux;
    }

    cout << "La pila fue vaciada completamente.\n";
}

int main() {
    Nodo* tope = NULL;
    int opcion, valor;

    cout << "=========================================\n";
    cout << "Nombre del estudiante: Jorge Eduardo Espel Melgar\n";
    cout << "Carnet: 9941-24-10596\n";
    cout << "Programa: Pila dinamica con nodos\n";
    cout << "=========================================\n";

    do {
        cout << "\n------ MENU DE PILA ------\n";
        cout << "1. Insertar elemento (push)\n";
        cout << "2. Eliminar elemento del tope (pop)\n";
        cout << "3. Mostrar elemento en el tope (peek)\n";
        cout << "4. Mostrar todos los elementos\n";
        cout << "5. Contar elementos\n";
        cout << "6. Buscar elemento\n";
        cout << "7. Vaciar pila\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese el numero que desea apilar: ";
                cin >> valor;
                push(tope, valor);
                break;

            case 2:
                pop(tope);
                break;

            case 3:
                peek(tope);
                break;

            case 4:
                mostrar(tope);
                break;

            case 5:
                cout << "Cantidad de elementos en la pila: " << contarElementos(tope) << endl;
                break;

            case 6:
                cout << "Ingrese el valor que desea buscar: ";
                cin >> valor;
                buscarElemento(tope, valor);
                break;

            case 7:
                vaciarPila(tope);
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while(opcion != 8);

    //liberar memoria
    vaciarPila(tope);

    return 0;
}