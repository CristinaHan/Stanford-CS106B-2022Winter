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
 * Function: sumOfElementsIn
 * -------------------------
 * Takes in a list of integers and returns the sum of all 
 * elements.
 */
int sumOfElementsIn(Cell* list) {
    /* Iterative solution
    int result = 0;
    for (Cell* curr = list; curr != nullptr; curr = curr->next) {
        result += curr->value;
    }
    return result;
    */
    /* Recursive solution */
    if (list == nullptr) return 0;
    return list->value + sumOfElementsIn(list->next);
}

/*
 * Function: lastElementOf
 * ------------------------
 * Takes in a list of integers and returns a pointer to the 
 * last element in the list.
 */
Cell* lastElementOf(Cell* list) {
    /* Iterative solution
    if (list == nullptr) error("Empty linked list!");
    Cell* result = list;
    while (result->next != nullptr) {
        result = result->next;
    }
    return result;
    */
    /* Recursive solution */
    if (list == nullptr) error("Empty linked list!");
    if (list->next == nullptr) return list;
    return lastElementOf(list->next);
}


/* * * * * Provided Tests Below This Point * * * * */
#include "vector.h"

PROVIDED_TEST("Small test for sumOfElementsIn") {
    Cell* list = createListFromVector({1, 2, 3, 4, 5});
    EXPECT_EQUAL(sumOfElementsIn(list), 15);
    freeList(list);

    Vector<int> nums;
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        nums.add(i);
        total += i;
    }

    Cell* biggerList = createListFromVector(nums);
    EXPECT_EQUAL(sumOfElementsIn(biggerList), total);
    freeList(biggerList);
}

PROVIDED_TEST("Small test for lastElementOf") {
    Cell* list = createListFromVector({1,2,3});
    EXPECT_EQUAL(lastElementOf(list), list->next->next);
    freeList(list);
}
