//Modul:    Programmieren 2 - Praktikum
//Datum:    04.04.24 - 14:47:00
//Name:     Lars Ebbeke
//Aufgabe:  P11_BinaryTree
//Todo:
//-

#include "binaryTree.h"

binaryTree::binaryTree(float w) {
    value = w;
    counter = 1;
    left = nullptr;
    right = nullptr;
}

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