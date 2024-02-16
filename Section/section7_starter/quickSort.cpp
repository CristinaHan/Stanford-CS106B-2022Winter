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
void quicksort(Cell*& list) {
    (void) list;
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
