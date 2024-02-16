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
#include "utility.h"
#include "error.h"
using namespace std;

struct DoublyLinkedCell {
    string value; // Or whatever type of data goes here
    DoublyLinkedCell* next;
    DoublyLinkedCell* prev;
}; 

/**
 * Function: makeEmptyList
 * ------------------------
 * Creates a new doubly-linked list with a dummy head and tail, 
 * then returns a pointer to the head.
 */
DoublyLinkedCell* makeEmptyList() {
    return nullptr;
}

/**
 * Function: printList
 * --------------------
 * Prints out the contents of a doubly-linked list whose dummy 
 * first and last elements are pointed at by the head and tail 
 * parameters.
 * 
 * Note: there is an implementation of this within this 
 * folder, but we recommend you code your own version 
 * for learning purposes!
 */
void printList(DoublyLinkedCell* head, DoublyLinkedCell* tail) {
    (void) head;
    (void) tail;
}

/**
 * Function: insertBefore
 * -----------------------
 * Takes in a newCell and a cell to insert the new cell before, 
 * and performs the pointer rewiring.
 */ 
void insertBefore(DoublyLinkedCell* newCell, DoublyLinkedCell* beforeMe) {
    (void) newCell;
    (void) beforeMe;
}

/**
 * Function: insertAfter
 * ----------------------
 * Takes in a newCell and a cell to insert the new cell after,
 * and perform the pointer rewiring.
 */
void insertAfter(DoublyLinkedCell* newCell, DoublyLinkedCell* afterMe) {
    (void) newCell;
    (void) afterMe;
}

/**
 * Function: append
 * -----------------
 * Uses pointer rewiring to append newCell to the tail pointer.
 */ 
void append(DoublyLinkedCell* tail, DoublyLinkedCell* newCell) {
    (void) tail;
    (void) newCell;
}

/**
 * Function: prepend
 * ------------------
 * Uses pointer rewiring to prepend newCell to the tail head.
 */ 
void prepend(DoublyLinkedCell* head, DoublyLinkedCell* newCell) {
    (void) head;
    (void) newCell;
}

/**
 * Function: remove
 * -----------------
 * Splices out toRemove from the linked list.
 */ 
void remove(DoublyLinkedCell* toRemove) {
    (void) toRemove;
}

/**
 * Function: freeList
 * ------------------
 * Frees all memory associated with the linked list that 
 * head points to.
 * 
 * Note: there is an implementation of this within this 
 * folder, but we recommend you code your own version 
 * for learning purposes!
 */ 
void freeList(DoublyLinkedCell* head) {
    (void) head;
}

// Create more STUDENT_TESTs here!

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Small test for insertBefore") {
    DoublyLinkedCell* front = new DoublyLinkedCell;
    DoublyLinkedCell* back  = new DoublyLinkedCell;
    DoublyLinkedCell* toAdd = new DoublyLinkedCell;

    front->next = back;
    back->prev = front;

    insertBefore(toAdd, back);
    EXPECT_EQUAL(back->prev, toAdd);
    EXPECT_EQUAL(toAdd->next, back);
    EXPECT_EQUAL(toAdd->prev, front);
    EXPECT_EQUAL(front->next, toAdd);

    delete front;
    delete back;
    delete toAdd;
}

PROVIDED_TEST("Small test for insertAfter") {
    DoublyLinkedCell* front = new DoublyLinkedCell;
    DoublyLinkedCell* back  = new DoublyLinkedCell;
    DoublyLinkedCell* toAdd = new DoublyLinkedCell;

    front->next = back;
    back->prev = front;

    insertAfter(toAdd, front);
    EXPECT_EQUAL(back->prev, toAdd);
    EXPECT_EQUAL(toAdd->next, back);
    EXPECT_EQUAL(toAdd->prev, front);
    EXPECT_EQUAL(front->next, toAdd);

    delete front;
    delete back;
    delete toAdd;
}

PROVIDED_TEST("Small test for remove") {
    DoublyLinkedCell* front = new DoublyLinkedCell;
    DoublyLinkedCell* back  = new DoublyLinkedCell;
    DoublyLinkedCell* middle = new DoublyLinkedCell;

    front->next = middle;

    middle->prev = front;
    middle->next = back;

    back->prev = middle;

    remove(middle);
    EXPECT_EQUAL(back->prev, front);
    EXPECT_EQUAL(front->next, back);

    delete front;
    delete back;
    // middle should've been deleted in remove()
}
