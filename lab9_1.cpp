/* TITLE lab9_1.cpp
 * ABSTRACT: this program will prompt for a text file of intergers
 * the program will then insert and sort every interger form the
 * into the array 
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/5/19
 */
// A sample program for insertion sort development.

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// Global constant for the array size.
const int ARRAY_SIZE = 10;

// Function prototypes
void readNumbers(ifstream &inFile, int numbers[], int size);
void insertion_sort (int values[], int size);

int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    inFile.open("ten_numbers.txt");

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }

    // Read the numbers into the array.
    readNumbers(inFile, numbers, ARRAY_SIZE);
    
    cout << "===== First 10 Numbers from Input File =====\n";
    for (int i=0; i < 10; i++)
        cout << numbers[i] << " ";
    cout << endl << endl;

    // Close the file.
    inFile.close();

    // Timer variables to measure the running time.
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the insertion sorting..." << endl;
    
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    insertion_sort(numbers, ARRAY_SIZE);
    
    // Measure the elapsed time after the starting clock.
    elapsedTime = clock() - startClock;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) << " seconds" << endl;
    
    cout << "\n===== First 10 Sorted Numbers =====\n";
    for (int i=0; i < 10; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    return 0;
}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************
void readNumbers(ifstream &inFile, int numbers[], int size)
{
   for (int i = 0; i < size; i++)
      inFile >> numbers[i];
}



// Sort an array of integer values in ascending order.
void insertion_sort (int values[], int size) 
{
    // Develop the insertion sort.
    //

    for(int i = 0; i < size - 1; i++)
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