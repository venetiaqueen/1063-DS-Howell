/**
* Homework 04
*
* List based queue
*
* Author: Faith Howell
* Date : Oct 14th 2019
/* */
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include "ListQueue.hpp"

using namespace std;

//overladed operator
ostream &operator<<(ostream &os, const Animal *a) {
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

int main() {

  ifstream fin("animals.txt");
	Animal* a;						//Animal object
	ListQueue LQ;                 // Queue instance 


	string name;
	double weight = 0.0;		//initialize variables
	double scary = 0.0;



	// While still animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary; 
		a = new Animal(name, weight, scary);
    
		LQ.Push(a);                       // push animal onto the stack
	}

	cout << endl;                     

	LQ.Print();                     // print queue to see where values are
	cout << endl << endl;

	a = LQ.Pop();
	cout << a << endl;				// pop items off the list and print
	a = LQ.Pop();					// them out.
	cout << a << endl;
	cout << endl << endl;


	LQ.Print();                     // print again to show front removal
	LQ.PrintPointers();

	Node* f = LQ.GetFront();        // We added this in class JUST to see what front
	cout << f->A << endl;			// pointed to.

	system("pause");
	return 0;
}
