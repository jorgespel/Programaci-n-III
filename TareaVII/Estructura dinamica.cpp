#include <iostream>
#include <limits>

using namespace std;

// ---------------------- NODOS ----------------------
struct NodoPila {
    int dato;
    NodoPila* siguiente;
};

struct NodoCola {
    int dato;
    NodoCola* siguiente;
};

struct NodoLista {
    int dato;
    NodoLista* siguiente;
};

// ---------------------- FUNCIONES PILA ----------------------
void push(NodoPila*& cima, int valor) {
    NodoPila* nuevo = new NodoPila;
    nuevo->dato = valor;
    nuevo->siguiente = cima;
    cima = nuevo;
}

void pop(NodoPila*& cima) {
    if (cima == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    NodoPila* aux = cima;
    cout << "Se elimino de la pila: " << aux->dato << endl;
    cima = cima->siguiente;
    delete aux;
}

void peekPila(NodoPila* cima) {
    if (cima == NULL) {
        cout << "La pila esta vacia.\n";
    } else {
        cout << "Elemento en la cima de la pila: " << cima->dato << endl;
    }
}

void mostrarPila(NodoPila* cima) {
    if (cima == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "Pila (impares): ";
    NodoPila* aux = cima;
    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

void liberarPila(NodoPila*& cima) {
    while (cima != NULL) {
        NodoPila* aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
}

// ---------------------- FUNCIONES COLA ----------------------
void enqueue(NodoCola*& frente, NodoCola*& fin, int valor) {
    NodoCola* nuevo = new NodoCola;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

void dequeue(NodoCola*& frente, NodoCola*& fin) {
    if (frente == NULL) {
        cout << "La cola esta vacia.\n";
        return;
    }

    NodoCola* aux = frente;
    cout << "Se elimino de la cola: " << aux->dato << endl;
    frente = frente->siguiente;

    if (frente == NULL) {
        fin = NULL;
    }

    delete aux;
}

void peekCola(NodoCola* frente) {
    if (frente == NULL) {
        cout << "La cola esta vacia.\n";
    } else {
        cout << "Elemento al frente de la cola: " << frente->dato << endl;
    }
}

void mostrarCola(NodoCola* frente) {
    if (frente == NULL) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "Cola (pares): ";
    NodoCola* aux = frente;
    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

void liberarCola(NodoCola*& frente, NodoCola*& fin) {
    while (frente != NULL) {
        NodoCola* aux = frente;
        frente = frente->siguiente;
        delete aux;
    }
    fin = NULL;
}

// ---------------------- FUNCIONES LISTA ----------------------
void insertarLista(NodoLista*& lista, int valor) {
    NodoLista* nuevo = new NodoLista;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        NodoLista* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void mostrarLista(NodoLista* lista) {
    if (lista == NULL) {
        cout << "La lista de negativos esta vacia.\n";
        return;
    }

    cout << "Lista (negativos): ";
    NodoLista* aux = lista;
    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

void liberarLista(NodoLista*& lista) {
    while (lista != NULL) {
        NodoLista* aux = lista;
        lista = lista->siguiente;
        delete aux;
    }
}

// ---------------------- VALIDACION ----------------------
int leerEntero() {
    int numero;

    while (true) {
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero: ";
        } else {
            return numero;
        }
    }
}

// ---------------------- MENU ----------------------
void mostrarMenu() {
    cout << "\n====== MENU PRINCIPAL ======\n";
    cout << "1. Ingresar numero\n";
    cout << "2. Mostrar pila\n";
    cout << "3. Mostrar cola\n";
    cout << "4. Mostrar lista\n";
    cout << "5. Eliminar de pila\n";
    cout << "6. Eliminar de cola\n";
    cout << "7. Ver cima de pila\n";
    cout << "8. Ver frente de cola\n";
    cout << "9. Mostrar estadisticas\n";
    cout << "10. Salir\n";
    cout << "Seleccione una opcion: ";
}

// ---------------------- MAIN ----------------------
int main() {
    NodoPila* pila = NULL;
    NodoCola* frente = NULL;
    NodoCola* fin = NULL;
    NodoLista* lista = NULL;

    int opcion, numero;
    int cantPares = 0;
    int cantImpares = 0;
    int cantNegativos = 0;

    cout << "=====================================\n";
    cout << "Estudiante: Jorge Eduardo Espel Melgar\n";
    cout << "Curso: Programacion III\n";
    cout << "Seccion: B\n";
    cout << "=====================================\n";

    do {
        mostrarMenu();
        opcion = leerEntero();

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero (-1 para cancelar este ingreso): ";
                numero = leerEntero();

                if (numero == -1) {
                    cout << "Ingreso cancelado.\n";
                } else if (numero < 0) {
                    insertarLista(lista, numero);
                    cantNegativos++;
                    cout << "Numero negativo agregado a la lista.\n";
                } else if (numero % 2 == 0) {
                    enqueue(frente, fin, numero);
                    cantPares++;
                    cout << "Numero par agregado a la cola.\n";
                } else {
                    push(pila, numero);
                    cantImpares++;
                    cout << "Numero impar agregado a la pila.\n";
                }
                break;

            case 2:
                mostrarPila(pila);
                break;

            case 3:
                mostrarCola(frente);
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 5:
                pop(pila);
                break;

            case 6:
                dequeue(frente, fin);
                break;

            case 7:
                peekPila(pila);
                break;

            case 8:
                peekCola(frente);
                break;

            case 9:
                cout << "\n--- Estadisticas ---\n";
                cout << "Cantidad de pares: " << cantPares << endl;
                cout << "Cantidad de impares: " << cantImpares << endl;
                cout << "Cantidad de negativos: " << cantNegativos << endl;
                break;

            case 10:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 10);

    // Liberar memoria
    liberarPila(pila);
    liberarCola(frente, fin);
    liberarLista(lista);

    cout << "Memoria liberada correctamente.\n";

    return 0;
}