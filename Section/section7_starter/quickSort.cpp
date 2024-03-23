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
#include "cell.h"
#include "utility.h"
#include "error.h"
using namespace std;

/*
 * Function: quickSort
 * --------------------
 * Takes in a linked list and sorts it in-place using the 
 * quickSort algorithm.
 */
Cell* lastElem(Cell* list) {
    if (list == nullptr) error("Empty linked list!");
    if (list->next == nullptr) return list;
    return lastElem(list->next);
}

Cell* concatList(Cell* one, Cell* two) {
    if (one == nullptr) return two;
    lastElem(one)->next = two;
    return one;
}

void addElem(Cell*& list, Cell* elems) {
    elems->next = list;
    list = elems;
}

void splitList(Cell*& list, Cell*& smaller, Cell*& bigger, Cell*& pivot) {
    while (list != nullptr) {
        Cell* next = list->next;
        if (list->value < pivot->value) {
            addElem(smaller, list);
        }
        else if (list->value == pivot->value) {
            addElem(pivot, list);
        }
        else {
            addElem(bigger, list);
        }
        list = next;
    }
}

void quickSort(Cell*& list) {
    if (list == nullptr || list->next == nullptr) return;

    Cell* pivot = list;
    Cell* other = pivot->next;
    pivot->next = nullptr;
    Cell* smaller = nullptr;
    Cell* bigger = nullptr;

    splitList(other, smaller, bigger, pivot);
    quickSort(smaller);
    quickSort(bigger);

    pivot = concatList(pivot, bigger);
    smaller = concatList(smaller, pivot);
    list = smaller;
}

/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Small test for quickSort") {
    Cell* list = createListFromVector({7, 5, 87, 41, 137, 1, 2});
    Cell* sorted = createListFromVector({1, 2, 5, 7, 41, 87, 137});
    quickSort(list);
    EXPECT(listEqual(list, sorted));
    freeList(list);
    freeList(sorted);
}
