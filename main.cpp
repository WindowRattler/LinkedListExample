//BenjaminKramer
//12-7-2020

//The main file for the LinkedList illustration
#include "linklistmod.h"
#include <iostream>

using namespace std;

//main
int main() {
  //illustration of addListItem
  cout << "\n" << endl;
  LinkedList l("Delilah");
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
  cout << endl;
  l.addListItem("Bob");
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
  cout << endl;
  l.addListItem("Rupert");
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
  cout << endl;
  l.addListItem("Sandy");
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
  cout << endl;
  //illustration of insertAtPosition
  //adds Dave to be the fourth
  //item in the list
  l.insertAtPosition("Dave", 3);
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
  //illustration of deleteAtPosition
  //removes Bob from the list
  l.deleteAtPosition(1);
  l.outputList();
  cout << "\n" << endl;
  l.outputLength();
}
