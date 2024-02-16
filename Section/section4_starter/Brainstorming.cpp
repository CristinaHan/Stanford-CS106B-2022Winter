/*
 * CS106B Section Handout Test Harness: Section 4
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"
#include "map.h"
using namespace std;

/*
 * Function: matches
 * ------------------
 * Your task is to write a function that takes as input a
 * string and a pattern, then returns whether that string
 * matches the pattern.
 */
bool matchesRec(const string& text, int textIndex,
                const string& pattern, int patternIndex) {
    if (patternIndex == pattern.length()) {
        return textIndex == text.length();
    }
    else if (isalpha(pattern[patternIndex])) {
        return textIndex != text.length() &&
               text[textIndex] == pattern[patternIndex] &&
               matchesRec(text, textIndex + 1, pattern, patternIndex + 1);
    }
    else if (pattern[patternIndex] == '.') {
        return textIndex != text.length() &&
               matchesRec(text, textIndex + 1, pattern, patternIndex + 1);
    }
    else if (pattern[patternIndex] == '?') {
        return matchesRec(text, textIndex, pattern, patternIndex + 1) ||
               (textIndex != text.length() &&
                matchesRec(text, textIndex + 1, pattern, patternIndex + 1));
    }
    else {
        return matchesRec(text, textIndex, pattern, patternIndex + 1) ||
               (textIndex != text.length() &&
                matchesRec(text, textIndex + 1, pattern, patternIndex));
    }

}
bool matches(const string& text, const string& pattern) {
    return matchesRec(text, 0, pattern, 0);
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Testing *") {
    EXPECT_EQUAL(matches("apple", "a*"), true);
    EXPECT_EQUAL(matches("apply", "a*"), true);
    EXPECT_EQUAL(matches("apoplexy", "a*"), true);
    EXPECT_EQUAL(matches("Amicus", "a*"), false);
    EXPECT_EQUAL(matches("banana", "a*"), false);
}

PROVIDED_TEST("Provided Test: Testing .") {
    EXPECT_EQUAL(matches("three", "th..."), true);
    EXPECT_EQUAL(matches("threshold", "th..."), false);
}

PROVIDED_TEST("Provided Test: Testing ?") {
    EXPECT_EQUAL(matches("color", "colo?r"), true);
    EXPECT_EQUAL(matches("colour", "colo?r"), true);
    EXPECT_EQUAL(matches("colouxr", "colo?r"), false);
}
