/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include "testing/SimpleTest.h"
#include "lexicon.h"
#include <string>
using namespace std;


int numSubwords(string word, const Lexicon& words) {
    Lexicon subwords;
    for (int i = 0; i < word.length(); i++) {
        for (int j = i; j <= word.length(); j++) {
            string substrOfWord = word.substr(i, j - i);
            if (!words.containsPrefix(substrOfWord)) break;
            if (words.contains(substrOfWord)) {
                subwords.add(substrOfWord);
            }
        }
    }
    return subwords.size();
}

string mostXzibitWord(const Lexicon& words) {
    int maxSum;
    int num = 0;
    string result = "";
    for (string word: words) {
        maxSum = numSubwords(word, words);
        if (maxSum > num) {
            result = word;
            num = maxSum;
        }
    }
    return result;
}

/* * * * * Provided Tests Below This Point * * * * */

static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

PROVIDED_TEST("Example from handout") {
    Lexicon& lex = sharedLexicon();
    EXPECT_EQUAL(mostXzibitWord(lex), "foreshadowers");
}
