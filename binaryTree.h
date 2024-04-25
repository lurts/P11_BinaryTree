//Modul:    Programmieren 2 - Praktikum
//Datum:    04.04.24 - 14:47:00
//Name:     Lars Ebbeke
//Aufgabe:  P11_BinaryTree
//Todo:
//-

#ifndef P11_BINARYTREE_BINARYTREE_H
#define P11_BINARYTREE_BINARYTREE_H

#endif //P11_BINARYTREE_BINARYTREE_H

#include <iostream>
#include <fstream>

template <typename T>

class binaryTree {
private:
    T value;
    unsigned counter;
    binaryTree* left;
    binaryTree* right;

public:
    //Konstruktor
    //binaryTree(float w);
    binaryTree(T w, unsigned z = 1);
    //Destruktor
    ~binaryTree();

    binaryTree(const binaryTree& src) = delete;

    unsigned getCount();

    //Zaehler inkrementieren
    void incCounter();
    //neuen eintrag am baum anhaengen
    void insert(T w);
    //baum in sortierter reihenfolge durchlaufen
    void durchlaufen();
    //Zeiger für ein gegebenes element suchen
    binaryTree* seek(T w);

    //construct a Tree from a file
    static binaryTree* constructFromFile(std::string& path);

    void prettyPrint(std::string indent);
};



//binaryTree::binaryTree(float w) {
//    value = w;
//    counter = 1;
//    left = nullptr;
//    right = nullptr;
//}

template <typename T>
binaryTree<T>::binaryTree(T w, unsigned z) {
    value = w;
    counter = z;
    left = nullptr;
    right = nullptr;
}

template <typename T>
binaryTree<T>::~binaryTree() {
    delete left;
    delete right;
}

template <typename T>
unsigned binaryTree<T>::getCount() {
    if (this != nullptr)
        return counter;
    else
        return 0;
}

template <typename T>
void binaryTree<T>::incCounter() {
    counter++;
}

template <typename T>
void binaryTree<T>::insert(T w) {
    binaryTree* current = this;

    while (current != nullptr) {
        if (w < current->value) {
            if (current->left == nullptr) {
                current->left = new binaryTree(w);
                break;
            }
            else
                current = current->left;
        }
        if (w > current->value) {
            if (current->right == nullptr) {
                current->right = new binaryTree(w);
                break;
            }
            else
                current = current->right;
        }
        if (w == current->value) {
            current->incCounter();
            break;
        }
    }
}


template <typename T>
void binaryTree<T>::durchlaufen() {
    if (left != nullptr)
        left->durchlaufen();

    std::cout << value << "\t" << counter << std::endl;

    if (right != nullptr)
        right->durchlaufen();
}

template <typename T>
binaryTree<T>* binaryTree<T>::seek(T w) {
    binaryTree* current = this;

    while (current != nullptr) {
        if (w < current->value)
            current = current->left;
        else if (w > current->value)
            current = current->right;
        else if (w == current->value)
            return current;
    }

    return nullptr;
}

template <typename T>
binaryTree<T>* binaryTree<T>::constructFromFile(std::string& path) {
    std::ifstream file(path);
    T number;

    //Wenn Datei nicht geöffnet werden kann funktion verlassen
    if (!file.is_open()) {
        return nullptr;
    }

    file >> number;

    binaryTree *bT;
    bT = new binaryTree(number);


    while (file >> number) {
        bT->insert(number);
    }

    return bT;
}

template <typename T>
void binaryTree<T>::prettyPrint(std::string indent) {
    std::cout << "W: " << value << std::endl;
    std::cout << indent << "L: ";
    if (left)
        left->prettyPrint(indent+"   ");
    else
        std::cout << "-" << std::endl; // nullptr
    std::cout << indent << "R: ";
    if (right)
        right->prettyPrint(indent+"   ");
    else
        std::cout << "-" << std::endl; // nullptr
}