// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "Student.h"

Student::Student()
{
  ID_ = " ";
  gradePoints_ = 0;
  creditHours_ = 0;
  gpa_ = 0.0;
  letterGrade_ = 'F';
}

Student::Student(std::string ID, int gradePoints, int creditHours)
{
  ID_ = ID;
  gradePoints_ = gradePoints;
  creditHours_ = creditHours;
  gpa_ = (double)gradePoints_ / creditHours_;
  letterGrade_ = getLetterGrade();
}

Student::~Student()
{
  // Destructor implementation (if needed)
}

std::string Student::getID()
{
  return ID_;
}

int Student::getGradePoints()
{
  return gradePoints_;
}

int Student::getCreditHours()
{
  return creditHours_;
}

void Student::printInfo()
{
  std::cout << ID_ << ": " << std::fixed << std::setprecision(2) << gpa_ << "    " << letterGrade_ << std::endl;
}

double Student::getGPA()
{
  return gpa_;
}

char Student::getLetterGrade()
{
  if (gpa_ >= 3.5)
  {
    return 'A';
  }
  else if (gpa_ >= 3.0)
  {
    return 'B';
  }
  else if (gpa_ >= 2.0)
  {
    return 'C';
  }
  else if (gpa_ >= 1.0)
  {
    return 'D';
  }
  else
  {
    return 'F';
  }
}
