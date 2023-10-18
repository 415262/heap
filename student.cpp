/*
  Allows user to create a list of students, their IDs, and GPAs.
  Started 10/03/2023, Completed 10/16/2023
 */

#include <iostream>
#include <vector>

using namespace std;

void addStudent();
void printList();
void deleteStudent();

struct Student {
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

bool isRunning = true;

string input; //input checks for the main functions, like ADD, PRINT, DELETE, and QUIT
int input2; //input2 checks for ID in the deleteStudent() fuction

vector<Student*> studentList; //Vector of Student*s
vector<Student*>::iterator pointer; //Iterator pointer to allow travelling/manipulating studentList

int main() {

  cout << "Begin process" << endl;

  while (isRunning) {
    cin >> input;
    
    if (input == "add" || input == "ADD") {
      addStudent();
    }
    if (input == "print" || input == "PRINT") {
      printList();
    }
    if (input == "delete" || input == "DELETE") {
      deleteStudent();
    }
    if (input == "quit" || input == "QUIT") {
      return 0;
    }

  }
  
}

void addStudent() { //Creates a new student prompting user for Name, ID, and GPA.
  
  Student* student = new Student();
  
  cout << "New Student first name: " << endl;
  cin >> student -> firstName;
  
  cout << "New Student last name: " << endl;
  cin >> student -> lastName;
  
  cout << "New Studnet id: " << endl;
  cin >> student -> id;
  
  cout << "New Student GPA: " << endl;
  cin >> student -> gpa;
  
  studentList.insert(studentList.end(), student);
  
  cout << "New Student created:" << endl;
  cout << "Name: " << student -> firstName << " " << student -> lastName << endl;
  cout << "GPA: " ;
  printf("%.2f", student -> gpa); //Reduces/Expands GPA to 2 decimal places.
  cout << " ID: " << student -> id << endl;
  cout << "Added." << endl;
}

void printList() { //Goes through studentList and prints each student's info
  
  cout << "List of students: " << endl;
  for (pointer = studentList.begin(); pointer < studentList.end(); pointer++) {
    //cout << *pointer << endl; USED FOR DEBUG

    cout << (*pointer) -> firstName << " " << (*pointer) -> lastName << endl;

    cout << "GPA: " << (*pointer) -> gpa << endl;
    cout << "ID: " << (*pointer) -> id << endl;

  }
  cout << "End of List." << endl;
  
}

void deleteStudent() { //Prompts user for a student ID, that student is removed from studentList.

  cout << "Type the ID of the student you wish to delete: " << endl;
  cin >> input2;
  for (pointer = studentList.begin(); pointer < studentList.end(); pointer++) {
    if ((*pointer) -> id == input2) {
      cout << "Deleted " << (*pointer) -> firstName << " " << (*pointer) -> lastName << " from list." << endl;
      delete *pointer;
      studentList.erase((pointer));
      break;
    }
  }

}
