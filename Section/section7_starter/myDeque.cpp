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

#include "myDeque.h"
#include "error.h"
using namespace std;

Deque::Deque() {
    head = new Cell;
    tail = new Cell;
    head->next = tail;
    tail->prev = head;
    head->prev = tail->next = nullptr;

    numElems = 0;
}

Deque::~Deque() {
    while (head != nullptr) {
        Cell* next = head->next;
        delete head;
        head = next;
    }
}

bool Deque::isEmpty() const {
    return numElems == 0;
}

int Deque::size() const {
    return numElems;
}

Deque::Cell* Deque::creatNewCell(int value) {
    Cell* newCell = new Cell;
    newCell->value = value;
    numElems++;
    return newCell;
}

void Deque::remove(Cell* toRemove) {
    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;
    delete toRemove;
    numElems--;
}

void Deque::pushFront(int value) {
    Cell* newCell = creatNewCell(value);
    newCell->next = head->next;
    newCell->prev = head;
    newCell->prev->next = newCell;
    newCell->next->prev = newCell;
}

void Deque::pushBack(int value) {
    Cell* newCell = creatNewCell(value);
    newCell->next = tail;
    newCell->prev = tail->prev;
    newCell->prev->next = newCell;
    newCell->next->prev = newCell;
}

int Deque::peekFront() const {
    if (isEmpty()) error("Empty List!!");
    return tail->prev->value;
}

int Deque::peekBack() const {
    if (isEmpty()) error("Empty List!!");
    return head->next->value;
}

int Deque::popFront() {
    int result = peekFront();
    remove(head->next);
    return result;
}

int Deque::popBack() {
    int result = peekBack();
    remove(tail->prev);
    return result;
}
