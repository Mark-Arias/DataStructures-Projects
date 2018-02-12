

#ifndef Game_hpp
#define Game_hpp


#include "globals.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Arena.hpp"




class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena * m_arena;
};


#endif /* Game_hpp */
