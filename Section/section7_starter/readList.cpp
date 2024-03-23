/*
 * CS106B Section Handout Test Harness: Section 7
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Neel Kishnani for 
 * Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */
#include <iostream>
#include <string>
#include "testing/SimpleTest.h"
#include "error.h"
#include "simpio.h"
using namespace std;

/*
 * Struct definition to store string as value instead of int version
 * in cell.h
 */
struct Cell {
    string value;
    Cell *next;
};

/*
 * Function: readList
 * -------------------
 * Prompts the user 
 */
Cell* readList() {
    Cell* tailPointer = nullptr;
    Cell* list = nullptr;
    while (true) {
        string line = getLine("Input your sentence:");
        if (line == "") break;
        Cell* newCell = new Cell;
        newCell->value = line;
        newCell->next = nullptr;

        if (list == nullptr) {
            list = newCell;
            tailPointer = newCell;
        } else {
            tailPointer->next = newCell;
            tailPointer = newCell;
        }
    }
    return list;
}

/* * * * * Add any additional STUDENT_TESTS here * * * * */

// Note: no PROVIDED_TESTs since output relies on user interaction
