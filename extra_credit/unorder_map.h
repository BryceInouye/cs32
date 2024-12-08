#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Exception.h"

// Template class for generic UnorderedMap. I have modified and built upon the previous week's lab so that it 
// to allow for greater code flexibility and to help organize data for this project.
namespace customDataStruct {
    template <typename T>
    class UnorderedMap {
    public:
        UnorderedMap();

        // Return total number of item occurrences
        int getTotalItems() const;

        // Return total number of unique items
        int getNumUniqueItems() const;

        // Return the number of occurrences for a specific item
        int getItemCount(T item) const;

        // Increment the number of occurrences
        int incrItemCount(T item, double price);

        // Decrement the number of occurrences
        int decrItemCount(T item);

        // Method to get sorted vector
        std::vector<std::pair<T, std::pair<int, double>>> getSortedVec() const;
        
        // Method to dump items sorted by key
        void dumpItemsSortedByItem(std::ostream &out) const;

        // Method to dump items sorted by occurrences
        void dumpItemsSortedByOccurrence(std::ostream &out) const;
        
        void dumpItemsSortedByValue(std::ostream &out) const;

    private:
        const static size_t CAPACITY = 10;  // Default capacity of hash table
        std::vector<std::pair<T, std::pair<int, int>>> table[CAPACITY]; // Modified structure

        size_t hash(T item) const;
    };
}

template <typename T>
customDataStruct::UnorderedMap<T>::UnorderedMap() {}

// Generic hash function
template <typename T>
size_t customDataStruct::UnorderedMap<T>::hash(T item) const {
    size_t accumulator = 0;
    for (size_t i = 0; i < item.size(); i++) {
        accumulator += item.at(i);
    }
    return accumulator % CAPACITY;
}

template <typename T>
int customDataStruct::UnorderedMap<T>::getTotalItems() const {
    int total = 0;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (auto &entry : table[i]) {
            total += entry.second.first;
        }
    }
    return total;
}

template <typename T>
int customDataStruct::UnorderedMap<T>::getNumUniqueItems() const {
    int count = 0;
    for (size_t i = 0; i < CAPACITY; ++i) {
        count += table[i].size();
    }
    return count;
}

template <typename T>
int customDataStruct::UnorderedMap<T>::getItemCount(T item) const {
    size_t index = hash(item);
    for (auto &entry : table[index]) {
        if (entry.first == item) {
            return entry.second.first;
        }
    }
    return 0;
}

template <typename T>
int customDataStruct::UnorderedMap<T>::incrItemCount(T item, double price) {
    size_t index = hash(item);
    for (auto &entry : table[index]) {
        if (entry.first == item) {
            ++entry.second.first;
            return entry.second.first;
        }
    }
    // item not found; insert into hash table
    table[index].emplace_back(item, std::make_pair(1, price));
    return 1;
}

template <typename T>
int customDataStruct::UnorderedMap<T>::decrItemCount(T item) {
    size_t index = hash(item);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == item) {
            if (it->second.first > 1) {
                --it->second.first;
                return it->second.first;
            } else {
                table[index].erase(it);
                return 0;
            }
        }
    }
    throw customException::InvalidKeyException();  // item not found
    return -1;
}

template <typename T>
std::vector<std::pair<T, std::pair<int, double>>> customDataStruct::UnorderedMap<T>::getSortedVec() const {
    std::vector<std::pair<T, std::pair<int, double>>> items;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (auto &entry : table[i]) {
            items.push_back(entry);
        }
    }
    std::sort(items.begin(), items.end(),
        [](const auto &a, const auto &b) { return a.first < b.first; });

    return items;
}

template <typename T>
void customDataStruct::UnorderedMap<T>::dumpItemsSortedByItem(std::ostream &out) const {
    std::vector<std::pair<T, std::pair<int, double>>> items;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (auto &entry : table[i]) {
            items.push_back(entry);
        }
    }

    std::sort(items.begin(), items.end(),
        [](const auto &a, const auto &b) { return a.first < b.first; });

    out << "\033[1mItem Name, Cost, Quantity\n\033[0m";
    char a = 'A';
    for (auto &item : items) {
        out << "[\033[1m" << a << "\033[0m]" << ": \033[3m" << item.first << "\033[0m" << ", Cost = " << item.second.second << " coin\n"; //, Quantity: " << item.second.first << "\n";
        a += 1;
    }
    return;
}

template <typename T>
void customDataStruct::UnorderedMap<T>::dumpItemsSortedByOccurrence(std::ostream &out) const {
    std::vector<std::pair<T, std::pair<int, double>>> items;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (auto &entry : table[i]) {
            items.push_back(entry);
        }
    }

    std::sort(items.begin(), items.end(),
        [](const auto &a, const auto &b) {
            if (a.second.first == b.second.first) return a.first < b.first;
            return a.second.first > b.second.first;
        });

    out << "\033[1mItem Name, Cost, Quantity\n\033[0m";
    char a = 'A';
    for (auto &item : items) {
        out << "[\033[1m" << a << "\033[0m]" << ": \033[3m" << item.first << "\033[0m" << ", Cost = " << item.second.second << " coin\n"; //, Quantity: " << item.second.first << "\n";
        a += 1;
    }
    return;
}

template <typename T>
void customDataStruct::UnorderedMap<T>::dumpItemsSortedByValue(std::ostream &out) const {
    std::vector<std::pair<T, std::pair<int, double>>> items;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (auto &entry : table[i]) {
            items.push_back(entry);
        }
    }

    std::sort(items.begin(), items.end(),
        [](const auto &a, const auto &b) {
            if (a.second.second == b.second.second) return a.first < b.first;
            return a.second.second > b.second.second;
        });
    out << "\033[1mItem Name, Cost, Quantity\n\033[0m";
    char a = 'A';
    for (auto &item : items) {
        out << "[\033[1m" << a << "\033[0m]" << ": \033[3m" << item.first << "\033[0m" << ", Cost = " << item.second.second << " coin\n"; //, Quantity: " << item.second.first << "\n";
        a += 1;
    }
    return;
}

#endif // UNORDERED_MAP
