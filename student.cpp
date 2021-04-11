#include <iostream>
#include <cstring>

#include "student.h"

//Student Class

Student::Student(int newID, char* newLastName, char* newFirstName, float newGPA) {
  ID = newID;
  strcpy(firstName, newFirstName);
  strcpy(lastName, newLastName);
  GPA = newGPA;
}

int Student::getID() {
  return ID;
}

char* Student::getLastName() {
  return lastName;
}

char* Student::getFirstName() {
  return firstName;
}

float Student::getGPA() {
  return GPA;
}
