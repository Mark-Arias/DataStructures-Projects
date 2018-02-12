//
//  BaseballPlayer.hpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#ifndef BaseballPlayer_hpp
#define BaseballPlayer_hpp

#include <stdio.h>
#include "Athlete.hpp"

class BaseballPlayer : public Athlete
{
public:
    virtual double salaryPerGame();
    
private:
    // Each different sports player will have differing private data, such as equipment used, food consumed
    // training, most popular countries, etc, but I left this blank becuase I was able to implement the
    // project specs via inheritance of the Athlete class
    // I redefined gamesPlayed internally in each seperate instance of the virtual function
};



#endif /* BaseballPlayer_hpp */
