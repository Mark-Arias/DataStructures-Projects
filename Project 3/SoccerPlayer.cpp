//
//  SoccerPlayer.cpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#include "SoccerPlayer.hpp"

double SoccerPlayer::salaryPerGame()
{
    double resultantsalary = 0.0;
    gamesPlayed = 38;  // redefinition of this variable here locally
    resultantsalary = salary / gamesPlayed;
    
    return resultantsalary;
}
