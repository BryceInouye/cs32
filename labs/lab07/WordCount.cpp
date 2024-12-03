// WordCount.cpp

#include "WordCount.h"
#include <algorithm> // std::sort

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int res = 0;

	for (auto vec : table) {
		for (auto word : vec) {
			res += word.second;
		}
	}

	return res;
}

int WordCount::getNumUniqueWords() const {
	int res = 0;

	for (auto vec : table) {
		for (auto word : vec) res++;
	}
	
	return res;
}

int WordCount::getWordCount(std::string word) const {
	int res = 0;
	word = makeValidWord(word);
	size_t hashKey = hash(word);

	const vPair& vec = table[hashKey];

	auto it = find_if(vec.begin(), vec.end(), [&word](const wordPair& pair) { return pair.first == word; });

	if (it != vec.end()) {
		res = it->second;
	}

	return res;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);

	if (word == "") return 0;

	int hashKey = hash(word);

	vPair& vec = table[hashKey];

	// if word in vector is not found, increment by 1
	auto it = find_if(vec.begin(), vec.end(), [&word](const wordPair& pair) { return pair.first == word; });
	if (it != vec.end()) 
	{
		it->second++;
	}
	else // add to the table
	{
		vec.push_back({word, 1});
		return 1;
	}

	// return it->second;
	return it->second;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);

	if (word == "") return -1;

	int res = -1;

	int hashKey = hash(word);
	vPair& vec = table[hashKey];

	auto it = find_if(vec.begin(), vec.end(), [&word](wordPair& pair) { return pair.first == word; });

	if (it != vec.end()) {
		it->second--;
		res = it->second;
		if (it->second == 0) {
			vec.erase(it);
			// res = -1;
		}
	}

	return res;
}


bool WordCount::isWordChar(char c) {
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	if (word == "") return "";

	string res = "";

	for (size_t i = 0; i < word.length(); i++) {
		if (isWordChar(word[i])) {
			res += tolower(word[i]);
		} 
		else if ((res.length() != 0 && i != word.length() - 1) && (word[i] == '-' || word[i] == '\''))
		{
			res += word[i];
		}
	}
	int i = res.length() - 1;

	while ((i >= 0) && (res[i] == '\'' || res[i] == '-')) {
		res = res.erase(i);
		i--;
	}


	return res;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// use std::sort with a function that compares keys
	out << "poopy poop";
	
	return;
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
	return;
}

void WordCount::addAllWords(std::string text) {
	// STUB
	return;
}
