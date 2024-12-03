#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream> // for oss

using namespace std;

int main() {
    cout << "TESTS FOR incrWordCount()" << endl;

    WordCount words;

    ASSERT_EQUALS(1, words.incrWordCount("alice"));
    ASSERT_EQUALS(2, words.incrWordCount("alice"));
    words.incrWordCount("bob");

    ostringstream oss;
    words.dumpWordsSortedByWord(oss);

    cout << oss.str() << endl;

    return 0;
}