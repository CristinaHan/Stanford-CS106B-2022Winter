/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <cctype>
#include <fstream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "vector.h"
#include "SimpleTest.h"
#include "soundex.h"
using namespace std;

/* This function is intended to return a string which
 * includes only the letter characters from the original
 * (all non-letter characters are excluded)
 *
 * Confirm that letterOnly will return the right result
 * when the first character of string is not a letter
 */
string lettersOnly(string s) {
    string result = "";
    if (isalpha(s[0])) {
        result = charToString(s[0]);
    }
    for (int i = 1; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

string changeToNum(string s) {
    string allLetters = toUpperCase(s);
    string result = "";
    for (int i = 0; i < allLetters.length(); i++) {
        if (stringContains("AEIOUHWY", allLetters[i])) {
            result += "0";
        } else if (stringContains("BFPV", allLetters[i])) {
            result += "1";
        } else if (stringContains("CGJKQSXZ", allLetters[i])) {
            result += "2";
        } else if (stringContains("DT", allLetters[i])) {
            result += "3";
        } else if (stringContains("L", allLetters[i])) {
            result += "4";
        } else if (stringContains("MN", allLetters[i])) {
            result += "5";
        } else {result += "6";}
    }
    return result;
}

string mergeAdjacent(string s) {
    string result = charToString(s[0]);
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i+1] != s[i]) {
            result += s[i+1];
        }
    }
    return result;
}

string replaceFirst(string s) {
    string letterS = lettersOnly(s);
    string numS = changeToNum(letterS);
    string result = mergeAdjacent(numS);
    char first = toUpperCase(letterS[0]);
    result = charToString(first) + result.substr(1);
    return result;
}

string deleteZero(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            result += s[i];
        }
    }
    return result;
}

string sCode(string s) {
    string result = s;
    if (s.length() >= 4) {
        return s.substr(0, 4);
    }
    for (int i = 1; i <= 4 - s.length(); i++) {
        result += "0";
    }
    return result;
}
/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    /* TODO: Fill in this function. */
    s = replaceFirst(s);
    s = deleteZero(s);
    return sCode(s);
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // This provided code opens the specified file
    // and reads the lines into a vector of strings
    ifstream in;
    Vector<string> allNames;

    if (openFile(in, filepath)) {
        allNames = readLines(in);
    }
    cout << "Read file " << filepath << ", "
         << allNames.size() << " names found." << endl;

    // The names read from file are now stored in Vector allNames
    /* TODO: Fill in the remainder of this function. */
    string surname;
    Vector<string> result;
    while (true) {
        surname = getLine("Enter a surname (RETURN to quit): ");
        if (surname == "") {
            return;
        }
        string soundexCode = soundex(surname);
        cout << "Soundex code is " << soundexCode << endl;
        for (string name: allNames) {
            if (soundex(name) == soundexCode) {
                result.add(name);
            }
        }
        result.sort();
        cout << "Matches from database: " << result << endl;
        result.clear();
    }
}


/* * * * * * Test Cases * * * * * */

// TODO: add your STUDENT_TEST test cases here!
STUDENT_TEST("Confirm lettersOnly is bug-free") {
    string s = "9248SergioRamos";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "SergioRamos");
    s = " Kaka";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Kaka");
    s = "   ";
    result = "";
    EXPECT_EQUAL(result, "");
}

STUDENT_TEST("Test changeToNum") {
    string s = "SERGIORAMOS";
    string result = changeToNum(s);
    EXPECT_EQUAL(result, "20620060502");
    s = "KAKA";
    result = changeToNum(s);
    EXPECT_EQUAL(result, "2020");
}

STUDENT_TEST("Test mergeAdjacent") {
    string s = "SERGIORAMOS";
    string sNum = changeToNum(s);
    string result = mergeAdjacent(sNum);
    EXPECT_EQUAL(result, "2062060502");
    s = "KAKKA";
    sNum = changeToNum(s);
    result = mergeAdjacent(sNum);
    EXPECT_EQUAL(result, "2020");
}

STUDENT_TEST("Test replaceFirst") {
    string s = "9248SergioRamos";
    string result = replaceFirst(s);
    EXPECT_EQUAL(result, "S062060502");
    s = " Kakka";
    result = replaceFirst(s);
    EXPECT_EQUAL(result, "K020");
}

STUDENT_TEST("Test deleteZero") {
    string s = "9248SergioRamos";
    string sNum = replaceFirst(s);
    string result = deleteZero(sNum);
    EXPECT_EQUAL(result, "S62652");
    s = " Kakka";
    sNum = replaceFirst(s);
    result = deleteZero(sNum);
    EXPECT_EQUAL(result, "K2");
}

STUDENT_TEST("Test sCode") {
    string s = "9248SergioRamos";
    string sNum = replaceFirst(s);
    string sSingle = deleteZero(sNum);
    string result = sCode(sSingle);
    EXPECT_EQUAL(result, "S626");
    s = " Kakka";
    sNum = replaceFirst(s);
    sSingle = deleteZero(sNum);
    result = sCode(sSingle);
    EXPECT_EQUAL(result, "K200");
}
/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Test exclude of punctuation, digits, and spaces") {
    string s = "O'Hara";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");
}

PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}
