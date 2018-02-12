// class implementation file
// define member functions here
#include "wordtree.hpp"


void WordTree::add(const string & value)
{
    insert(value);
}



int WordTree::totalWords() const
{
    int count = totalPreOrderCount(m_root);
    return count;
}



int WordTree::distinctWords() const
{
    int count = preOrderCount(m_root);
    return count;
}



// this method definition needs to appear before it is called in the operator<< method
//  this is in order traversal
void printAlphabeticalOrder(WordNode * current, ostream & out)
{
    if(current == NULL)
    {
        return; // if empty, return
    }
    printAlphabeticalOrder(current -> left, out);       // process nodes in left subtree
    out << current -> value << ' '  << current -> wordcount << ' ' << endl;           // process the current node
    printAlphabeticalOrder(current -> right, out);      // process nodes in right subtree
}



ostream& operator<<(ostream & out, const WordTree & rhs)
{
    out << ' ';
    printAlphabeticalOrder(rhs.m_root, out);
    
    return out;
    
    
}



//-------------------------------------------------------------------------------
// code in section below would have been used for making the copy constructor and assignment operator work
// but i was not able to get the function to work in the limited time available
WordNode * WordTree::copyTree(WordNode * root)
{
    WordNode * copyNode = NULL;
    if (root)
    {
        copyNode->value = root->value;
        copyNode->left = copyTree(root->left);
        copyNode->right = copyTree(root->right);
    }
    return copyNode;
}

// Definition of overloaded assignment operator
// does not work.
/*
const WordTree & WordTree::operator=(const WordTree & rhs)
{
    
    WordNode * current = rhs.m_root;
    WordNode * final = copyTree(current);
    
    static WordTree duplicatedTree; // = WordTree();
    
    duplicatedTree.m_root = final;
    
    
    
    return duplicatedTree;
}
*/





// copy constructor
// Does not work
/*
WordTree::WordTree(const WordTree & rhs)
{
    
}
*/

//-------------------------------------------------------------------------------



















// Defintion of helper Methods



// in placing a new value in our binary Search tree, we must place the new node so that the resulting tree
// is still a valid bst, this method below acheives just that
void WordTree::insert(const string & value)
{
    if(m_root == NULL)
    {
        m_root = new WordNode(value);
        return;
    }
    WordNode * current = m_root;
    for(;;)
    {
        // this block executes if the input string matches a string already in the tree
        // prevents multiple inclusions of the same word
        // should do the incrementation code here
        // might make sense to give each node its own counter of occurences
        // and then increment it individually
        if(value == current -> value)
        {
            current->wordcount++;
            return;
        }
        
        if(value < current -> value)
        {
            if(current -> left != NULL)
            {
                current = current -> left;
            }
            else
            {
                current -> left = new WordNode(value);
                return;
            }
        }
        else if(value > current -> value)
        {
            if(current -> right != NULL)
            {
                current = current -> right;
            }
            else
            {
                current -> right = new WordNode(value);
                return;
            }
        }
    }
}






// free and destroy the nodes in a tree
// this is a post order traversal
// implemented via recursion
// use this code to build the bst class destructor.
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










// I am going to use this code to implement the counting feautures

int WordTree::preOrderCount(WordNode * current) const
{

    int count = 0;
    
    if(current) //if the tree is empty, then exit and return
    {
        count++;
        count = count + preOrderCount(current -> left);
        count = count + preOrderCount(current -> right);
    }
    
    return count;
}


// this method returns count of total words, including duplicates
// I need to parse through each node, and add into a running total the counts stored local to each
// return running local to caller
int WordTree::totalPreOrderCount(WordNode * current) const
{
    if (current == NULL) return 0;
    return current ->wordcount +  totalPreOrderCount(current->left) + totalPreOrderCount(current->right);
    
}


