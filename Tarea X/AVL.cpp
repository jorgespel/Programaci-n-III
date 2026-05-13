#include "AVL.h"

AVL::AVL() {
    root = nullptr;
    totalNodes = 0;
}

int AVL::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVL::maxValue(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int AVL::balanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = maxValue(height(y->left), height(y->right)) + 1;
    x->height = maxValue(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = maxValue(height(x->left), height(x->right)) + 1;
    y->height = maxValue(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVL::insert(Node* node, Student student) {
    if (node == nullptr) {
        totalNodes++;
        return new Node(student);
    }

    if (student.skill_score < node->student.skill_score) {
        node->left = insert(node->left, student);
    } 
    else if (student.skill_score > node->student.skill_score) {
        node->right = insert(node->right, student);
    } 
    else {
        if (student.student_id < node->student.student_id) {
            node->left = insert(node->left, student);
        } else {
            node->right = insert(node->right, student);
        }
    }

    node->height = 1 + maxValue(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && student.skill_score < node->left->student.skill_score) {
        return rotateRight(node);
    }

    if (balance < -1 && student.skill_score > node->right->student.skill_score) {
        return rotateLeft(node);
    }

    if (balance > 1 && student.skill_score > node->left->student.skill_score) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && student.skill_score < node->right->student.skill_score) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVL::insertStudent(Student student) {
    root = insert(root, student);
}

void AVL::inorder(Node* node, int& position) {
    if (node != nullptr) {
        inorder(node->right, position);

        cout << position << ". " 
             << node->student.full_name 
             << " - Score: " 
             << node->student.skill_score << endl;

        position++;

        inorder(node->left, position);
    }
}

void AVL::showRanking() {
    if (root == nullptr) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    int position = 1;
    cout << "\nRanking Academico:\n";
    inorder(root, position);
}

Node* AVL::search(Node* node, int skill_score) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->student.skill_score == skill_score) {
        return node;
    }

    if (skill_score < node->student.skill_score) {
        return search(node->left, skill_score);
    } else {
        return search(node->right, skill_score);
    }
}

void AVL::searchByScore(int skill_score) {
    Node* result = search(root, skill_score);

    if (result == nullptr) {
        cout << "No se encontro estudiante con ese skill_score." << endl;
    } else {
        cout << "\nEstudiante encontrado:\n";
        cout << "ID: " << result->student.student_id << endl;
        cout << "Nombre: " << result->student.full_name << endl;
        cout << "Carrera: " << result->student.career << endl;
        cout << "Semestre: " << result->student.semester << endl;
        cout << "GPA: " << result->student.gpa << endl;
        cout << "Skill Score: " << result->student.skill_score << endl;
    }
}

void AVL::showStats() {
    cout << "\nEstadisticas AVL:\n";
    cout << "Altura actual del arbol: " << height(root) << endl;
    cout << "Factor de balance de la raiz: " << balanceFactor(root) << endl;
    cout << "Cantidad de nodos insertados: " << totalNodes << endl;
}