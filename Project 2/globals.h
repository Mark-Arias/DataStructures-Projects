//
//  globals.h
//  Assignment_2_CS20A
//
//  Created by Mark S Arias on 10/5/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#ifndef globals_h
#define globals_h

#include <cstdlib>
extern int randReturn;
int TESTrand();

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  Then get Arena::display going.  That gives
// you more flexibility in the order you tackle the rest of the functionality.
// As you finish implementing each TODO: item, remove its TODO: comment.

// Instead of having all the libraries in the global header file
// I included them in each of the files
/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
*/


///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;             // max number of rows in the arena
const int MAXCOLS = 40;             // max number of columns in the arena
const int MAXROBOTS = 130;          // max number of robots allowed
const int MAXSHOTLEN = 5;           // max number of steps you can shoot

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;

// Will need to include all the headers for the different Classes here
// so that my program's classes know that the others exist
// interesting note:
// placing these includes before the constants keeps them from being read
//#include "Robot.hpp"
//#include "Arena.hpp"
//#include "Player.hpp"
//#include "Game.hpp"



///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

// These are global functions that are declared here, and implemented in the utilities.cpp file
// They are not part of any class direclty, and therefore are of more generic functionality
int decodeDirection(char dir);
void clearScreen();






#endif /* globals_h */
