/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */
/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "console.h"
#include <iostream>
#include "SimpleTest.h"
#include "perfect.h"
using namespace std;


long smarterSum(long n) {
    /* TODO: Fill in this function. */
    long total = 0;
    if (n == 1) {
        return total;
    }
    for (int divisor = 2; divisor <= sqrt(n); divisor++) {
        if (n % divisor == 0) {
            if (divisor == sqrt(n)) {
                total += divisor;
            } else {
                total += divisor + n / divisor;
            }
        }
    }
    return total + 1;
}

long findNthPerfectEuclid(long n) {
    /* TODO: Fill in this function. */
    long s = 0;
    for (int k = 1; ; k++) {
        long m = pow(2, k) - 1;
        if (smarterSum(m) == 1) {
            s++;
            if (s == n) {
                return pow(2, k - 1) * m;
            }
        }
    }
}









