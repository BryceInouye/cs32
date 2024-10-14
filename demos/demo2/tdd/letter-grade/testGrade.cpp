#include "grade.h"
#include "tddFuncs.h"
int main() {
    // normal cases
    assertEquals("A grade at 100", "A", getLetterGrade(100));
    
    assertEquals("B grade at 80", "B", getLetterGrade(80));

    assertEquals("D grade at 60", "D", getLetterGrade(60));

    assertEquals("F grade at 0", "F", getLetterGrade(0));

    assertEquals("B grade at 80", "B", getLetterGrade(80));

    assertEquals("A grade at 90", "A", getLetterGrade(90));

    assertEquals("B grade at 89.99999", "B", getLetterGrade(89.99999));


    // edge cases

    assertEquals("A grade at 1000", "A", getLetterGrade(1000));

    // assertEquals("F grade using string \"edge case\"", "F", getLetterGrade("edge case"));


    return 0;
}