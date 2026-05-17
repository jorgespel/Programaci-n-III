#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Estudiante {
    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;
};

struct Nodo {
    Estudiante estudiante;
    Nodo* siguiente;
};

class HashTable {
private:
    static const int SIZE = 10;

    Nodo* tabla[SIZE];

    int totalEstudiantes;
    int totalColisiones;

    int funcionHash(int id) {
        return id % SIZE;
    }

public:

    HashTable() {

        for (int i = 0; i < SIZE; i++) {
            tabla[i] = nullptr;
        }

        totalEstudiantes = 0;
        totalColisiones = 0;
    }

    Estudiante* buscar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {
                return &actual->estudiante;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    bool insertar(Estudiante estudiante) {

        int indice = funcionHash(estudiante.student_id);

        // Validar duplicados
        if (buscar(estudiante.student_id) != nullptr) {

            cout << "Error: estudiante duplicado con ID "
                 << estudiante.student_id << endl;

            return false;
        }

        Nodo* nuevo = new Nodo;

        nuevo->estudiante = estudiante;
        nuevo->siguiente = nullptr;

        // Verificar colision
        if (tabla[indice] != nullptr) {
            totalColisiones++;
        }

        // Insertar al inicio
        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        totalEstudiantes++;

        return true;
    }

    bool eliminar(int id) {

        int indice = funcionHash(id);

        Nodo* actual = tabla[indice];
        Nodo* anterior = nullptr;

        while (actual != nullptr) {

            if (actual->estudiante.student_id == id) {

                if (anterior == nullptr) {
                    tabla[indice] = actual->siguiente;
                }
                else {
                    anterior->siguiente = actual->siguiente;
                }

                delete actual;

                totalEstudiantes--;

                cout << "Estudiante eliminado correctamente.\n";

                return true;
            }

            anterior = actual;
            actual = actual->siguiente;
        }

        cout << "No se encontro el estudiante.\n";

        return false;
    }

    void mostrarTabla() {

        cout << "\n========= TABLA HASH =========\n";

        for (int i = 0; i < SIZE; i++) {

            cout << "Bucket [" << i << "] -> ";

            Nodo* actual = tabla[i];

            if (actual == nullptr) {
                cout << "vacio";
            }

            while (actual != nullptr) {

                cout << "("
                     << actual->estudiante.student_id
                     << ", "
                     << actual->estudiante.full_name
                     << ") -> ";

                actual = actual->siguiente;
            }

            cout << "NULL\n";
        }
    }

    void mostrarEstadisticas() {

        cout << "\n========= ESTADISTICAS =========\n";

        cout << "Total de estudiantes: "
             << totalEstudiantes << endl;

        cout << "Total de colisiones: "
             << totalColisiones << endl;

        cout << "Factor de carga: "
             << calcularFactorCarga() << endl;
    }

    float calcularFactorCarga() {

        return (float) totalEstudiantes / SIZE;
    }

    void cargarCSV(string nombreArchivo) {

        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {

            cout << "Error al abrir el archivo CSV.\n";

            return;
        }

        string linea;

        // Saltar encabezado
        getline(archivo, linea);

        while (getline(archivo, linea)) {

            stringstream ss(linea);

            string dato;

            Estudiante estudiante;

            getline(ss, dato, ',');
            estudiante.student_id = stoi(dato);

            getline(ss, estudiante.full_name, ',');

            getline(ss, estudiante.career, ',');

            getline(ss, dato, ',');
            estudiante.semester = stoi(dato);

            getline(ss, dato, ',');
            estudiante.gpa = stof(dato);

            getline(ss, dato, ',');
            estudiante.skill_score = stoi(dato);

            insertar(estudiante);
        }

        archivo.close();

        cout << "Archivo CSV cargado correctamente.\n";
    }

    ~HashTable() {

        for (int i = 0; i < SIZE; i++) {

            Nodo* actual = tabla[i];

            while (actual != nullptr) {

                Nodo* temp = actual;

                actual = actual->siguiente;

                delete temp;
            }
        }
    }
};

int main() {

    HashTable hash;

    int opcion;

    cout << "=========================================\n";
    cout << "Nombre del estudiante: Jorge Eduardo Espel Melgar\n";
    cout << "Carnet: 9941-24-10596\n";
    cout << "Curso: Programacion III\n";
    cout << "=========================================\n";


    // Cargar CSV automaticamente
    hash.cargarCSV("estudiantes.csv");

    do {

        cout << "\n========= MENU =========\n";

        cout << "1. Buscar estudiante\n";
        cout << "2. Eliminar estudiante\n";
        cout << "3. Mostrar tabla hash\n";
        cout << "4. Mostrar estadisticas\n";
        cout << "5. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            int id;

            cout << "Ingrese el ID del estudiante: ";
            cin >> id;

            Estudiante* encontrado = hash.buscar(id);

            if (encontrado != nullptr) {

                cout << "\nEstudiante encontrado\n";

                cout << "ID: "
                     << encontrado->student_id << endl;

                cout << "Nombre: "
                     << encontrado->full_name << endl;

                cout << "Carrera: "
                     << encontrado->career << endl;

                cout << "Semestre: "
                     << encontrado->semester << endl;

                cout << "GPA: "
                     << encontrado->gpa << endl;

                cout << "Skill Score: "
                     << encontrado->skill_score << endl;
            }
            else {

                cout << "Estudiante no encontrado.\n";
            }
        }

        else if (opcion == 2) {

            int id;

            cout << "Ingrese el ID a eliminar: ";
            cin >> id;

            hash.eliminar(id);
        }

        else if (opcion == 3) {

            hash.mostrarTabla();
        }

        else if (opcion == 4) {

            hash.mostrarEstadisticas();
        }

        else if (opcion == 5) {

            cout << "Saliendo del programa...\n";
        }

        else {

            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}