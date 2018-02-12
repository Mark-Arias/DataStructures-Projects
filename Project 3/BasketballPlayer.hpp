//
//  BasketballPlayer.hpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#ifndef BasketballPlayer_hpp
#define BasketballPlayer_hpp

#include <stdio.h>

#include "Athlete.hpp"

class BasketballPlayer : public Athlete
{
public:
    virtual double salaryPerGame();
    
private:
    
};


#endif /* BasketballPlayer_hpp */
