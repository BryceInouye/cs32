// Student.cpp
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student(string name, int age, int id): Person(name, age), studentId(id){}

/*
 * This will also work:
Student::Student(string name, int age, int id) : Person(name, age){
	studentId = id;
}
*/

int Student::getStudentId() { return studentId; }

void Student::setStudentId(int id) { studentId = id; }


Student::~Student() {
    cout << "in Student destructor" << endl; }
