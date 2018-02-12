// Mark Arias
// Project 6
// CS20A
// Program Purpose:
// this program can perform an analysis of an input file, and return to the user the total word count
// and frequency of words encountered


#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "wordtree.hpp"
#include <vector>
#include <sstream>

using namespace std;


// method prototype
vector<string> readInputFile(ifstream & infile);


int main()
{
    
    ifstream fin;
    ofstream fout;
    string filename;
    cout << "Enter name of file with text to analyze: ";
    cin >> filename;
    
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Error opening file.\n";
        exit(1);
    }
    cout << "\nAnalyzing " << filename << ".\n";
    
    WordTree myTree;
    
    // insert code here
    // What it think this means is that here is where you implement the fancy and shiny new methods just written
    // to enact the program goals
    vector<string> words = readInputFile(fin);
    vector<string>::const_iterator stringIterator;
    
    // using iterator code to run the tree insertion
    for(stringIterator = words.begin(); stringIterator != words.end(); stringIterator++)
    {
        myTree.add(*stringIterator);
    }
    
    int wordcount = myTree.totalWords();
    
    
    // my code changes end here
    
    fin.close();
    fout.open("results.txt");
    cout << "\nWord counts:\n\n";
    cout << myTree;
    fout << myTree;
    cout << "\nTotal number of words in text: " << wordcount << ".\n";
    fout << "\nTotal number of words in text: " << wordcount << ".\n";
    cout << "Number of distinct words appearing in text: "
    << myTree.distinctWords() << ".\n";
    fout << "Number of distinct words appearing in text: "
    << myTree.distinctWords() << ".\n";
    fout.close();
    
    return 0;
}














// this function takes as input an input filestream
// and returns back to the main program a vector full of words
// Function Bugs*****
// Function leaves commas, -, and symbols like that appended to the words. This is not desirable
// but I handle this in another method
vector<string> readInputFile(ifstream & infile)
{
    
    vector<char> charVector;
    vector<char>::const_iterator charIterator;
    
    char c;
    // parses through the input char by char
    while(infile.get(c))
    {
        char lowerChar;
        lowerChar = tolower(c);             // convert all chars as to lowercase versions
        charVector.push_back(lowerChar);    // to simplify the counting of duplicate words
    }
    
    vector<string> stringWords;             // store the final, formated string words here
    string tempWord = "";
    for(charIterator = charVector.begin(); charIterator != charVector.end(); charIterator++)
    {
        // code to run if dealing with no alphabetical chars( indicates where words start and end)
        if(*charIterator == ',' || *charIterator == '-' || *charIterator == '.' || *charIterator == ' ' )
        {
            stringWords.push_back(tempWord);
            // reset the conditions to store a new word
            tempWord = "";
        }
        
        // this code appends the words char by char into complete words, converting them into strings
        if(*charIterator != ' ')
        {
            stringstream ss;
            string str;
            ss << *charIterator;
            ss >> str;
            tempWord += str;
        }
    }
    
    // perform data cleaning.( strip the vector of punctuation symbols)
    // I use the outer loop to traverse the length of punctuation string, and use the char at those locations to swap into the inner iterator
    // loop as the arg for what to search and destroy in the dataset
    string punctuation = ":-;,.[]()?!\"";
    for(int i = 0; i < punctuation.length(); i++)
    {
        char punctSymbol = punctuation.at(i);
        vector<string>::iterator stringIterator;
        for(stringIterator = stringWords.begin(); stringIterator != stringWords.end(); stringIterator++)
        {
            string temp = *stringIterator;
            string result;
            istringstream is(temp);
            while(getline(is,result, punctSymbol ))
            {
                *stringIterator = result;
            }
        }
        
    }
    
   
    
    
    //return the vector back to the main program
    return stringWords;
}
