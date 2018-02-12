/* Mark Arias
 * CS20A Project 5
 * Project Description:
 * This program takes as input a .txt file containing words that it parses through and compares with the permutations
 * generated looking for matching valid dictionary words.
 */
//------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>
#include <assert.h>

using namespace std;
const int MAXRESULTS   = 20;
const int MAXDICTWORDS = 30000;

//------------------------------------------------------------
// Primary Program Function Prototypes
// These are the three primary work horse functions required per project specifications

int readDictionary(istream &dictfile, string dict[]);
// Places each string in dictfile into the array dict. Returns the number of words read into dict.
// This number should not be larger than MAXDICTWORDS since that is the size of the array.

int recursivePermute(string word, const string dict[], int size, string results[]);
// Places all the permutations of word, which are found in dict into results. Returns the number of matched words found.
// This number should not be larger than MAXRESULTS since that is the size of the array.
// The size is the number of words inside the dict array.

void recurPrint(const string results[], int size);
// Prints size number of strings from results. The results can be printed in any order.

//------------------------------------------------------------
//Auxiliary function Prototypes
// External helper functions called within the three primary functions used in assisting their sucesfull operation
void recursive_readDictionary(istream &dictfile, string dict[], int& words_count);
void findPermutations(string prefix, string rest, const string dict[], const int& size, string results[], int& count);
void permutation_loop(int i, int max, string prefix, string rest, const string dict[], const int& size, string results[], int& count);
int checkDictionary(const string& target, const string dict[], int size, string results[], int& count);
bool isDuplicated(const string& target, const string results[], int start, int max);

//------------------------------------------------------------

int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    
    dictfile.open("/Users/marksarias/Desktop/words.txt");
    if (!dictfile)
    {
        cout << "File not found!" << endl;
        return (1);
    }
    
    nwords = readDictionary(dictfile, dict);
    
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    
    int numMatches = recursivePermute(word, dict, nwords, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        recurPrint(results, numMatches);
    
    dictfile.close();
    return 0;
}

//------------------------------------------------------------
// Primary Function Definitions

int readDictionary(istream &dictfile, string dict[])
{
    int count = 0;
    
    recursive_readDictionary(dictfile, dict, count);
    
    return count;
}

//------------------------------------------------------------

int recursivePermute(string word, const string dict[], int size, string results[])
{
    int count = 0;
    
    findPermutations("", word, dict, size, results, count);
    
    return count;
}

//------------------------------------------------------------

void recurPrint(const string results[], int size)
{
    if(size == 0)
        return;
    else
    {
        cout << "Matching word " << *results << endl;
        recurPrint(results + 1, size - 1);
    }
}

//------------------------------------------------------------








//------------------------------------------------------------
// Auxillary Function Definitions

// this function reads through the external txt file via recursion without the use of loops!
void recursive_readDictionary(istream &dictfile, string dict[], int & count)
{
    string line;
    
    if(dictfile >> line)        // if read into local var line is sucessfull from input file
    {
        count++;                // up count of words read in
        
        if (count > MAXDICTWORDS)   // catch if statement to check if our count is greater than limit for dictwords
        {
            count--;
            return;
        }
        
        *dict = line;           // store temp string word in line into the dict array
        
        recursive_readDictionary(dictfile, dict + 1, count);    // call function again, pass in dictfile again, move pointer of dict up one
    }                                                           // poisiton
}

//------------------------------------------------------------

void findPermutations(string prefix, string rest, const string dict[], const int& size, string results[], int& count)
{
    if (rest.length() == 0)
    {
        // increase count while also calling the checkDictionary func to see if the word is contained in the list
        count += checkDictionary(prefix, dict, size, results, count);
        
        // do not allow the program to return more words than the size of max results
        if (count > MAXRESULTS)
        {
            count--;
            return;
        }
    }
    else
    {
        permutation_loop(0, static_cast<int>(rest.length()), prefix, rest, dict, size, results, count);
    }
}

//------------------------------------------------------------
// permutation loop is a helper function to assist in the movement through the permutations without a while or for loop :(
void permutation_loop(int i, int max, string prefix, string rest, const string dict[], const int& size, string results[], int& count)
{
    if(i >= max)
        return;
    
    findPermutations(prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1), dict, size, results, count);
    
    permutation_loop(i + 1, max, prefix, rest, dict, size, results, count);
}

//------------------------------------------------------------
// check dictionary for the target word passed in as an arg and if so store the word in results
// make use of the isduplicated function to check if target is a duplicate and prevent them from being utilized
int checkDictionary(const string& target, const string dict[], int size, string results[], int& count)
{
    if(size == 0)
        return 0;
    
    
    if(target == *dict)
    {
        if(isDuplicated(target, results, 0, count))
            return 0;
        
        else
        {
            results[count] = target;
            return 1;
        }
    }
    else
        return checkDictionary(target, dict + 1, size - 1, results, count);
}

//------------------------------------------------------------
// check if the target word is duplicated in results
bool isDuplicated(const string& target, const string results[], int start, int max)
{
    if(start >= max)
        return false;
    
    if(target == *results)
        return true;
    else
        return isDuplicated(target, results + 1, start + 1, max);
}

//------------------------------------------------------------





