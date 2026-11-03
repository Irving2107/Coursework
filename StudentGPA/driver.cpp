// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "Student.h"

int main()
{
  std::ifstream inFile("students.txt");
  // Check if the file was opened successfully
  if (!inFile)
  {
    std::cerr << "Error opening file." << std::endl;
    return 1;
  }

  int i, j;

  // Read and process the file contents
  std::string ID;
  int gradePoints;
  int creditHours;

  // Create an array of Student objects for sorting and printing
  const int studentSize = 30;
  Student studentArr[studentSize];

  // This creates the student objects and stores them in the array
  i = 0;
  while (inFile >> ID >> gradePoints >> creditHours)
  {
    Student student(ID, gradePoints, creditHours);
    studentArr[i] = student;
    i++;
  }

  // This is a simple bubble sort algorithm to sort the students by GPA in descending order
  for (i = 0; i < studentSize - 1; i++)
  {
    for (j = 0; j < studentSize - i - 1; j++)
    {
      if (studentArr[j].getGPA() < studentArr[j + 1].getGPA())
      {
        Student temp = studentArr[j];
        studentArr[j] = studentArr[j + 1];
        studentArr[j + 1] = temp;
      }
    }
  }

  // Simple loop to print the sorted student information
  for (i = 0; i < studentSize; i++)
  {
    studentArr[i].printInfo();
  }

  inFile.close();

  return 0;
}