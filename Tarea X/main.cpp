#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL tree;
    int option;

    do {
        cout << "\n====================================\n";
        cout << "Estudiante: Jorge Eduardo Espel Melgar \n";
        cout << "Carnet: 9941-24-10596\n";
        cout << "Curso: Progrmacion III\n";
        cout << "Seccion: B\n";
        cout << "====================================\n";
        cout << "\n===== Ranking Academico  =====" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Mostrar ranking academico" << endl;
        cout << "3. Buscar por skill_score" << endl;
        cout << "4. Mostrar estadisticas AVL" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        if (option == 1) {
            Student s;

            cout << "ID del estudiante: ";
            cin >> s.student_id;
            cin.ignore();

            cout << "Nombre completo: ";
            getline(cin, s.full_name);

            cout << "Carrera: ";
            getline(cin, s.career);

            cout << "Semestre: ";
            cin >> s.semester;

            cout << "GPA: ";
            cin >> s.gpa;

            cout << "Skill Score: ";
            cin >> s.skill_score;

            tree.insertStudent(s);
            cout << "Estudiante insertado correctamente." << endl;
        }
        else if (option == 2) {
            tree.showRanking();
        }
        else if (option == 3) {
            int score;
            cout << "Ingrese el skill_score a buscar: ";
            cin >> score;

            tree.searchByScore(score);
        }
        else if (option == 4) {
            tree.showStats();
        }
        else if (option == 5) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }

    } while (option != 5);

    return 0;
}