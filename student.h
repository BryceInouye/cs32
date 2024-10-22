#ifndef STUDENT_H
#define STUDENT_H 

#include <string>

class Student {

 public:
  Student(const char * const name, int perm);

  int getPerm() const;
  const char * const getName() const;

  void setPerm(const int perm);
  void setName(const char * const name);

  Student(const Student &orig);
  ~Student();
  Student & operator=(const Student &right);

  std::string toString() const;

 private:
  int perm;
  char *name; // allocated on heap
};


#endif
