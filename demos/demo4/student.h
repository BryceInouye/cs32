// Student.h 
#ifndef STUDENT_H 
#define STUDENT_H 
#include "person.h" 

class Student : public Person { 
   public: 
        Student(std::string name, int age, int studentId); 
	   
        int getStudentId(); 
	   
        void setStudentId(int id); 

        ~Student();

   private: 
	    int studentId; 
}; 

#endif
