

#ifndef Player_hpp
#define Player_hpp


#include "globals.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


#include "Arena.hpp"
class Arena;






class Player
{
public:
  
    Player(Arena * ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    string takeComputerChosenTurn();
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();
    
private:
    Arena * m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

#endif /* Player_hpp */
