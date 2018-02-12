// Mark Arias
// CS 20A, Section #4118
// Assignment # 1, problem 6

// Summary of the program:
// Write a program that can be used to gather statistical data about the number of movies college students see
// in a month. The program should perform the following steps:
// -user input total students surveyed. dynamically allocate an array of integers of user input size
// -after array has been created, allow the user to populate each array element with the # of movies seen
// -calculate and display the average, median, and mode of values entered. 
// Write functions, (encapsulate complexity) for calucating median and mode
// -perform input validation: Do not accept negative numbers for input
// - use pointers to access array elements

#include <iostream>
#include <string>
#include <algorithm>	

using namespace std;



// Function Prototypes
// functions returns median as a double value
// accepts as parameters the pointer to the student array, and the length of array
double median(int *arr, int n);

int mode(int *arr, int SIZE);



// Main body of code
int main()
{
	cout << "*** Movie Viewing Habits of College Students ***" << endl;
	cout << "     This program will perform an analysis      " << endl;
	cout << endl;
	cout << "Please enter the total number of students surveyed: ";
	int studentTotal = 0;
	cin >> studentTotal;
	cout << endl;

	// this section performs the dynamic memory allocation
	int * intPointer;
	intPointer = new int[studentTotal];

	// populate the array
	int numberEntered;
	int total;	// for performing the average calculation
	for(int i = 0; i < studentTotal; i++)
	{
		cout << "Enter number: ";
		cin >> numberEntered;
		// performing input validation 
		if(numberEntered > 0)
		{
			// store the value entered via dereferencing the pointer at the plus ith location
			*(intPointer + i) = numberEntered;
			total += *(intPointer + i);	// perform running total here
		}
		else
		{
			// if user enters a negative number, set the number to zero
			*(intPointer + i) = 0;
		}
		
	}


	// average emits garbage values without this cout
	// my guess is that the buffer needs to be flushed here
	cout << endl;
	cout << endl;



	// calcuate the average of the values entered
	cout << "The average college student watches this many movies per month: " << endl;
	int average;
	average = total / studentTotal;
	cout << average << endl;

	// calculate the median of the values entered
	double medianResult;
	medianResult = median(intPointer, studentTotal);
	cout << "The Median Value: " << endl;
	cout << medianResult << endl;

	// calculate the mode of the values entered
	int modeResult;
	modeResult = mode(intPointer, studentTotal);
	cout << "The Mode Value: " << endl;
	cout << modeResult << endl;


	// return allocated memory to the sytem
	delete [] intPointer;

	return 0;
}




// Function Definitions

double median(int * arr, int n)
{
	// if the length of the array is even, then the median will need to be 
	// the average of two adjacent values in center
	if (n % 2 == 0)
	{
		double evenMedian;
		evenMedian = (*(arr + n / 2) + *(arr + n / 2 - 1)) / 2.0;
		return evenMedian;
	} 
	else
	{
		// if we wre dealing with an odd array, then we only need the center value
		// to represent the median
		double oddMedian;
		oddMedian = *(arr + n / 2);
		return 	oddMedian;
	}
}


// Mode function very complex to implement
// looked at different coding websites(such as stack oveflow) to see different implementations
int mode(int *arr, int SIZE)
{
    int modenum, oldnum, curntnum = -1, precount, count = 0;

    for(int e = 0; e < SIZE; e++)
    {
        precount = 0;
        oldnum = *(arr + e);

        // comparing against other values that come up
        for (int n = 0; n < SIZE; n++)
        {
            if(curntnum == oldnum)
            oldnum = *(arr + (++e));
        }

        // perfroms a count of the num occurences
        for(int i = 0; i < SIZE; i++)
        {
            if (oldnum == arr[i])
            {
                precount++;
            }
        }

        // store the old parsed value in the curntnum
        // to allow us to continue parsing other numbers
        curntnum = oldnum;

        // whatever number has the highest count is the mode of the range
        // and here is where it is assigned
        if (precount > count)
        {
            count = precount;
            modenum = curntnum;
        }
    }
    
    // returns the num that the func found to have the highest occurence
    return (modenum);
}




