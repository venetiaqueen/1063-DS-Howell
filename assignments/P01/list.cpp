#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

/** Created By: Faith Howell
  * Program #1
  Tuesday 17th September,2019
  */

struct EmployeeList
{ //list of variables
    string emp_id;
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    EmployeeList *Next;   //This creates node Next which will be used to connect Head and Temp nodes 



    EmployeeList()
    {
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }


    EmployeeList(string id, string first, string last, 
            string sex, string mail, double pay)
    {
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

//Faith Howell

class LinkedList
{
    EmployeeList *Head; //points to the first node
public:
    LinkedList()
    {
        Head = NULL;
    }


      void frontSert(string id,string first,string last,string sex,string mail, double pay){
        EmployeeList* Temp = new EmployeeList(id,first,last,sex,mail,pay);

          if(Head == NULL){
            Head = Temp;
        }
          else{
            Temp->Next = Head;
            Head = Temp;
        }   
    };


      void push_front(string id, string first, string last, 
                string sex, string mail, double pay) // this method is used to add employee info to the front of the list
    {
        EmployeeList *Temp = new EmployeeList(id, first, last, sex, mail, pay); // this creates a new node called Temp

        Head = Temp;
        cout<< Temp->emp_id << ", " <<Temp->first_name << ", " << Temp->last_name << endl;
    };

      void pop_remove(string id, string first, string last, 
             string sex, string mail, double pay)// this method is used to remove employee info to the front of the list
    {
        EmployeeList *Temp = Head; 
        Head = Temp->Next; 
        delete Temp; 
        cout<< Temp->emp_id << ", " <<Temp->first_name << ", " <<Temp->last_name << endl;
    }; 

//Faith Howell

     bool substringMatch(string macro, string micro)
  {

     return (macro.find(micro) != std::string::npos);

  };

     bool find(string email){// this method is used to find an employee email from the list
      ofstream fout;
      fout.open("output.dat");
      EmployeeList *Temp = Head; 
            EmployeeList *Result = Head; 
            bool found = false; 
            string macro, micro; 
            cout << "Please enter email address you would like to search:";
            cin >> micro;
            while(Temp)
            {

                macro = Temp->email; 
                Result = Temp; 
                Temp = Temp->Next; 
                
                if (macro.find(micro) != std::string::npos) 
                {
                    found = true;
                    fout << found << "\n"; 
                }
            } Temp = Temp->Next;
            return found;   

            fout.close();
     };

     
    

    void delete_email(string email){// this method is used to delete an employee email from the list

        string macro, micro;
        cout << "Please enter email of employee you would like to delete from the list: ";
        cin >> micro; 
            if (Head != NULL) {
			EmployeeList* Temp = Head;

			  while (Temp->Next != NULL) {
				  if (substringMatch(Temp->Next->email, email)) {
					cout << "\n" << Temp->Next->emp_id << ", " 
						<< Temp->Next->first_name << ", " << Temp->Next->last_name
						<< ", " << Temp->Next->email << ", " << Temp->Next->gender
						<< ", " << Temp->Next->hourly_pay << endl;

					  EmployeeList* ahead = Temp->Next->Next; 

					Temp->Next = ahead;  
              delete(Temp->Next); 
				   }
				Temp = Temp->Next;

			   }
        }
   
        if (substringMatch(macro, micro) == 0) 
        {
            cout << "Error.\n";
        }

            
    }; 

     void print(){// this method is used to print 30 employees from list in output.data 
    ofstream fout;
    fout.open("output.dat");//open file
        EmployeeList* Temp = Head;
        for(int i = 0; i < 30; i++){
            fout<<Temp->emp_id<<", "<<Temp->first_name<<", "<<Temp->last_name<<", "<<Temp->email<<", "<<Temp->gender<<", "<<Temp->hourly_pay << endl;
            Temp = Temp->Next;
            
        }cout<<" Employee List has been succesfully added to the file output.data\n";
        fout.close();// close file
    }
  



}; //Faith Howell

    int menu(){


    int choice = 0;
	  while (choice < 1 || choice > 4) {
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Add Employee\n";
		cout << "    3 - Delete Employee\n";
		cout << "    4 - Quit\n";
		cout << "Choice: ";
		cin >> choice; 
    
	}

	return choice;
}

 


    int main()
    {
       bool menu = 1; 
    
        LinkedList List; //list of variables
        string empid;
        string first;
        string last;
        string email;
        string gender;
        double pay;

         ifstream fin("employees.dat"); 

        while (!fin.eof()) 
        {                  
            fin >> empid >> first >> last >> email >> gender >> pay;

            List.frontSert(empid, first, last, email, gender, pay);
        };


    //Faith Howell


          while (menu == true)
        {
           
            int choice;
            cout << "\nMenu of Operations:\n";
            cout << "    1 - Find Employee\n";
            cout << "    2 - Add Employee\n";
            cout << "    3 - Delete Employee's Email \n";
            cout << "    5 - Print Employee Information\n";
            cout << "    6 - Quit\n";
            cin >> choice;
            switch (choice)
            {
            case 1: 
                List.find(email);
                break;

            case 2:
                List.push_front(empid, first, last, email, gender, pay);
                break;

            case 3:
                List.delete_email(empid);
                break;

            case 5:
                List.print();
                break;

            case 6:
                menu = 0;
                break;
            }
        }
    }
