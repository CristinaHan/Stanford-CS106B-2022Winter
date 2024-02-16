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
#include "set.h"
#include "queue.h"
#include "strlib.h"
#include <fstream>
#include "tokenscanner.h"
#include "filelib.h"
#include "simpio.h"
using namespace std;

/*
 * See Stanford library's promptUserForFile function to get
 * a file into a stream format:
 * https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/filelib.html#Function:promptUserForFile
 */

/**
 * Asks the user for the name of a file to read.
 * The file is opened using the reference parameter <code>stream</code>.
 * The function returns the name of the file.
 * If the requested file cannot be opened, the user is given additional chances
 * to type a valid file name.
 *
 * The optional <code>prompt</code> argument provides an input prompt
 * for the user.
 *
 * The also optional <code>reprompt</code> argument provides an output message
 * displayed each time if the user types a file that is not found.
 * If no value is passed, defaults to, "Unable to open that file.  Try again.".
 */

/* Simple Edition */
/*
Set<string> wordsIn(istream& input) {
    Set<string> result = {};
    for (string line; getline(input, line);) {
        Vector<string> words = stringSplit(line, " ");
        for (int i = 0; i < words.size(); i++) {
            result.add(words[i]);
        }
    }
    return result;

STUDENT_TEST("Test wordsIn") {
    std::ifstream testTxt("res/TESTMY.txt");
    Set<string> rightAnswer = { "I", "all", "didn't", "say", "said", "the", "things" };
    EXPECT_EQUAL(wordsIn(testTxt), rightAnswer);
}
*/

string queueToString(Queue<string> kGram) {
    string result;
    while (!kGram.isEmpty()) {
        if (result != " ") result += " ";
        result += kGram.dequeue();
    }
    return result;
}

Set<string> kGramsIn(istream& input, int k) {
    if (k <= 0) error("k must be positive");
    TokenScanner scanner(input);
    scanner.addWordCharacters("'");

    Queue<string> kGram;
    Set<string> result;
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (scanner.getTokenType(token) == TokenScanner::TokenType::WORD) {
            kGram.enqueue(token);
            if (kGram.size() == k) {
                result.add(queueToString(kGram));
                (void) kGram.dequeue();
            }
        }
    }
    return result;
}

Set<string> wordsIn(istream& input) {
    return kGramsIn(input, 1);
}

int chooseKGramSize() {
    while (true) {
        int result = getInteger("Enter k: ");
        if (result > 0) return result;
        cout << "Please enter a positive interger" << endl;
    }
}
Set<string> contenTsOfFileChoice(int k) {
    ifstream input;
    promptUserForFile(input, "Enter file name: ");
    return kGramsIn(input, k);
}

int main() {
    int k = chooseKGramSize();
    Set<string> s1 = contenTsOfFileChoice(k);
    Set<string> s2 = contenTsOfFileChoice(k);

    double intersectSize = (s1 * s2).size();
    double uniontSize = (s1 + s2).size();

    cout << "Kaccard similarity: " << intersectSize / uniontSize << endl;
    return 0;
}
