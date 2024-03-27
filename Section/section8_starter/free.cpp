/*
 * CS106B Section Handout Test Harness: Section 8
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Neel Kishnani for 
 * CS106B Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "error.h"
#include "set.h"
using namespace std;

/*
 * Function: free
 * ---------------
 * Frees all memory associated with tree given root. Note
 * that there is an implementation of this in this folder, 
 * but give this a try before looking!
 */
void free(Node* root) {
    while (root != nullptr) {
        if (root->left == nullptr) {
            Node* rest = root->right;
            delete root;
            root = rest;
        } else {
            Node* leftTree = root->left;
            root->left = leftTree->right;
            leftTree->right = root;
            root = leftTree;
        }
    }
}

PROVIDED_TEST("Simple tests for freeTree function") {
    Node* a = new Node;
    a->left = new Node;
    a->right = new Node;
    a->left->left = nullptr;
    a->left->right = nullptr;
    a->right->left = nullptr;
    a->right->right = nullptr;
    free(a); // Check that there are no leaks
}
