// Mark Arias
// CS 20A Data Structures
//
//
//-------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//-------------------------------------------------------
// Function Prototypes
vector<string> printFile(ifstream & infile);
void balanceChecker(vector<string> & infile);

//-------------------------------------------------------

int main()
{

    string userInput;
    cout << "Must specify full path directory for your machine!" << endl;
    cout << "Please enter a filename for c++ code: ";
    cin >> userInput;
    cout << endl;
    
    //-------------------------------------------------------
    // get file name codeblock
    ifstream infile(userInput);
    // this if gets thrown if the program is not able to find the source file that you passed in as an arg
    if(!infile)
    {
        cerr << "Error: Cannot open this file! " << endl;
        exit(0);
    }
    
    //-------------------------------------------------------
    // Call a function to print the file with line numbers to the terminal
    // a side effect of this design I built is that the formatted file with line numbers is returned back to the main
    // and stored in a string vector
    vector<string> formattedInput = printFile(infile);
    
    
    //-------------------------------------------------------
    // Call a balance checking function to see if the input file has balanced operators
    // Here balance is passed in a refernce to the string vector that i built prior
    // as opposed to passing in the raw infile again since this would require file processing all over again, and losing the line numbers
    
    balanceChecker(formattedInput);
    
    //-------------------------------------------------------
    // housekeeping
    infile.close();
    return 0;
}


//-------------------------------------------------------
vector<string> printFile(ifstream & infile)
{
    // This code block appends line numbers to the input file string
    int i = 1;
    string line;
    vector<string> myLines;
    vector<string>::const_iterator stringIterator;
    // parses through the input file line by line
    while(getline(infile, line))
    {
        myLines.push_back(to_string(i) + " " + line);
        i++;
    }
    
    
    
    // print out contents of myLines vector, line by line to terminal
    
    for(stringIterator = myLines.begin(); stringIterator != myLines.end(); stringIterator++)
    {
        cout << (*stringIterator) << endl;
    }
    
    //return the vector back to the main program, modifed with line numbers and newline chars
    return myLines;
}

//-------------------------------------------------------
// Note to self. This program crashes if I do not pass the infile object by reference
// for both of these functions I believe

