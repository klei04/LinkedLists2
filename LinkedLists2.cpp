//This is a student list program using linked lists
//Author: Kevin Lei
//Date: 4/11/2021

#include "node.h"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//Function Prototypes
void ADD(Node* head, Student* newStudent);
void PRINT(Node* next);
void DELETE(Node* head, int id);
void AVERAGE(Node* head, float total, int numStudents);

int main() {

  cout << "Welcome to Student List" << endl;
  
  Node* head = NULL;
  char input[20];

  //While loop runs as long as QUIT isn't typed
  while (strcmp(input, "QUIT") != 0) {
    cout << "Type ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl;
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      char first[20];
      char last[20];
      int id;
      float gpa;
      cout << "ID:  ";
      cin >> id;
      cout << "Last Name: ";
      cin >> last;
      cout << "First Name: ";
      cin >> first;
      cout << "GPA: ";
      cin >> gpa;
      Student* newStudent = new Student(id, last, first, gpa);
      if (head == NULL) {
	head = new Node(newStudent);
      } else if (head->getStudent()->getID() > id) {
	Node* temp = head;
	head = new Node(newStudent);
	head->setNext(temp);
      }
      else {
	ADD(head, newStudent);
      }
    } else if (strcmp(input, "PRINT") == 0) {
      PRINT(head);
    } else if (strcmp(input, "DELETE") == 0) {
      if (head == NULL) {
	cout << "The list is empty" << endl;
      } else {
	int id;
	cout << "ID: ";
	cin >> id;

	if (head->getStudent()->getID() == id) {
	  Node* temp = head;
	  head = head->getNext();
	  delete(temp);
	} else {
	  DELETE(head, id);
	}
      }
    } else if (strcmp(input, "AVERAGE") == 0) {
      float sum = 0;
      int count = 0;
      AVERAGE(head, sum, count);
    } 
  }
  cout << "Goodbye!" << endl;

  return 0;
}

//Function to add a student to the list
void ADD(Node* head, Student* newStudent) {
  Node* current = head;
  if (current->getNext() == NULL || current->getNext()->getStudent()->getID() > newStudent->getID()) {
    Node* newNode = new Node(newStudent);
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    
  } else {
    ADD(head->getNext(), newStudent);
  }
}

//Function to print out all students
void PRINT(Node* head) {
  if (head != NULL) {
    cout << head->getStudent()->getFirstName();
    cout << " " << head->getStudent()->getLastName();
    cout << ", ID: " << head->getStudent()->getID();
    cout << ", GPA: " << fixed << setprecision(2) << head->getStudent()->getGPA() << endl;
    PRINT(head->getNext());
  }
}

//Function to delete a student based of ID
void DELETE(Node* current, int id) {
  if (current->getNext() != NULL) {
    if (current->getNext()->getStudent()->getID() == id) {
      Node* temp = current->getNext();
      current->setNext(temp->getNext());
      delete(temp);
    } else { 
      DELETE(current->getNext(), id);
    }
  } else {
    cout << "Student not found" << endl;
  }
}

//Function to print the average GPA in the list
void AVERAGE(Node* next, float sum, int count) {
  if (next != NULL) {
    sum += next->getStudent()->getGPA();
    count++;
    AVERAGE(next->getNext(), sum, count);
  } else {
    if (count == 0) {
      cout << "List is empty" << endl;
    } else {
      cout << fixed << setprecision(2) << (sum / count) << endl;
    }
  }
}
