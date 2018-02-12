//
//  SoccerPlayer.hpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#ifndef SoccerPlayer_hpp
#define SoccerPlayer_hpp

#include <stdio.h>

#include "Athlete.hpp"

class SoccerPlayer : public Athlete
{
public:
    virtual double salaryPerGame();
    
private:
    
};


#endif /* SoccerPlayer_hpp */