void balanceChecker(vector<string> & infile)
{
    stack<char> operatorStack;
    vector<char> charVector;
    vector<string> localStringVector;
    
    vector<char>::const_iterator iterator;
    vector<string>::const_iterator stringIterator;
    
    //-------------------------------------------------------
    // These nested for loops are designed to store the contents of infile inside of the char Vector
    // special consideration was required becuase the outer for loop is required to run through each line of the infile
    // and the inside for loop is required to run through each of the lines and element by element pass in and store each of the
    // referenced chars so that the resultant char vector has every char stored inside of it
    for(stringIterator = infile.begin(); stringIterator != infile.end(); stringIterator++ )
    {
        string tempLine = *stringIterator + '\n';   // appending the newline so that it exists within the vector
        for(iterator = tempLine.begin(); iterator != tempLine.end(); iterator++ )
        {
            charVector.push_back(*iterator);
        }
    }
    
    
    //-------------------------------------------------------
    // parse through charVector and perform stack operations that verify balance
    // Function Notes:
    // I kept getting a lot of access error bugs the first time I tried utilizing and writing operations with the stack
    // becuase I did not first check if the stack was empty before trying to call and use the .top() method
    // Lessons learned!
    
    //*** Important Note: Observation
    // The spacing generated by the way the vector parses characters between line is consistent enough to let
    // me measure the spacing generated to create and generate line numbers for the error output
    // Or, the approach i took is to utilize the new line char as the marker for where the line number will be and to use the
    // iterator to print out the numbers ahead of the newline
    cout << endl;
    for(iterator = charVector.begin(); iterator != charVector.end(); iterator++)
    {
        
        //-------------------------------------------------------
        // this section of code deals with the block comments
        // Treating the block comments in this manner seperate from the stack becuase block comments do not have
        // to have valid syntax within their scope, so iterator moves past the end of the closing block
        // prints out that it found a pair, and then resumes balance checking via the stack operations
        if(*iterator == '/' && *(iterator + 1) == '*')
        {
            do
            {
                iterator++;
            }
            while (*iterator != '*' && *(iterator + 1) != '/');
            cout << "pair matching /* and */" << endl;
        }
        //-------------------------------------------------------
        // codeblock will iterate through the rest of line until it reaches a newline char
        // effectively skipping and commenting out all data after
        char forwardSlash = 47;
        if(*iterator == forwardSlash && *(iterator + 1) == forwardSlash)
        {
            while (*iterator != '\n')
            {
                ++iterator;
            }
        }
        
        //-------------------------------------------------------
        // checks for matching double quotes
        // The potential bug I see with this code is that if the user messes up and does not close the quote
        // this program will display incorrect stuff as it eats through a lot of the other characters it should
        // be leaving alone!
        
        if(*iterator == '\"')
        {
            do
            {
                iterator++;
                if(*iterator == '\n')
                {
                    iterator--;
                    char lineNumber1;
                    char lineNumber2;
                    
                    while(*iterator != '\n')
                    {
                        iterator--;
                    }
                    lineNumber1 = *(iterator +1);
                    lineNumber2 = *(iterator +2);
                    
                    //--------
                    cout << "unbalaced symbol on line " << lineNumber1 << lineNumber2 << endl;
                    exit(0);
                    //--------
                }
            }
            while(*iterator != '\"');
            cout << "pair matching \" and \" " << endl;
        }
        
        //-------------------------------------------------------
        // I am using a check for a newline as catch against unbalanced single and double quotes
        // The reasoning is that I have decided to limit the length of single and double quotes to the length of a single line
        // since a coder should break their strings up and concatenate them with plus's across multiple lines
        // checks for matching single quotes
        if(*iterator == '\'')
        {
            do
            {
                iterator++;
                //--------
                if(*iterator == '\n')
                {
                    iterator--;
                    char lineNumber1;
                    char lineNumber2;
                    
                    while(*iterator != '\n')
                    {
                        iterator--;
                    }
                    lineNumber1 = *(iterator +1);
                    lineNumber2 = *(iterator +2);
                    
                    cout << "unbalaced quote ' on line " << lineNumber1 << lineNumber2 << endl;
                    exit(0);
                }
                //--------
            }
            while(*iterator != '\'');
            cout << "pair matching \' and \' " << endl;
        }
    
        //-------------------------------------------------------
        // this section checks the ordinary brace characters
        if(*iterator == '(' || *iterator == '{' || *iterator == '[')
        {
            operatorStack.push(*iterator);
        }
        else if(*iterator == ')' || *iterator == '}' || *iterator == ']')
        {
            //-------------------------------------------------------
            // perform some error catching first, to make sure I first and foremost can safely asses the top method
            // and to make sure syntax balance is correct
            // and then to see if unbalanced symbols exist on the stack
            if(operatorStack.empty() == true)
            {
                iterator--;
                char lineNumber1;
                char lineNumber2;
                
                while(*iterator != '\n')
                {
                    iterator--;
                }
                lineNumber1 = *(iterator +1);
                lineNumber2 = *(iterator +2);
                cout << "unbalaced symbol on line " << lineNumber1 << lineNumber2 << endl;
                //cout << "stack is empty!" << endl;
                exit(0);
            }
            
            if(*iterator == ')' && operatorStack.top() != '(')
            {
                iterator--;
                char lineNumber1;
                char lineNumber2;
                
                while(*iterator != '\n')
                {
                    iterator--;
                }
                lineNumber1 = *(iterator +1);
                lineNumber2 = *(iterator +2);
                cout << "unbalaced ) symbol on line " << lineNumber1 << lineNumber2 << endl;
                exit(0);
            }
            
            if(*iterator == '}' && operatorStack.top() != '{')
            {
                iterator--;
                char lineNumber1;
                char lineNumber2;
                
                while(*iterator != '\n')
                {
                    iterator--;
                }
                lineNumber1 = *(iterator +1);
                lineNumber2 = *(iterator +2);
                cout << "unbalaced } symbol on line " << lineNumber1 << lineNumber2 << endl;
                exit(0);
            }
            
            if(*iterator == ']' && operatorStack.top() != '[')
            {
                iterator--;
                char lineNumber1;
                char lineNumber2;
                
                while(*iterator != '\n')
                {
                    iterator--;
                }
                lineNumber1 = *(iterator +1);
                lineNumber2 = *(iterator +2);
                cout << "unbalaced ] symbol on line " << lineNumber1 << lineNumber2 << endl;
                exit(0);
            }
            
           
            //-------------------------------------------------------
            // Here, perform the pop's on the stack and print out a message that indicates the corresponding pair
            if(*iterator == ')' && operatorStack.top() == '(')
            {
                cout << "pair matching ( and )" << endl;
                operatorStack.pop();
            }
            if(*iterator == '}' && operatorStack.top() == '{')
            {
                cout << "pair matching { and }" << endl;
                operatorStack.pop();
            }
            if(*iterator == ']' && operatorStack.top() == '[')
            {
                cout << "pair matching [ and ]" << endl;
                operatorStack.pop();
            }
            //-------------------------------------------------------
        }
    }
    
    //-------------------------------------------------------
    // this code block confirms the stack operations were performed sucesfully
    // The stack is empty at the end and parsed all the way through my test file
    cout << endl;
    if(operatorStack.empty() == true)
    {
        cout << "Balance is ok" << endl;
    }
    else
    {
        if(operatorStack.top() == '{')
        {
            cout << "unbalanced { operator in program" << endl;
            exit(0);
        }
        else if(operatorStack.top() == '(')
        {
            cout << "unbalanced ( operator in program" << endl;
            exit(0);
        }
        else if(operatorStack.top() == '[')
        {
            cout << "unbalanced [ operator in program" << endl;
            exit(0);
        }
        else
        {
            cout << "The operators are not balanced" << endl;
            cout << "Operator on the Stack: " << operatorStack.top() << endl;
        }
    }
    cout << endl;
    
    //-------------------------------------------------------
    // This loop prints out the contents of charVector char by char
    /*
    for(iterator = charVector.begin(); iterator != charVector.end(); iterator++)
    {
        cout << (*iterator) << endl;
    }
    */
    //-------------------------------------------------------
}



//-------------------------------------------------------
// Work Area: Caution! Hard hats required!



















