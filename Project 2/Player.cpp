
#include "Player.hpp"


///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Arena* ap, int r, int c)
{
    
    if (ap == nullptr)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
        // exits the program
    }
    
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
        << "," << c << ")!" << endl;
        exit(1);
    }
    
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

//------------------------------------------------------------------------

int Player::row() const
{
    return m_row;
}

//------------------------------------------------------------------------

int Player::col() const
{
    return m_col;
}

//------------------------------------------------------------------------

int Player::age() const
{
    return m_age;
}

//------------------------------------------------------------------------
// This method now works in a primitive sense
// however I should make this more intelligent if I can
// needs to better access the shooting and moving functions
// and still need to fix that edge shooting glitch
// but that is a problem from that function and not this one
string Player::takeComputerChosenTurn()
{
 
    int machineLearning = rand() % 4; // should contain values between 1 and 3
    switch (machineLearning)
    {
        case 0:
            stand();        // computer keeps the player still
            m_arena->display("Stood.");
            break;
        case 1:
            move(machineLearning);
            m_arena->display("moved");
            break;
        case 2:
            shoot(machineLearning);
            m_arena->display("Shot");
            break;
        default:
            stand();
            m_arena->display("Stood.");
            break;
            
    }
    return "machine learning happened.";
}


//------------------------------------------------------------------------

void Player::stand()
{
    m_age++;
}

//------------------------------------------------------------------------

void Player::move(int dir)
{
            m_age++;
    
        switch (dir)
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
// Shooting in all directions works
// however I know that I have a program bug when the player tries to shoot at a target that is at range 5
// while this is still a valid range, program crashes if robot is beyond range of the arena
// need to program into this a catch that prevents shooting from going beyond arena's edge(cut down range if player is close to edge)
// bug is in shooting in all directions
// throws error in accessing a m_row or m_col 
bool Player::shoot(int dir)
{
    m_age++;
   
    
    if (rand() % 3 == 0)  // miss with 1/3 probability
    {
        return false;
    }
    else
    {
        if(dir == UP)
        {
            for(int i = 1; i <= 5; i++)
            {
                if((m_arena -> nRobotsAt(m_row - i, m_col ) > 0))
                   {
                       m_arena -> damageRobotAt(m_row - i, m_col);  // think the issue is with accessing the m_row and m_col here
                       return true;
                       break;
                   }
            }
        }
        else if(dir == DOWN)
        {
            for(int i = 1; i <= 5; i++)
            {
                if((m_arena -> nRobotsAt(m_row + i, m_col ) > 0))
                {
                    m_arena -> damageRobotAt(m_row + i, m_col);
                    return true;
                    break;
                }
            }
        }
        if(dir == LEFT)
        {
            for(int i = 1; i <= 5; i++)
            {
                if((m_arena -> nRobotsAt(m_row, m_col - i ) > 0))
                {
                    m_arena -> damageRobotAt(m_row, m_col - i);
                    return true;
                    break;
                }
            }
        }
        if(dir == RIGHT)
        {
            for(int i = 1; i <= 5; i++)
            {
                if((m_arena -> nRobotsAt(m_row, m_col + i ) > 0))
                {
                    m_arena -> damageRobotAt(m_row, m_col + i);
                    return true;
                    break;
                }
            }
        }
        
    }
    return false;
    
}

//------------------------------------------------------------------------

bool Player::isDead() const
{
    return m_dead;
}

//------------------------------------------------------------------------

void Player::setDead()
{
    m_dead = true;
}

//------------------------------------------------------------------------

