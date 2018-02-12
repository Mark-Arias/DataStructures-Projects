
#ifndef Robot_hpp
#define Robot_hpp

#include "Arena.hpp"
#include "globals.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Arena;



class Robot
{
public:
    // Constructor
    Robot(Arena * ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool takeDamageAndLive();
    
private:
    Arena * m_arena;
    int    m_row;
    int    m_col;
    bool robotAlive;
    int hitCounter;
};




#endif /* Robot_hpp */
