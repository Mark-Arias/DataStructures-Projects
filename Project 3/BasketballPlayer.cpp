//
//  BasketballPlayer.cpp
//  assignment3_2
//
//  Created by Mark S Arias on 10/29/17.
//  Copyright © 2017 Mark  Arias. All rights reserved.
//

#include "BasketballPlayer.hpp"

double BasketballPlayer::salaryPerGame()
{
    double resultantsalary = 0.0;
    gamesPlayed = 82;  // redefinition of this variable here locally
    resultantsalary = salary / gamesPlayed;
    
    return resultantsalary;
}
