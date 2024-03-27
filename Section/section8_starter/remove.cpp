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
 * Function: removeFrom
 * ---------------------
 * Given the root of a tree and a key to remove,
 * removes the key in-place.
 */
int largestDel(Node*& root);
void haveChild(Node*& root);

void haveChild(Node*& root) {
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
    }
    else if (root->left == nullptr) {
        Node* next = root->right;
        delete root;
        root = next;
    }
    else if (root->right == nullptr) {
        Node* next = root->left;
        delete root;
        root = next;
    }
    else {
        root->data = largestDel(root->left);
    }
}

int largestDel(Node*& root) {
    if (root->right == nullptr) {
        int result = root->data;
        haveChild(root);
        return result;
    }
    return largestDel(root->right);
}


void removeFrom(Node*& root, int value) {
    if (root == nullptr) return;
    else if (root->data < value) {
        removeFrom(root->right, value);
    }
    else if (root->data == value) {
        haveChild(root);
    }
    else {
        removeFrom(root->left, value);
    }
}

PROVIDED_TEST("Simple tests for remove function") {
    Node* tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, EMPTY});
    Node* modified = createTreeFromVector({ 5 });
    removeFrom(tree, 3);
    EXPECT(treeEqual(tree, modified));
    freeTree(tree);
    freeTree(modified);
}
