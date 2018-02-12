// wordtree.hpp
// header file for the class
// contains general class and method prototypes

#ifndef wordtree_hpp
#define wordtree_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

using namespace std;


// structure that defines a Binary tree node
struct WordNode
{
    // added constructor for this node, to make new node creation easier
    // implemented via initializer list
    WordNode(const string & myVal) :
        value(myVal),
        wordcount(1),   // very cool. Got the count right. All counts should begin on 1, not zero!
        left(NULL),
        right(NULL)
        {}
    
    
    string value;
    int wordcount;          // each node stores the count of total number of same word that appears in original file
    
    WordNode * left;
    WordNode * right;
};



// class definition of a binary Search Tree
class WordTree
{
public:
    
    // class constructor
    // implement via initializer list
    WordTree() :
        m_root(NULL)
        {}
    
    // class destructor
    ~WordTree()
    {
        freeTreeNodes(m_root);
        cout << "Done"<<endl;
    }
    
    
    // copy constructor
    WordTree(const WordTree & rhs);
    
    // assignment operator
    const WordTree  & operator=(const WordTree & rhs);
    
    
    
    // adds the given word to the tree if it is not already in the tree, or increments the appropriate
    // counter if it is already there
    // implement in terms of a recursive private member function defined in .cpp file
    void add(const string & value);
    
    
    // returns the number of words / nodes currently stored in the tree
    int distinctWords() const;
    
    
    // returns the total number of words(including duplicates
    int totalWords() const;
    
    
    //prints words in the tree in alphabetical order, and next to each word, prints the number of times each word occurs in the text
    // implement in terms of a recursive private member function defined in .cpp file
    friend ostream& operator<<(ostream & out, const WordTree & rhs);
    
    
    
private:
    WordNode * m_root;
    
    // private class methods
    void printAlphabeticalOrder(WordNode * current, ostream & out);
    void insert(const string & value);
    // bug note:
    // *****
    // The destructor wasnt working when I tried calling this code int he implementation file
    // I kept getting linker errors
    // whereas here and now, it works fine, and the program does not crash
    void freeTreeNodes(WordNode * current)
    {
        if(current == NULL)
        {
            return; // if empty, return
        }
        freeTreeNodes(current -> left);        // delete the nodes in the left subtree
        freeTreeNodes(current -> right);       // delete the nodes in the right subtree
        
        delete current;                         // free the current node
    }
    int preOrderCount(WordNode * current) const;
    int totalPreOrderCount(WordNode * current) const;
    
    WordNode * copyTree(WordNode * root);
    
};





#endif /* wordtree_hpp */
