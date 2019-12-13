///////////////////////////////////////////////////////////////////////////////
//
// Author:           Faith Howell
// Assignment:       Program_04
// Date:             5th December 2019
// Title:            Program 4 - Cipher
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            cipher.cpp
//                   encrypted.txt
//                   decrypted.txt
//                   
// Description:
//       Program reads in an encrypted file and decrypts it.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

ifstream fin("encrypted.txt");
ofstream fout("decrypted.txt");

class CaesarCipher
{
private:

    string encrypt1; //encrypted string
    string decrypt1; //decrypted string
    int shift;
  
public:

    CaesarCipher();

    string Encrypt(string &p);   // encrypts a string given a specific shift value
    string Decrypt();   // decrypts a string given a specific shift value
    string UpperCase(); // a method that uppercases a string ( there are built in methods, but we will write our own)
    void SetShift();          // sets the shift amount for your class (default should be 13)
    string ReadCipherText();  // reads an encrypted file into a string
    void WriteCipherText();   // writes an encrypted message to a file
    string ReadPlainText();   // reads a plain text file into a string
    void WritePlainText();    // writes a plain text string to a file
};


CaesarCipher::CaesarCipher() {
	shift = 0;
	encrypt1 = " " ;
	decrypt1 = " ";
  
}
/**
 * Encrypt
 * 
 * Description:
 *      Encrypts plain text
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      encrypt1 : encrypted line
 */
string CaesarCipher::Encrypt(string &p){
    int intVal=0;
    encrypt1 = p;
for (int i = 0; i < p.size(); i++){
    if (p[i] >= 65 && p[i] <= 90){
    intVal = (int)p[i] - 65;  // Turn it into an integer number between 0-25
    intVal += shift;
    intVal = intVal % 26;       // Shift the letter, using mod to wrap back around
    p[i] = intVal + 65;       // Turn integer back into an ascii upper case letter
    }
}
    encrypt1 = p;
    return encrypt1;
}

/**
 * Decrypt
 * 
 * Description:
 *      decrypts an encrypted string
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      decrypt1 : decrypted string
 */
string CaesarCipher::Decrypt(){
int intVal = 0;
string p = decrypt1;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] >= 65 && p[i] <= 90)
        {
            intVal = (int)p[i] - 65; // Turn it into an integer number between 0-25
            intVal -= shift;
            if (intVal < 0) //if negative, add 26 to bring it back up
            {
                intVal += 26;
            }
            intVal = intVal % 26;  // Shift the letter, using mod to wrap back around
            p[i] = intVal + 65; // Turn integer back into an ascii upper case letter
        }
    }
    decrypt1 = p;
    return decrypt1;
}

/**
 * UpperCase
 * 
 * Description:
 *      cycles through plain text variable and subtracts 32
 *      from a character if it is lowercase
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      decrypt1, now completely uppercase if it wasn't already
 */
string CaesarCipher::UpperCase(){
    for(int i = 0; i < decrypt1.size(); i++){
        if(decrypt1[i] >= 97 && decrypt1[i] <= 122){
            decrypt1[i] -= 32;
        }
    }
    return decrypt1;
}
/**
 * SetShift
 * 
 * Description:
 *      reads shift from file
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      none
 */
void CaesarCipher::SetShift(){
    fin >> shift;
}

/**
 * ReadCipherText
 * 
 * Description:
 *      reads an entire line of encrypted text into encrypt1
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      encrypt1 : encrypted text
 */

string CaesarCipher::ReadCipherText(){

		SetShift();
		getline(fin, encrypt1);
		getline(fin, encrypt1);
    
    return encrypt1;
}

/**
 * WriteCipherText
 * 
 * Description:
 *      writes encrypted text to file  
 * Params:
 *      none
 * 
 * Returns:
 *      none
 */
void CaesarCipher::WriteCipherText(){
    fout<<encrypt1<<endl<<endl;
}


/**
 * ReadPlainText
 * 
 * Description:
 *      Reads plain text from a hypothetical plain text file
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      decrypt1 : plain text
 */
string CaesarCipher::ReadPlainText(){

    getline(fin, decrypt1);
    getline(fin, decrypt1);
    
    UpperCase();
    return decrypt1;
}

/**
 * WritePlainText
 * 
 * Description:
 *      writes decrypted text to file "decrypted.txt"
 * 
 * Params:
 *          none
 * 
 * Returns:
 *      None
 */
void CaesarCipher::WritePlainText(){
   fout<<decrypt1<<endl<<endl;
}


 /**
 * main
 * 
 * Description:
 *      uses a loop to call methods to read in encrypted text, decrypt it,
 *      and write it to the outfile for the entire file
 * 
 * Params:
 *      none
 * 
 * Returns:
 *      0
 */
 int main(){
    int count = 0;
    fin >> count;
    fout << "Faith Howell\n";
    fout << "December 5th 2019\n";
    fout << "Program 4\n\n";
      for(int i = 0; i < count; i++){
    CaesarCipher j;
    j.ReadCipherText();
    j.Decrypt();
    j.WritePlainText();
    }
    return 0;
}
