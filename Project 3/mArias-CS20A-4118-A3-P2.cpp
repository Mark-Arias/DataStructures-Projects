// Mark Arias
// CS 20A, Section # 4118
// Assignment # 3 Problem 2
// Program Purpose:
// Design an athlete superclass and then different player
// subclasses that inherit the traits they all share in common
// In main, perform the salary per game analysis
#include <iostream>
#include <string>
using namespace std;

#include "Athlete.hpp"
#include "BaseballPlayer.hpp"
#include "BasketballPlayer.hpp"
#include "FootballPlayer.hpp"
#include "SoccerPlayer.hpp"

// Polymorphic function prototype
void printSalary(Athlete & a);

int main()
{
    BaseballPlayer Babe;
    Babe.setName("Babe Ruth");
    Babe.setSalary(1000000.00);
    double result1 = Babe.salaryPerGame();
    cout << "Salary Per Game # 1: " << result1 << endl;
    
    BasketballPlayer Kobe;
    Kobe.setName("Kobe Bryant");
    Kobe.setSalary(30000000.00);
    double result2 = Kobe.salaryPerGame();
    cout << "Salary Per Game # 2: " << result2 << endl;
    
    FootballPlayer Peyton;
    Peyton.setName("Peyton Manning");
    Peyton.setSalary(4000000.00);
    double result3 = Peyton.salaryPerGame();
    cout << "Salary Per Game # 3: " << result3 << endl;
    
    SoccerPlayer Lionel;
    Lionel.setName("Lionel Messi");
    Lionel.setSalary(9000000.00);
    double result4 = Lionel.salaryPerGame();
    cout << "Salary Per Game # 4: " << result4 << endl;
    
    cout << endl;
    cout << "This section demonstrates Polymorhpism at work:" << endl;
    printSalary(Babe);
    printSalary(Kobe);
    printSalary(Peyton);
    printSalary(Lionel);
    
    
    return 0;
}

// Extra credit
// Write a function printSalary that is not a class function, but that will be a polymorphic function
// that takes in a base class argument
// Polymorphic Function Implementation
void printSalary(Athlete & a)
{
    cout << a.getName() << " Statistics" << endl;
    double salary = a.getSalary();
    cout << "Salary: $" << salary << endl;
}

