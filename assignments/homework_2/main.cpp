/**
 * Faith Howell
 * CMPS 1063 
 * Tuesday 8th October 2019
 * Description: This program is used to resize an array.     Using methods such as checkResize, Enlarge and Reduce.
 *    
 */


#include <iostream>
#include "stdlib.h"
#include <fstream>

using namespace std;


class Stack{
  private:


  
public:


    int *A;         
    int start;   // top of array 
    int size; 


/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
  Stack(){

  size = 10;

  A = new int [size];

  start = -1;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack(int s){

  size = s;

  A = new int [size];

  start = -1;

}

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Push(int val){

  if(!Full()){

    start++;

    A[start] = val;

    return true;

  }else{

    return false;

  }
}
//Faith Howell
/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
int Pop(){

  if(!Empty()){

    int temp = 0;   

    temp = A[start];

    start--;

    return temp;

  }else{

    // should return a value that implies failuer, but good enough for now
    cout<<"Cannot remove item from empty stack"<<endl;

  }

  return 0;
}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Empty(){
  return start < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Full(){
  return (start == size - 1);
}

  /**
 * Print
 * Description:
 *    Prints data to output file in order
 * Params:
 *    int lrgest = largest size
 * Returns:
 *     void
 */
  void Print(int l, int c)
  {

    ofstream outfile; 
    outfile.open ("stack_out.dat");

    outfile << "Faith Howell\n";
    outfile << "Tuesday 8th October 2019\n";
    outfile << "Homework 2\n";

    outfile <<endl;
   

    outfile << "Stack size: " << c << endl;
    outfile << "Largest size: " << l << endl;
    outfile << "Values: ";
    for (int i = size; i >= 0; i--)
    {
      outfile << A[i] << " ";
    }

    outfile.close();
    
  }

  //Faith Howell
  /**
	 * checkResize
	 * Description:
	 *   Checks if stack needs to be resized
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
  double checkResize()
	{
		    int a;
        int b;
        if ((a + 1) / (float)b >= 0.8)
    {
      return 1;
    }
    else if ((a + 1) / (float)b <= 0.2)
    {
      return 2;
    }
    else
    {
      return 0;
    }
	}

/**
	 * Enlarge
	 * Description:
	 *   Resizes stack by 1.5 times
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
void Enlarge()
  {
    int new_size = size * 1.5; 
		int *B = new int[new_size]; 
		for (int i = 0; i < size; i++)
		{
			B[i] = A[i];
		}
		int *x = A;
		A = B;
		delete[] x;
  }

	/**
	 * Reduce
	 * Description:
	 *   Resizes stack by 0.5 times
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
void Reduce()
	{
    int a, b;
		size = b * 0.5;
    int *c = new int[size];

    for (int i = 0; i <= a; i++)
    {
      c[i] = A[i];
    }
    delete[] A;
    A = c;
  }
};
//Faith Howell
int main() {
  srand(34234); 

  ifstream fin;
	fin.open("input_data.txt");
	

	 int lrgest; 
	 int size;

	Stack S1; 
	
	while (!(fin.eof()))
	{
    char nums;
	  int data;
		fin >> nums; 
		fin >> data;

		if ( nums == '+')
		{
			S1.Push(data);
			lrgest++; 
			size++;
		}
		else if (nums == '-')
		{
			S1.Pop();
			size--; 
		}

	}

	if (S1.checkResize() >= 0.8)
	{
		S1.Enlarge();
	}
	else if (S1.checkResize() <= 0.2)
	{
		S1.Reduce();
	}

	S1.Print(lrgest, size); 

	
	fin.close();
	return 0;
}
