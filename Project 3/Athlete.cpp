
#include "Athlete.hpp"

//constructor
Athlete::Athlete(string n, double s)
{
    name = n;
    salary = s;
    gamesPlayed = 0;
}

Athlete::Athlete()
{
    name = "";
    salary = 0.0;
    gamesPlayed = 0;
}

// Accessor Methods
string Athlete::getName()
{
    return name;
}
double Athlete::getSalary()
{
    return salary;
}

// Mutator Methods
void Athlete::setName(string n)
{
    name = n;
}
void Athlete::setSalary(double s)
{
    salary = s;
}

// Generic Method
double Athlete::salaryPerGame()
{
    double resultantsalary = 0.0;
    resultantsalary = salary / gamesPlayed;
    
    return resultantsalary;
}

