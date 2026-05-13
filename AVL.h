#ifndef AVL_H
#define AVL_H

#include "Student.h"

struct Node {
    Student student;
    Node* left;
    Node* right;
    int height;

    Node(Student s) {
        student = s;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    Node* root;
    int totalNodes;

    int height(Node* node);
    int balanceFactor(Node* node);
    int maxValue(int a, int b);

    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);

    Node* insert(Node* node, Student student);
    void inorder(Node* node, int& position);
    Node* search(Node* node, int skill_score);

public:
    AVL();

    void insertStudent(Student student);
    void showRanking();
    void searchByScore(int skill_score);
    void showStats();
};

#endif
