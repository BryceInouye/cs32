#include <iostream>
#include "SimpleList.h"
#include <type_traits>
#include <string>
using namespace std;

template <class T>
void setNull(T element) {}

template <class T>
void setNull(T*& element) {
    element = nullptr;
}

template <class T>
SimpleList<T>::SimpleList() {
    /*
    Also allocates the array elements with a size of CAPACITY.
    SimpleList constructor that sets numElements to 0 (i.e. the SimpleList is constructed with 0 elements). 
    */
    std::cout << "Hello, World!" << std::endl;  // DELETEME!
    elements = new T[CAPACITY];
    if (is_pointer<T>::value) {
        for (int i = 0; i < CAPACITY; i++) {
            setNull(elements[i]);
        }
    }
    numElements = 0;
}

template <class T>
void destroy(T element) {}

template <class T>
void destroy(T* element) {
    delete element;
}

// Destructor implementation
template <class T>
SimpleList<T>::~SimpleList() {
    /*
    SimpleList destructor must delete the dynamically allocated array on the heap as well as
    deleting any elements in SimpleList that exist on the heap
    */
   if (std::is_pointer<T>::value) {
    std::cout << "using a pointer!" << endl;
    for (int i = 0; i < CAPACITY; i++) {
        destroy(elements[i]);
    }
   }
    cout << "destructor called ay ay ay!" << endl;
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const {
    /*
    Returns the element at index location. Throws a InvalidIndexException. 
    if there is no element at index.
    */
   if (index >= CAPACITY || index < 0 || elements[index] == T()) {
    throw InvalidIndexException();
   }

    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    /*
    Returns true if the list is empty, false otherwise.
    */
    return !numElements;
}

template <class T>
T SimpleList<T>::first() const {
    /*
    Return the element at index 0. Throws an EmptyListException if the list is empty.
    */
   if (!numElements) throw EmptyListException();

   return elements[0];
}

template <class T>
T SimpleList<T>::last() const {
    /*
    Return the last element in the SimpleList. Throws an EmptyListException if the list is empty.
    */
   if (!numElements) throw EmptyListException();

   return elements[numElements - 1];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    /*
    Returns the number of items currently stored in the SimpleList.
    */
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    /*
    Inserts item at the first possible slot towards the end of the list. Throws a FullListException if
    the list is at Capacity.
    */
    if (numElements == CAPACITY) throw FullListException();

    elements[numElements] = item;
    this->numElements++;
    cout << "[";
    for (int i = 0; i < numElements; i++) {
    cout << elements[i] << " AND ";
   } cout << "]" << endl;
}

template <class T>
void SimpleList<T>::remove(int index) {
    /*
    Removes the element at index. You will need to shift all elements inserted after the index
    position down slot in the array in order to prevent any “holes” in the SimpleList.

    First checks if the SimpleList is empty - throws an EmptyListException if the SimpleList is empty.

    Throws an InvalidIndexException if there is no element at the index position.
    */
   if (this->empty()) throw EmptyListException();        // If empty list

   try {
        this->at(index);
   } catch (InvalidIndexException e) {
    throw InvalidIndexException();
   }
   cout << "PRE: [";
    for (int i = 0; i < numElements; i++) {
    cout << elements[i] << " AND ";
   } cout << "]" << endl;
   cout << "attempting to kill: " << elements[index] << endl;
   destroy(elements[index]);
    // 0 1 2
    // 1 2
    // numElements = 3
    // start(i = index=0), end(i < 2) -> repeats 2 times
    // 0 1 2
    // 0 2
    // start(i = index=1), end(i < 2) -> repeats 1 time
    // 0 1 2
    // 0 1
    // start(i = index=2), end(i = 2) -> repeats 0 time
    for (int i = index; i < numElements; i++) {
        cout << "index = " << index << endl;
        elements[i] = elements[i + 1];
    }
   
   numElements--;
    cout << "POST: [";   
    for (int i = 0; i < numElements; i++) {
    cout << elements[i] << " AND ";
   } cout << "]" << endl;
   
   return;
}
