///////////////////////////////////////////////////////////////////////////////
//
// Author:           FAITH HOWELL
// Assignment:       Program_03
// Date:             November 14 2019
// Title:            Program 3 - Arbitrary Precision Math
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            apm.cpp,  
//                   input_data.txt 
//                   output.num
// Description:
//       This program reads in a very large number as a string and uses a 
//       doubly linked list to add and  subtract the numbers
//       as per the file instructions.
//
///////////////////////////////////////////////////////////
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

ofstream fout ("output.num");

struct Node {
	int data;
	Node *Next;
	Node *Prev;

	Node(int d) {
		data = d;
		Next = NULL;
		Prev = NULL;
	}
};

class calNum {
private:
	Node *Head;               // Head of list pointer
	Node *Tail;               // Tail of list pointer
	int Count;                // Count of items in list
	void _DeleteTail();
public:
	calNum();                   // Constructor
  calNum(string);
	calNum(const calNum &);     // Copy Constructor
	~calNum();                  // Destructor
	int Size();
  void InsertFront(int);
	void InsertBack(int);
	void Print(ofstream &out);
	void RevPrint(ofstream &out);
  int Pop();
	void Delete();
  bool Empty();
	calNum Add(calNum num);
	calNum Sub(calNum num);
	
};

/**
 * Public Default Constructor
 */
calNum::calNum() {
	Head = Tail = NULL;
	Count = 0;
}


calNum::calNum(string num1) {
    Head = Tail = NULL;
    Count = 0;
    int digit=0;

  for(int i=0;i<num1.size();i++){
    digit = num1[i]-48;
       InsertBack(digit);
       Count++;

  }

}
/**
 * Public Copy Constructor
 *      constructs a new list with values from another list.
 */
calNum::calNum(const calNum &list) {
	Head = Tail = NULL; // Initialize pointers like always
	Count = 0;

	// Point to "Other" lists head. Even though its private we
	// can access it beacuase we are in a class of the same type.
	Node* Other = list.Head;

	// Travers the other list
	while (Other) {
		// Insert values into new nodes in this list.
		InsertBack(Other->data);
		Other = Other->Next;
	}
}

/**
 * Public Destructor
 */
calNum::~calNum() {
	Node *temp = Head;

	while (temp) {
		temp = temp->Next;
		delete Head;
		Head = temp;
	}
}

/**
 * Public InsertFront
 *
 * Adds item to head of list by calling private method with a node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void calNum::InsertFront(int data) {
	Node *Temp = new Node(data);

	if (!Head) {
		Head = Temp;
		Tail = Temp;
	}
	else {
		Head->Prev = Temp;
		Temp->Next = Head;
		Head = Temp;
	}
}

/**
 * Public InsertBack
 *
 * Adds item to tail of list by calling private method with a node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void calNum::InsertBack(int data) {
	Node *Temp = new Node(data);

	if (!Head) {
		Head = Temp;
		Tail = Temp;
	}
	else {
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Tail = Temp;
	}
}
/**
 * Pop
 *
 * Description:
 *      Pops the end of the list and updates new list
 *
 * Params:
 *      none
 *
 * Returns:
 *      int : the int at the end of the list
 */
int calNum::Pop() {

	int value = 0;
	if (Head)
	{
		value = Tail->data;
		Node *temp = Tail->Prev;

		delete Tail;

		Tail = temp;

		if (Tail)
			Tail->Next = NULL;
		else
			Head = NULL;

		this->Count--;
	}
	return value;
}

/**
 * Public Print
 *
 * Prints list 
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void calNum::Print(ofstream &out) {
	Node *Temp = Head;

	while (Temp) {
		out << Temp->data;
		
		Temp = Temp->Next;
	}
	out << endl;
}

/**
 * Private _DeleteTail
 *
 * Deletes last node in list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void calNum::_DeleteTail() {

	if (Tail) {
		Node *Temp = Tail;
		if (Tail == Head) {
			Tail = Head = NULL;
			delete Temp;
		}
		else {

			Tail = Tail->Prev;
			Tail->Next = NULL;
			delete Temp;
		}
		Count--;
	}
}

/**
 * Public Delete
 *
 * Deletes last node in list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void calNum::Delete() {
	_DeleteTail();
}

/**
 * Public Size
 *
 * Returns size of list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     int
 */
int calNum::Size() {
	return Count;
}


bool calNum::Empty(){
  return ((!Head) && (!Tail));
}

/**
 * Public RevPrint
 *
 *  Prints list in reverse
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void calNum::RevPrint(ofstream &out) {
	Node *Temp = Tail;

	while (Temp) {
		out << Temp->data;
		if (Temp->Prev) {
			out << "->";
		}
		Temp = Temp->Prev;
	}
	out << endl;
}
/**
 * Add
 *
 * Description:
 *      Adds two lists
 *
 * Params:
 *      calNum num    : The new list
 *
 * Returns:
 *      calNum : a doubly linked list with addition results
 */
calNum calNum::Add(calNum num)
{
	calNum List;
	while (this->Count > 0 || num.Count > 0)
		List.InsertFront(Pop() + num.Pop());

	Node *temp = List.Tail;
	while (temp)
	{
		if (temp->data >= 10)
		{
			if (temp->Prev == NULL)
			{
				List.InsertFront((temp->data / 10)); 
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
			else
			{
				temp->Prev->data += (temp->data / 10);
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
		}
		else {
			temp = temp->Prev;
		}
	}
	return List;
}
/**
 * Sub
 *
 * Description:
 *      Subtracts two lists 
 *
 * Params:
 *      calNum num    : The new list
 *
 * Returns:
 *      calNum : a doubly linked list with subtraction results
 */
calNum calNum::Sub(calNum num)
{
	calNum List;

	while (this->Count > 0 || num.Count > 0)
		List.InsertFront(Pop() - num.Pop());

	Node *temp = List.Tail;
	while (temp)
	{
		if (temp->data < 0)
		{
			if (temp->Prev == NULL)
			{
				List.InsertFront(0);
				temp = temp->Prev;
			}
			else
			{
				temp->Prev->data -= (1);
				temp->data = temp->data + 10;
				temp = temp->Prev;
			}
		}
		else {
			temp = temp->Prev;
		}
	}
	return List;
}


int main()
{

  fout << "Faith Howell\n";
  fout << "Program 3\n";
  fout << "Arbitrary Precision Math\n\n";
	ifstream fin;
	fin.open("input_data.txt");

	char op;
	int count;
	string num1,num2;



	fin >> count;
	for (int i = 1; i <= count; i++)
	{
    fin >> op >> num1 >> num2;
		calNum p(num1),num(num2);
	

		fout << "Operation " << i << ": ";
		switch (op)
		{
		case '+':
			fout << "Addition" << endl;
			fout << "Answer:" << endl << endl;
			(p.Add(num)).Print(fout);
			fout << endl;
			break;
		case '-':
			fout << "Subtraction" << endl;
			fout << "Answer:" << endl << endl;
			(p.Sub(num)).Print(fout);
			fout << endl;
			break;
    }
	}

	fin.close();
	fout.close();
	return 0;
}
