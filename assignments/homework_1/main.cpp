// Faith Howell


#include <iostream> 
#include <string>
#include <ctime>     
#include <fstream>  

using namespace std; 

#define SIZE 20




struct Student
{
    string firstname; // first name of student
    string lastname; // last name of student
    int countGrades; // number of grades
    int grades[20]; // size of grades
};


int loadClassList(Student *classList, string fileName) // function used to open the file and read the data
{
    ifstream fin;   //readin   
    fin.open(fileName); // open the stream using fileName parameter
    int i = 0;          // index (counter)


    while (!fin.eof())
    { 
        fin >> classList[i].firstname >> classList[i].lastname >> classList[i].countGrades; //readin students' first name, lastname and no. of grades

        
  
for(int x = 0; x < classList[i].countGrades; x++) // 
{

      
      fin >> classList[i].grades[x];
}
  i++; // return count of grades
    }
    return i;
}


void printClassList(Student *classList, int classSize)
{
  ofstream fout;
  fout.open("student_output.dat");
  fout << "Students" << endl;
  fout << "==================================="<< endl;
  
    for (int i = 0; i < classSize; i++)
    {
        fout <<i+1<<". "
             << classList[i].firstname << " "
             << classList[i].lastname << ":\t";
    for ( int x = 0; x < classList[i].countGrades; x++)
    {
            fout << classList[i].grades[x] << "  ";

    }

    fout<<endl;
}
fout.close();
}


int main()
{
  
     
    Student classList[100];
    int classSize = 0;

    classSize = loadClassList(classList, "input_data.txt");

    printClassList(classList, classSize);


    return 0;
} 
