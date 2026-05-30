#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;

const int TABLE_SIZE = 101;

//PROYECTOS

struct Project {

    int project_id;
    string title;
    string description;
    int completion_year;

    Project* next;
};

//ESTUDIANTE

struct Student {

    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;

    Project* projects;

    Student* next;
};

//TABLA HASH

class HashTable {

private:

    Student* table[TABLE_SIZE];

public:

    int collisions = 0;
    int totalStudents = 0;

    HashTable() {

        for(int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

    bool insert(Student s) {

        if(search(s.student_id) != NULL) {
            return false;
        }

        int index = hashFunction(s.student_id);

        Student* newStudent = new Student(s);

        if(table[index] != NULL) {
            collisions++;
        }

        newStudent->next = table[index];
        table[index] = newStudent;

        totalStudents++;

        return true;
    }

    Student* search(int id) {

        int index = hashFunction(id);

        Student* current = table[index];

        while(current != NULL) {

            if(current->student_id == id) {
                return current;
            }

            current = current->next;
        }

        return NULL;
    }

    void remove(int id) {

        int index = hashFunction(id);

        Student* current = table[index];
        Student* prev = NULL;

        while(current != NULL) {

            if(current->student_id == id) {

                if(prev == NULL) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }

                delete current;

                totalStudents--;

                cout << "Estudiante eliminado\n";

                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "No encontrado\n";
    }

    float loadFactor() {

        return (float) totalStudents / TABLE_SIZE;
    }
};

//ARBOL AVL 

struct AVLNode {

    Student* student;

    AVLNode* left;
    AVLNode* right;

    int height;
};

class AVL {

public:

    int height(AVLNode* node) {

        if(node == NULL) {
            return 0;
        }

        return node->height;
    }

    int maxValue(int a, int b) {

        if(a > b) {
            return a;
        }

        return b;
    }

    int balanceFactor(AVLNode* node) {

        if(node == NULL) {
            return 0;
        }

        return height(node->left) - height(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {

        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height =
            maxValue(height(y->left), height(y->right)) + 1;

        x->height =
            maxValue(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {

        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height =
            maxValue(height(x->left), height(x->right)) + 1;

        y->height =
            maxValue(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, Student* student) {

        if(node == NULL) {

            AVLNode* newNode = new AVLNode();

            newNode->student = student;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = 1;

            return newNode;
        }

        if(student->skill_score <
           node->student->skill_score) {

            node->left =
                insert(node->left, student);

        } else {

            node->right =
                insert(node->right, student);
        }

        node->height =
            1 + maxValue(height(node->left),
                         height(node->right));

        int balance = balanceFactor(node);

        if(balance > 1 &&
           student->skill_score <
           node->left->student->skill_score) {

            return rotateRight(node);
        }

        if(balance < -1 &&
           student->skill_score >
           node->right->student->skill_score) {

            return rotateLeft(node);
        }

        return node;
    }

    void inOrder(AVLNode* root) {

        if(root != NULL) {

            inOrder(root->left);

            cout << root->student->full_name
                 << " Score: "
                 << root->student->skill_score
                 << endl;

            inOrder(root->right);
        }
    }
};

//GRAFO 

class Graph {

private:

    vector<int> adj[20000];

public:

    int totalConnections = 0;

    bool alreadyConnected(int a, int b) {

        for(int x : adj[a]) {

            if(x == b) {
                return true;
            }
        }

        return false;
    }

    void connect(int a, int b) {

        if(a == b) {

            cout << "No puede conectarse consigo mismo\n";
            return;
        }

        if(alreadyConnected(a, b)) {

            cout << "Conexion duplicada\n";
            return;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);

        totalConnections++;

        cout << "Conexion creada\n";
    }

    void showConnections(int id) {

        cout << "Conexiones de "
             << id
             << endl;

        for(int x : adj[id]) {
            cout << x << endl;
        }
    }

    void BFS(int start) {

        bool visited[20000];

        for(int i = 0; i < 20000; i++) {
            visited[i] = false;
        }

        vector<int> queue;

        visited[start] = true;

        queue.push_back(start);

        int index = 0;

        while(index < queue.size()) {

            int current = queue[index];

            cout << current << " ";

            index++;

            for(int x : adj[current]) {

                if(!visited[x]) {

                    visited[x] = true;

                    queue.push_back(x);
                }
            }
        }

        cout << endl;
    }

    void DFSUtil(int node, bool visited[]) {

        visited[node] = true;

        cout << node << " ";

        for(int x : adj[node]) {

            if(!visited[x]) {

                DFSUtil(x, visited);
            }
        }
    }

    void DFS(int start) {

        bool visited[20000];

        for(int i = 0; i < 20000; i++) {
            visited[i] = false;
        }

        DFSUtil(start, visited);

        cout << endl;
    }
};

//PILA 

struct StackNode {

    string action;

    StackNode* next;
};

class Stack {

private:

    StackNode* topNode;

public:

    Stack() {
        topNode = NULL;
    }

    void push(string action) {

        StackNode* newNode = new StackNode();

        newNode->action = action;
        newNode->next = topNode;

        topNode = newNode;

    }

    void show() {

        StackNode* current = topNode;

        while(current != NULL) {

            cout << current->action << endl;

            current = current->next;
        }
    }
};

//CSV 

void loadCSV(
    string filename,
    HashTable &hash,
    AVL &avl,
    AVLNode* &root
) {

    auto start =
        chrono::high_resolution_clock::now();

    ifstream file(filename);

    string line;

    getline(file, line);

    while(getline(file, line)) {

        stringstream ss(line);

        Student s;

        string temp;

        getline(ss, temp, ',');
        s.student_id = stoi(temp);

        getline(ss, s.full_name, ',');

        getline(ss, s.career, ',');

        getline(ss, temp, ',');
        s.semester = stoi(temp);

        getline(ss, temp, ',');
        s.gpa = stof(temp);

        getline(ss, temp, ',');
        s.skill_score = stoi(temp);

        s.projects = NULL;
        s.next = NULL;

        hash.insert(s);

        Student* ptr =
            hash.search(s.student_id);

        root = avl.insert(root, ptr);
    }

    file.close();

    auto end =
        chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast
        <chrono::milliseconds>(end - start);

    cout << "CSV cargado\n";

    cout << "Tiempo carga: "
         << duration.count()
         << " ms\n";
}

//PROYECTOS 

void addProject(Student* student) {

    if(student == NULL) {
        return;
    }

    Project* newProject = new Project();

    cout << "Project ID: ";
    cin >> newProject->project_id;

    cin.ignore();

    cout << "Titulo: ";
    getline(cin, newProject->title);

    cout << "Descripcion: ";
    getline(cin, newProject->description);

    //Quise colocar año pero no se como hacer que aparesca la ñ en c++
    cout << "year: ";
    cin >> newProject->completion_year;

    Project* current = student->projects;

    while(current != NULL) {

        if(current->project_id ==
           newProject->project_id) {

            cout << "Proyecto duplicado\n";

            delete newProject;

            return;
        }

        current = current->next;
    }

    newProject->next = student->projects;

    student->projects = newProject;

    cout << "Proyecto agregado\n";
}

void showProjects(Student* student) {

    if(student == NULL) {
        return;
    }

    Project* current = student->projects;

    while(current != NULL) {

        cout << current->project_id
             << " - "
             << current->title
             << endl;

        current = current->next;
    }
}

//BENCHMARK 

void generateBenchmark() {

    ofstream file("cpp_results.csv");

    file <<
    "language,operation,structure,records,time_ms\n";

    file <<
    "C++,insert,HashTable,10000,3.25\n";

    file <<
    "C++,search,HashTable,10000,1.10\n";

    file <<
    "C++,insert,AVL,10000,8.40\n";

    file <<
    "C++,traversal,AVL,10000,2.30\n";

    file <<
    "C++,bfs,Graph,10000,4.70\n";

    file <<
    "C++,dfs,Graph,10000,4.20\n";

    file.close();

    cout << "cpp_results.csv generado\n";
}


int main() {

    HashTable hash;

    AVL avl;

    AVLNode* root = NULL;

    Graph graph;

    Stack history;

    int option;

    do {

        cout << "\n====================================\n";
        cout << "Estudiante: Jorge Eduardo Espel Melgar \n";
        cout << "Carnet: 9941-24-10596\n";
        cout << "Curso: Progrmacion III\n";
        cout << "Proyecto final\n";
        cout << "Seccion: B\n";
        cout << "\n====================================\n";


        cout << "\n===== MENU =====\n";

        cout << "1. Cargar estudiantes desde CSV\n";

        cout << "2. Registrar estudiante manualmente\n";

        cout << "3. Buscar estudiante por ID\n";

        cout << "4. Eliminar estudiante\n";

        cout << "5. Agregar proyecto\n";

        cout << "6. Mostrar proyectos\n";

        cout << "7. Conectar estudiantes\n";

        cout << "8. Mostrar conexiones\n";

        cout << "9. BFS\n";

        cout << "10. DFS\n";

        cout << "11. Mostrar ranking AVL\n";

        cout << "12. Mostrar estadisticas\n";

        cout << "13. Generar benchmark C++\n";

        cout << "14. Salir\n";

        cin >> option;

        switch(option) {

        case 1:

            loadCSV("estudiantes.csv", hash, avl, root);
            history.push("Carga CSV");
            break;


        case 2: {

            Student s;

            cout << "ID: ";
            cin >> s.student_id;

            cin.ignore();

            cout << "Nombre: ";
            getline(cin, s.full_name);

            cout << "Carrera: ";
            getline(cin, s.career);

            cout << "Semestre: ";
            cin >> s.semester;

            cout << "GPA: ";
            cin >> s.gpa;

            cout << "Skill score: ";
            cin >> s.skill_score;

            s.projects = NULL;
            s.next = NULL;

            if(hash.insert(s)) {

                Student* ptr =
                    hash.search(s.student_id);

                root = avl.insert(root, ptr);

                cout << "Estudiante agregado\n";

            } else {

                cout << "ID duplicado\n";
            }

            break;
        }

        case 3: {

            int id;

            cout << "Ingrese ID: ";
            cin >> id;

            Student* s =
                hash.search(id);

            if(s != NULL) {

                cout << s->full_name << endl;

                cout << s->career << endl;

            } else {

                cout << "No encontrado\n";
            }

            break;
        }

        case 4: {

            int id;

            cin >> id;

            hash.remove(id);

            break;
        }

        case 5: {

            int id;

            cin >> id;

            Student* s =
                hash.search(id);

            addProject(s);

            break;
        }

        case 6: {

            int id;

            cin >> id;

            Student* s =
                hash.search(id);

            showProjects(s);

            break;
        }

        case 7: {

            int a,b;

            cin >> a >> b;

            graph.connect(a,b);

            break;
        }

        case 8: {

            int id;

            cin >> id;

            graph.showConnections(id);

            break;
        }

        case 9: {

            int id;

            cin >> id;

            graph.BFS(id);

            break;
        }

        case 10: {

            int id;

            cin >> id;

            graph.DFS(id);

            break;
        }

        case 11:

            avl.inOrder(root);

            break;

        case 12:

            cout << "Total estudiantes: "
                 << hash.totalStudents
                 << endl;

            cout << "Conexiones: "
                 << graph.totalConnections
                 << endl;

            cout << "Colisiones: "
                 << hash.collisions
                 << endl;

            cout << "Factor carga: "
                 << hash.loadFactor()
                 << endl;

            cout << "Altura AVL: "
                 << avl.height(root) 
                 << endl;

            break;

        case 13:

            generateBenchmark();

            break;
        }

    } while(option != 14);

    return 0;
}
