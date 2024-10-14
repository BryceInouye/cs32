#include "grade.h"
#include<iostream>

std::string getLetterGrade(int score) {
    if (score > 90) { // bug 1: fails with 90
        return "A";
    } else if (score >= 80) {
        return "B";
    } else if (score >= 70) {
        return "C";
    } else if (score >= 60) {
        return "D";
    }
    return "F";
}

