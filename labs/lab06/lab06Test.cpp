#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main() {
    cout << "TESTS FOR incrWordCount()" << endl;

    WordCount words;

    ASSERT_EQUALS(1, words.incrWordCount("alice"));
    ASSERT_EQUALS(2, words.incrWordCount("alice"));
    words.incrWordCount("bob");

    cout << "\nTESTS FOR getWord*" << endl;
    ASSERT_EQUALS(2, words.getWordCount("alice"));
    ASSERT_EQUALS(0, words.getWordCount("connor"));
    ASSERT_EQUALS(2, words.getNumUniqueWords());
    ASSERT_EQUALS(3, words.getTotalWords());


    cout << "TESTS FOR decrWordCount()" << endl;
    ASSERT_EQUALS(1, words.decrWordCount("alice"));
    ASSERT_EQUALS(-1, words.decrWordCount("alice"));
    ASSERT_EQUALS(-1, words.decrWordCount("smolder"));

    cout << "\nMore TESTS FOR getWord*" << endl;
    ASSERT_EQUALS(1, words.getNumUniqueWords());
    ASSERT_EQUALS(-1, words.decrWordCount("bob"));
    ASSERT_EQUALS(0, words.getWordCount("connor"));
    ASSERT_EQUALS(0, words.getNumUniqueWords());
    ASSERT_EQUALS(0, words.getTotalWords());

    cout << "\nTESTS FOR makeValidWord()" << endl;
    ASSERT_EQUALS("alice", words.makeValidWord("alice"));
    ASSERT_EQUALS("bob's", words.makeValidWord("bob's"));
    ASSERT_EQUALS("c-o-o-k-i-e", words.makeValidWord("---c-o-o-k-i-e---"));
    ASSERT_EQUALS("s'h'o'p", words.makeValidWord("''-'-'-'-'-'-s'h'o'p'''"));
    ASSERT_EQUALS("pcmn", words.makeValidWord("p@c3m$n"));
    ASSERT_EQUALS("", words.makeValidWord(""));
    ASSERT_EQUALS("", words.makeValidWord("---"));
    ASSERT_EQUALS("", words.makeValidWord("\n\n\n\r\t"));

    return 0;
}
