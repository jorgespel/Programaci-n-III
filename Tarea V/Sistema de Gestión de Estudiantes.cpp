#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

void insertarInicio(Nodo*& head);
void insertarFinal(Nodo*& head);
void mostrarEstudiantes(Nodo* head);
void buscarEstudiante(Nodo* head);
void eliminarEstudiante(Nodo*& head);
void liberarLista(Nodo*& head);
int leerEntero(string mensaje);

int main() {
    Nodo* head = NULL;
    int opcion;

    string nombreEstudiante = "Jorge Eduardo Espel Melgar";
    string carneEstudiante = "9941-24-10596";

    do {
        cout << "\n=========================================\n";
        cout << "   SISTEMA DE GESTION DE ESTUDIANTES\n";
        cout << "=========================================\n";
        cout << "Nombre del estudiante: " << nombreEstudiante << endl;
        cout << "Carne del estudiante: " << carneEstudiante << endl;
        cout << "=========================================\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar todos los estudiantes\n";
        cout << "4. Buscar estudiante por carne\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";

        opcion = leerEntero("Ingrese una opcion: ");

        switch (opcion) {
            case 1:
                insertarInicio(head);
                break;
            case 2:
                insertarFinal(head);
                break;
            case 3:
                mostrarEstudiantes(head);
                break;
            case 4:
                buscarEstudiante(head);
                break;
            case 5:
                eliminarEstudiante(head);
                break;
            case 6:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != 6);

    liberarLista(head);
    return 0;
}

int leerEntero(string mensaje) {
    int valor;

    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cout << "Entrada invalida. Debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

void insertarInicio(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    nuevo->carne = leerEntero("\nIngrese el carne: ");

    cout << "Ingrese el nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, nuevo->apellido);

    cout << "Ingrese la carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = head;
    head = nuevo;

    cout << "\nEstudiante insertado al inicio correctamente.\n";
}

void insertarFinal(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    nuevo->carne = leerEntero("\nIngrese el carne: ");

    cout << "Ingrese el nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, nuevo->apellido);

    cout << "Ingrese la carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = NULL;

    if (head == NULL) {
        head = nuevo;
    } else {
        Nodo* aux = head;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    cout << "\nEstudiante insertado al final correctamente.\n";
}

void mostrarEstudiantes(Nodo* head) {
    if (head == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    Nodo* aux = head;

    cout << "\n===== LISTA DE ESTUDIANTES =====\n";
    while (aux != NULL) {
        cout << "Carne: " << aux->carne << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Apellido: " << aux->apellido << endl;
        cout << "Carrera: " << aux->carrera << endl;
        cout << "-----------------------------\n";
        aux = aux->siguiente;
    }
}

void buscarEstudiante(Nodo* head) {
    if (head == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    int carneBuscar = leerEntero("\nIngrese carne a buscar: ");
    Nodo* aux = head;
    bool encontrado = false;

    while (aux != NULL) {
        if (aux->carne == carneBuscar) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Carne: " << aux->carne << endl;
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Apellido: " << aux->apellido << endl;
            cout << "Carrera: " << aux->carrera << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }

    if (!encontrado) {
        cout << "\nEstudiante no encontrado.\n";
    }
}

void eliminarEstudiante(Nodo*& head) {
    if (head == NULL) {
        cout << "\nLa lista esta vacia. No hay nada que eliminar.\n";
        return;
    }

    int carneEliminar = leerEntero("\nIngrese carne del estudiante a eliminar: ");

    Nodo* actual = head;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->carne != carneEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "\nEstudiante no encontrado.\n";
        return;
    }

    if (anterior == NULL) {
        head = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "\nEstudiante eliminado correctamente.\n";
}

void liberarLista(Nodo*& head) {
    Nodo* aux;

    while (head != NULL) {
        aux = head;
        head = head->siguiente;
        delete aux;
    }
}
