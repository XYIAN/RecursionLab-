/* TITLE lab9_1.cpp
 * ABSTRACT: this program will prompt for a text file of intergers
 * the program will then insert and sort every interger form the
 * into the array 
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/5/19
 */
 
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int x);
void sortNames (int values[], int fill);
void sortNumbers (int values[], int fill);
void readNames(ifstream &inFile, string names[], int y);
void swap(int x, int y);

int main()
{
    // File stream object
    ifstream inFile;
     
   //variables 
    int size;
    inFile >> size;
    cout << "DEBUG SIZE" << size; 
    string names[size]; 
    int ID[size]; 
     
    //int numbers[];

    // Open the input file.
    inFile.open("t1.txt");

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }
    
    
    //inFile >> size;
    // Read the numbers and names into the array.
    readNumbers(inFile, ID, size);
    readNames(inFile, names, size);
    
    //sortNames(names, size);
    sortNumbers(ID, size);
    
    /* **********************
       ****** Display ******* 
       **********************
    */
    cout << "DEBUG ID SORT: " ; 
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << i+1 << ". "<<  ID[i] ; 
    }

    // Close the file.
    inFile.close();
    
    
}

//function definitions///////////////////////////

//define read numbers -- insert numbers into array 
void readNumbers(ifstream &inFile, int ID[], int x)
{
   for (int i = 0; i < x; i++)
      inFile >> ID[i];
}
//define read names -- insert names into array
void readNames(ifstream &inFile, string names[], int y)
{
   for (int i = 0; i < y; i++)
      inFile >> names[i];
}

/*
//define sort names -- sort names in ascending order
void sortNames (int values[], int fill)
{
    
}
*/

//define sort numbers -- sort ID array in ascending order 
void sortNumbers (int values[], int fill)
{
    for(int i = 0; i < fill - 1; i++)
    {
        //set temp value
        int temp ;
        temp = values[i+1]; 
        
        
        //check sorted 
        for(int j = i ; j >=  0 ; j--)
        {
            //swaping 
            if(values[j] > temp)
            {
                swap(values[j], values[j+1]);
            }
            else
            {
                values[j+1] = temp; 
                break; 
            }
        }
    }
}

void swap(int x, int y)
{
    int temp; 
    temp = x;
    y = x; 
    x = temp; 
}