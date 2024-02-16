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
#include <string>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"
#include "strlib.h"
using namespace std;

/*
 * Function: isElementSpellable
 * -----------------------------
 * Write a function that accepts as input a string and a Set<string>
 * containing all element symbols (stored with the proper
 * capitalization), then returns whether that string can be
 * written using only element symbols.
 */
bool isElementSpellable(const string& text, const Set<string>& symbols) {
    if (text.length() == 0) {
        return true;
    }
    for (int i = 0; i < text.length(); i++) {
        string currChar = toUpperCase(text.substr(i, 1));
        string nextChar = toLowerCase(text.substr(i + 1, 1));
        string doubleChar = currChar + nextChar;
        if (symbols.contains(currChar) && symbols.contains(doubleChar)) {
            return isElementSpellable(text.substr(i + 1), symbols) ||
                   isElementSpellable(text.substr(i + 2), symbols);
        }
        if (symbols.contains(currChar)) {
            return isElementSpellable(text.substr(i + 1), symbols);
        }
        if (symbols.contains(doubleChar)) {
            return isElementSpellable(text.substr(i + 2), symbols);
        }
    }
    return false;
}
bool wordSpellWithElem(const string& text, const Set<string>& symbols, string& result) {
    if (text.length() == 0) {
        result = "";
        return true;
    }
    for (int i = 0; i < text.length(); i++) {
        string currChar = toUpperCase(text.substr(i, 1));
        string doubleChar = currChar + toLowerCase(text.substr(i + 1, 1));
        if (symbols.contains(currChar) && symbols.contains(doubleChar)) {
            if (wordSpellWithElem(text.substr(i + 1), symbols, result)) {
                result = currChar + result;
                return true;
            }
            if (wordSpellWithElem(text.substr(i + 2), symbols, result)) {
                result = doubleChar + result;
                return true;
            }
        }
        if (symbols.contains(currChar)) {
            if (wordSpellWithElem(text.substr(i + 1), symbols, result)) {
                result = currChar + result;
                return true;
            }
        }
        if (symbols.contains(doubleChar)) {
            if (wordSpellWithElem(text.substr(i + 2), symbols, result)) {
                result = doubleChar + result;
                return true;
            }
        }
    }
    return false;
}

string closestApproximationTo(const string& text, const Set<string>& symbols) {
    return "";
}
/* * * * * Student Tests Below This Point * * * * */
STUDENT_TEST("Student Test: Verify that the solution works on examples from the handout.") {
    Set<string> symbols = {
        "H", "He", "Li", "Be", "B",
        "C", "N", "O", "F", "Ne", "Na",
        "Mg", "Al", "Si", "P", "S", "Cl",
        "Ar", "K", "Ca", "Sc", "Ti", "V",
        "Cr", "Mn", "Fe", "Co", "Ni",
        "Cu", "Zn", "Ga", "Ge", "As",
        "Se", "Br", "Kr", "Rb", "Sr",
        "Y", "Zr", "Nb", "Mo", "Tc",
        "Ru", "Rh", "Pd", "Ag", "Cd",
        "In", "Sn", "Sb", "Te", "I",
        "Xe", "Cs", "Ba", "La", "Ce",
        "Pr", "Nd", "Pm", "Sm", "Eu",
        "Gd", "Tb", "Dy", "Ho", "Er",
        "Tm", "Yb", "Lu", "Hf", "Ta",
        "W", "Re", "Os", "Ir", "Pt",
        "Au", "Hg", "Tl", "", "Pb",
        "Bi", "Po", "At", "Rn", "Fr",
        "Ra", "Ac", "Th", "Pa", "U",
        "Np", "Pu", "Am", "Cm", "Bk",
        "Cf", "Es", "Fm", "Md", "No",
        "Lr", "Rf", "Db", "Sg", "Bh",
        "Hs", "Mt", "Ds", "Rg", "Cn",
        "Nh", "Fl", "Mc", "Lv", "Ts",
        "Og"
    };
    string result = "";
    EXPECT_EQUAL(wordSpellWithElem("feline", symbols, result), true);
    EXPECT_EQUAL(wordSpellWithElem("interesting", symbols, result), false);
    EXPECT_EQUAL(wordSpellWithElem("Chemowizardry", symbols, result), true);

}
/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Verify that the solution works on examples from the handout.") {
  Set<string> symbols = {
    "H", "He", "Li", "Be", "B",
    "C", "N", "O", "F", "Ne", "Na",
    "Mg", "Al", "Si", "P", "S", "Cl",
    "Ar", "K", "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni",
    "Cu", "Zn", "Ga", "Ge", "As",
    "Se", "Br", "Kr", "Rb", "Sr",
    "Y", "Zr", "Nb", "Mo", "Tc",
    "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I",
    "Xe", "Cs", "Ba", "La", "Ce",
    "Pr", "Nd", "Pm", "Sm", "Eu",
    "Gd", "Tb", "Dy", "Ho", "Er",
    "Tm", "Yb", "Lu", "Hf", "Ta",
    "W", "Re", "Os", "Ir", "Pt",
    "Au", "Hg", "Tl", "", "Pb",
    "Bi", "Po", "At", "Rn", "Fr",
    "Ra", "Ac", "Th", "Pa", "U",
    "Np", "Pu", "Am", "Cm", "Bk",
    "Cf", "Es", "Fm", "Md", "No",
    "Lr", "Rf", "Db", "Sg", "Bh",
    "Hs", "Mt", "Ds", "Rg", "Cn",
    "Nh", "Fl", "Mc", "Lv", "Ts",
    "Og"
  };
  EXPECT_EQUAL(isElementSpellable("feline", symbols), true);
  EXPECT_EQUAL(isElementSpellable("interesting", symbols), false);
  EXPECT_EQUAL(isElementSpellable("Chemowizardry", symbols), true);
}
