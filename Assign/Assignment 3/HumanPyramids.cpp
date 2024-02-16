#include "HumanPyramids.h"
#include "error.h"
#include "map.h"
#include "vector.h"
using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
double weightOnBackRec(int row, int col, int pyramidHeight,
                       Map<Vector<int>, double>& backDone) {
    if (row < 0 || row > pyramidHeight - 1 || col < 0 || col > pyramidHeight - 1) {
        error("The person is out of bounds!");
    }
    else if (row == 0) {
        return 0;
    }
    else {
        Vector<int> position = { row, col };
        if (backDone.containsKey(position)) {
            return backDone[position];
        }
        else {
            double newBackDone;
            if (col == 0) {
                newBackDone = weightOnBackRec(row - 1, col, pyramidHeight, backDone) / 2 + 80;
            }
            else if (col == row) {
                newBackDone = weightOnBackRec(row - 1, col - 1, pyramidHeight, backDone) / 2 + 80;
            }
            else {
                newBackDone = 160 +
                              weightOnBackRec(row - 1, col - 1, pyramidHeight, backDone) / 2 +
                              weightOnBackRec(row - 1, col, pyramidHeight, backDone) / 2;
            }
            backDone[position] = newBackDone;
            return newBackDone;
        }
    }
}

double weightOnBackOf(int row, int col, int pyramidHeight) {
    Map<Vector<int>, double> backs = {};
    return weightOnBackRec(row, col, pyramidHeight, backs);
}
/*
double weightOnBackOf(int row, int col, int pyramidHeight) {
    double weight = 160;
    if (row < 0 || row > pyramidHeight - 1 || col < 0 || col > pyramidHeight - 1) {
        error("The person is out of bounds!");
    }
    if (row == 0) {
        return 0;
    }
    else if (row == 1) {
        return weight / 2;
    }
    else if (col == 0) {
        return weightOnBackOf(row - 1, col, pyramidHeight) / 2 + weight / 2;
    }
    else if (col == row) {
        return weightOnBackOf(row - 1, col - 1, pyramidHeight ) / 2 + weight / 2;
    }
    else {
        return weight + weightOnBackOf(row - 1, col - 1, pyramidHeight ) / 2 +  weightOnBackOf(row - 1, col, pyramidHeight) / 2;
    }
}
*/




/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
STUDENT_TEST("Test the condition of error") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 4));
    EXPECT_ERROR(weightOnBackOf(5, 1, 4));
}

STUDENT_TEST("Test the value of back") {
    EXPECT_EQUAL(weightOnBackOf(0, 0, 5), 0);
    EXPECT_EQUAL(weightOnBackOf(2, 0, 5), 120);
    EXPECT_EQUAL(weightOnBackOf(3, 1, 5), 340);
    EXPECT_EQUAL(weightOnBackOf(4, 2, 5), 500);
}
/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
STUDENT_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(190, 100, 200) >= 10000);
}
