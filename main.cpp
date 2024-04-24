//Modul:    Programmieren 2 - Praktikum
//Datum:    04.04.24 - 14:41:53
//Name:     Lars Ebbeke
//Aufgabe:  P11-BinaryTree
//Todo:
//-

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "binaryTree.h"


bool eval(std::vector<float> elements, float target, int expect) {
    //neuen Baum anlegen
    binaryTree *bT;
    bT = new binaryTree(0);

    //Elemente am Baum anhängen
    for (float f : elements) {
        bT->insert(f);
    }

    //durchlaufen Funktion testen
    bT->durchlaufen();

    //pretty print?
    //bT->prettyPrint("");

    //Element im Baum finden und Zähler abfragen
    binaryTree *foundElement = bT->seek(target);
    int foundValue = foundElement->getCount();

    bool verdict = (foundValue == expect);

    std::cout << "\nExpected Value: " << expect << " Function returned: " << foundValue << "\n";

    if (verdict == true)
        std::cout << "OK\n\n";
    else
        std::cout << "NOK :c\n\n";

    delete bT;

    return verdict;
}


int main() {

    std::vector<float> elements;
    float target;
    int expect;

    int counter = 0;
    int tests = 0;

    //Test 1
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {5.0, -2.4, 10.0, 60.3, 10.1, 10,0};
    target = 10.0;
    expect = 2;

    if(eval(elements, target, expect))
        counter++;

    //Test 2
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {3.14, 1.618, 2.718, 3.14159, 1.414};
    target = 3.14;
    expect = 1;

    if(eval(elements, target, expect))
        counter++;


    //Test 3
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {10.5, 20.75, 15.25, 10.5, 10.5};
    target = 10.5;
    expect = 3;

    if(eval(elements, target, expect))
        counter++;


    //Test 4
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {100.0, 50.0, 25.0, 75.0, 150.0};
    target = 75.0;
    expect = 1;

    if(eval(elements, target, expect))
        counter++;


    //Test 5
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {100.0, 50.0, 25.0, 75.0, 150.0};
    target = -10.0;
    expect = 0;

    if(eval(elements, target, expect))
        counter++;


    //Test 6
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {100.0, 50.0, 25.0, 75.0, 150.0, -10.0};
    target = -10.0;
    expect = 1;

    if(eval(elements, target, expect))
        counter++;

    //Test 7
    tests++;
    std::cout << "Running Test " << tests << "\n";

    elements = {-10.3, 50.0, 25.0, 50.1, 26.0, 25.5};
    target = 25.5;
    expect = 1;

    if(eval(elements, target, expect))
        counter++;


    //File Test
    std::cout << "File Test " << tests << "\n";

    std::string path = "Zahlen.txt";
    binaryTree *bT;
    bT = binaryTree::constructFromFile(path);

    bT->durchlaufen();
    delete bT;


    float percentage = (float(counter)/float(tests))*100.0;

    std::cout << counter << " out of " << tests << " Tests passed! - " << std::setw(3) << percentage << "%!";

    return 0;
}
