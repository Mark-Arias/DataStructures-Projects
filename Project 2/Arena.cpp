
#include "Arena.hpp"


///////////////////////////////////////////////////////////////////////////
//  Arena implementations
///////////////////////////////////////////////////////////////////////////

// Constructor
//------------------------------------------------------------------------

Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** Arena created with invalid size " << nRows << " by "
        << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nRobots = 0;
}

// Destructor
//------------------------------------------------------------------------

Arena::~Arena()
{
    delete [] m_player;
    for(int i = 0; i < m_nRobots; i++)
    {
        if(m_robots[i] != nullptr)
        {
            delete m_robots[i];
        }
    }
}

//------------------------------------------------------------------------

int Arena::rows() const
{
    return m_rows;
}

//------------------------------------------------------------------------

int Arena::cols() const
{
    return m_cols;
}

//------------------------------------------------------------------------

Player * Arena::player() const
{
    return m_player;
}

//------------------------------------------------------------------------

int Arena::robotCount() const
{
    return m_nRobots;
}

//------------------------------------------------------------------------

int Arena::nRobotsAt(int r, int c) const
{
    int robotCount = 0;
    for(int i = 0; i < m_nRobots; i++)
    {
        if( r == m_robots[i] -> row() && c == m_robots[i] -> col())
        {
            robotCount++;
        }
    }

    return robotCount;
}

//------------------------------------------------------------------------

void Arena::display(string msg) const
{
    // Position (row,col) in the arena coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
    // Fill the grid with dots
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
        {
            grid[r][c] = '.';
            if(nRobotsAt(r, c) == 1)
            {
                grid[r][c] = 'R';
            }
            else if(nRobotsAt(r, c) == 2)
            {
                grid[r][c] = '2';
                
            }
            else if(nRobotsAt(r, c) == 3)
            {
                grid[r][c] = '3';
                
            }
            else if(nRobotsAt(r, c) == 4)
            {
                grid[r][c] = '4';
                
            }
            else if(nRobotsAt(r, c) == 5)
            {
                grid[r][c] = '5';
                
            }
            else if(nRobotsAt(r, c) == 6)
            {
                grid[r][c] = '6';
                
            }
            else if(nRobotsAt(r, c) == 7)
            {
                grid[r][c] = '7';
                
            }
            else if(nRobotsAt(r, c) == 8)
            {
                grid[r][c] = '8';
                
            }
            else if(nRobotsAt(r, c) == 9)
            {
                grid[r][c] = '9';
                
            }
            else if(nRobotsAt(r, c) > 9)
            {
                grid[r][c] = '9';
                
            }
        }
    }
    
    
    // Indicate player's position
    if (m_player != nullptr)
    {
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }
    
    // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;
    
    
    // Write message, robot, and player info
    cout << endl;
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << robotCount() << " robots remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isDead())
            cout << "The player is dead." << endl;
    }
}

//------------------------------------------------------------------------

bool Arena::addRobot(int r, int c)
{
    if(m_nRobots == MAXROBOTS)
    {
        return false;
    }
    else
    {
        m_robots[m_nRobots] = new Robot(this, r, c);
        m_nRobots++;    // keep track of number of robots that exist
        
        return true;
    }
}

//------------------------------------------------------------------------

bool Arena::addPlayer(int r, int c)
{
    // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;
   
    m_player = new Player(this, r, c);
    return true;
}

//------------------------------------------------------------------------
// This function might need some work
// Implemented some of the changes that Ambrosio recommended
// I am damaging the robots twice in this method
// go through later, and change this
void Arena::damageRobotAt(int r, int c)
{
    for(int i = 0; i < m_nRobots - 1; i++)
    {
        // see if the i robot matches the r and c val's of target for kill
        if(m_robots[i] -> row() == r && m_robots[i] -> col() == c)
        {
            //m_robots[i]->takeDamageAndLive(); // believe that this is what causes the robot to die in a one hit kill
            // becuase i am invoking this method twice
            // i was invoking this method twice, changed this and now code works properly!
            // executes if robot dies(returns false,which becomes true)
            if(!m_robots[i] -> takeDamageAndLive())
            {
                Robot * temp = m_robots[i];
                for(int k = i; k < m_nRobots - 1; k++)
                {
                    m_robots[k] = m_robots[k+1];
                }
                delete temp;
                m_nRobots--;
            }
            
        }
    }
}

//------------------------------------------------------------------------
// Method Notes:
// As implemented, the code below if acctivated kills the player if they happen to be in the location one
// of the robots moved to.
bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
        m_robots[k] ->move();
        // code that kills player if robot moves to their location
        
        if(m_robots[k]->row() == m_player->row() && m_robots[k]->col() == m_player->col())
        {
            m_player->setDead();
            
        }
        
    }
    
    // return true if the player is still alive, false otherwise
    return  m_player->isDead();
}
