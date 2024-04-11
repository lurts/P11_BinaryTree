//Modul:    Programmieren 2 - Praktikum
//Datum:    04.04.24 - 14:47:00
//Name:     Lars Ebbeke
//Aufgabe:  P11_BinaryTree
//Todo:
//-

#ifndef P11_BINARYTREE_BINARYTREE_H
#define P11_BINARYTREE_BINARYTREE_H

#endif //P11_BINARYTREE_BINARYTREE_H

class binaryTree {
    private:
        float value;
        unsigned counter;
        binaryTree* left;
        binaryTree* right;

    public:
        //Konstruktor
        binaryTree(float w);
        binaryTree(float w, unsigned z);
        //Destruktor
        ~binaryTree();

        unsigned getCount();

        //Zaehler inkrementieren
        void incCounter();
        //neuen eintrag am baum anhaengen
        void insert(float w);
        //baum in sortierter reihenfolge durchlaufen
        void durchlaufen();
        //Zeiger für ein gegebenes element suchen
        binaryTree* seek(float w);

        void prettyPrint(std::string indent);

};