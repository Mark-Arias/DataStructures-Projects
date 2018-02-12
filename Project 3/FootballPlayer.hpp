//
//  FootballPlayer.hpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#ifndef FootballPlayer_hpp
#define FootballPlayer_hpp

#include <stdio.h>

#include "Athlete.hpp"

class FootballPlayer : public Athlete
{
public:
    virtual double salaryPerGame();
    
private:
    
};


#endif /* FootballPlayer_hpp */
