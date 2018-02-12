
#include "Robot.hpp"


///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
        << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
}

//------------------------------------------------------------------------

int Robot::row() const
{
    return m_row;
}

//------------------------------------------------------------------------

int Robot::col() const
{
    return m_col;
}

//------------------------------------------------------------------------

void Robot::move()
{
    switch (rand() % 4)
    {
        case UP:
            if ( (row() - 1) > 0)
                m_row--;
            break;
        case DOWN:
            if ( row() <= m_arena-> rows() - 1)
                m_row ++;
            break;
        case LEFT:
            if  ((col() - 1) > 0)
                m_col--;
            break;
        case RIGHT:
            if ( col() <= m_arena-> cols() - 1)
                m_col++;
            break;
    }
}

//------------------------------------------------------------------------
// Need to do some work here
// Implementing a correct way to delete robots that have been killed
bool Robot::takeDamageAndLive()
{
    hitCounter++;
    
    if(hitCounter == 1)
    {
        robotAlive = true;
    }
    else if(hitCounter >= 2)
    {
        robotAlive = false;
    }
    
    return robotAlive;
}

//------------------------------------------------------------------------




