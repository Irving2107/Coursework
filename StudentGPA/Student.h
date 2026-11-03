// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class Student
{
public:
  Student();
  Student(std::string ID, int gradePoints, int creditHours);

  ~Student();

  std::string getID();
  int getGradePoints();
  int getCreditHours();
  void printInfo();
  double getGPA();
  char getLetterGrade();

private:
  std::string ID_;
  int gradePoints_;
  int creditHours_;
  double gpa_;
  char letterGrade_;
};
