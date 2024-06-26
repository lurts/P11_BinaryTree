//Modul:    Programmieren 2 - Praktikum
//Datum:    04.04.24 - 14:47:00
//Name:     Lars Ebbeke
//Aufgabe:  P11_BinaryTree
//Todo:
//-

#include <iostream>
#include <fstream>
#include <queue>
#include "binaryTree.h"

//binaryTree::binaryTree(float w) {
//    value = w;
//    counter = 1;
//    left = nullptr;
//    right = nullptr;
//}

binaryTree::binaryTree(float w, unsigned z) {
    value = w;
    counter = z;
    left = nullptr;
    right = nullptr;
}

binaryTree::~binaryTree() {
    delete left;
    delete right;
}

unsigned binaryTree::getCount() {
    if (this != nullptr)
        return counter;
    else
        return 0;
}


void binaryTree::incCounter() {
    counter++;
}

void binaryTree::insert(float w) {
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



void binaryTree::durchlaufen() {
    if (left != nullptr)
        left->durchlaufen();

    std::cout << value << "\t" << counter << std::endl;

    if (right != nullptr)
        right->durchlaufen();
}


binaryTree* binaryTree::seek(float w) {
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

binaryTree* binaryTree::constructFromFile(std::string& path) {
    std::ifstream file(path);
    float number;

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

void binaryTree::prettyPrint(std::string indent) {
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