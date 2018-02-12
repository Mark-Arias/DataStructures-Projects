

#ifndef Athlete_hpp
#define Athlete_hpp

#include <iostream>
#include <string>
using namespace std;

class Athlete
{
public:
    //constructors
    Athlete(string n, double s);
    Athlete();
    
    // Accessor Methods
    string getName();
    double getSalary();
    
    // Mutator Methods
    void setName(string n);
    void setSalary(double s);
    
    // Generic Method
    // redefine this as a virtual function
    // change the formula internally in each redefinition of the function
    virtual double salaryPerGame();
    // This function returns salary divided by the games a player played in during their
    // sports respective season
    // virtual here means that this is a function that will be redefined in the subclass's that inhherit
    // from this superclass
    
protected:
    string name;
    double salary;
    int gamesPlayed;
};



#endif /* Athlete_hpp */
