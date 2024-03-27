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

/* Function: contains
 * -------------------
 * Given the root of a tree and a key, returns 
 * true if the key is in the tree, and false if
 * not.
 */
bool contains(Node* root, int key) {
    if (root == nullptr) return false;
    return root->data == key || contains(root->left, key) || contains(root->right, key);
}

/* Function: insert
 * ------------------
 * Given the root of a tree and a key, inserts 
 * the key in the right position given BST 
 * ordering.
 */
void insert(Node*& root, int key) {
    Node* curr = root;
    Node* prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        if (curr->data == key) return;
        else if (curr->data < key) curr = curr->right;
        else curr = curr->left;
    }

    curr = new Node;
    curr->data = key;
    curr->left = curr->right = nullptr;

    if (prev == nullptr) root = curr;
    else {
        if (prev->data > key) prev->left = curr;
        else prev->right = curr;
    }
}

PROVIDED_TEST("Simple Tests for Contains") {
    Node* tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 8, 10});
    EXPECT(contains(tree, 4));
    EXPECT(!contains(tree, 11));
    freeTree(tree);
}

PROVIDED_TEST("Simple Tests for Insert") {
    Node *tree = createTreeFromVector({/* Level 1*/ 5});
    Node *bigger = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, EMPTY});
    insert(tree, 3);
    EXPECT(treeEqual(tree, bigger));
    freeTree(tree);
    freeTree(bigger);
}
