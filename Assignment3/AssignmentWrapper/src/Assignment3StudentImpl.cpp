#include "Assignment3StudentImpl.h"
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;
#define UNUSED_ARG(arg) (void)arg

// ================================================================================================
// Assignment3_1StudentImpl

// This function adds a new player to the storage with the provided starting score.
// The function takes an integer 'startingScore' as input parameter which represents the starting score of the new player.
void Assignment3_1StudentImpl::NewPlayer(int32_t startingScore)
{
    //Add the score to the list of scores using the built in function/
    playerScores.push_back(startingScore);
}

// This function returns the score of the player at the specified index.
// The function takes a 'size_t' parameter 'index' as input which represents the index of the player in the storage.
int32_t Assignment3_1StudentImpl::GetPlayer(size_t index)
{
    //Just return the value stored at that index.
    return playerScores[index];
}

// This function updates the score of the player at the specified index with the provided value.
// The function takes a 'size_t' parameter 'index' as input which represents the index of the player in the storage.
// It also takes an integer 'value' as input parameter which represents the new score of the player.
void Assignment3_1StudentImpl::SetPlayer(size_t index, int32_t value)
{
    //Set the value according to the index, built in function
    playerScores[index] = value;
    UNUSED_ARG(index);
    UNUSED_ARG(value);
    
}

// ================================================================================================
// Assignment3_2StudentImpl

// This function adds a new player to the storage.
Player* Assignment3_2StudentImpl::AddPlayer()
{   
    //Create a new player, add it to the list, and return it by reference
    Player* newPlayer = new Player;
    players.push_back(newPlayer);
    return newPlayer;
}

// This function removes a player from the storage.
// It takes a pointer to a player object 'player' as input parameter which represents the player to be removed.
void Assignment3_2StudentImpl::RemovePlayer(Player* player)
{
    //Iterate through the vector until a value matches the given pointer, delete that valu and then the pointer
    auto it = find(players.begin(), players.end(), player);
    if (it != players.end())
    {
        players.erase(it);
        delete player;
    }
   
}

// This function iterates through all the player objects in the storage and calls the provided callback function for each player.
// The function takes two input parameters:
// 1. A pointer to a callback function 'callbackFunction' which is invoked for each player object.
// 2. A void pointer 'userData' which needs to be passed to the callback each time it is called
void Assignment3_2StudentImpl::Iterate(IterateCallback* callbackFunction, void* userData)
{
    for (Player* player : players)
    {
        //Call the ffunciton and apss in the userdata for each player in players
        callbackFunction(player, userData);
    }
}

// ================================================================================================
// Assignment3_3StudentImpl

// This function adds a new waypoint to the collection of waypoints and returns a reference to the added waypoint.
Waypoint& Assignment3_3StudentImpl::AddWaypoint(void)
{
    //Add the waypoint to queue, then return the last one
    waypoints.emplace();
    return waypoints.back();
}

// This function returns a reference to the next waypoint in the collection of waypoints.
Waypoint& Assignment3_3StudentImpl::GetNextWaypoint(void)
{
    //Queue has FIFO, so it will return the correct waypoint
    return waypoints.front();
}

// This function removes the next waypoint in the collection of waypoints.
void Assignment3_3StudentImpl::RemoveNextWaypoint(void)
{
    //Check if the queue is empty, then remove the value if it is not
    if (!waypoints.empty())
    {
        waypoints.pop();
    }
}

// ================================================================================================
// Assignment3_4StudentImpl

// This function sets the value of a cell in a 2D grid.
// It takes three parameters - two unsigned 8-bit integers 'x' and 'y' representing the row and column indices of the cell,
// and an integer 'value' representing the new value to be set in the cell.
void Assignment3_4StudentImpl::SetCell(uint8_t x, uint8_t y, int32_t value)
{
    //GET that dang value in the spot pwis
    cells[x][y] = value;
    UNUSED_ARG(x);
    UNUSED_ARG(y);
    UNUSED_ARG(value);
}

// This function retrieves the value of a cell in a 2D grid.
// It takes two parameters - two unsigned 8-bit integers 'x' and 'y' representing the row and column indices of the cell.
int32_t Assignment3_4StudentImpl::GetCell(uint8_t x, uint8_t y)
{
    //GIMME that value
    UNUSED_ARG(x);
    UNUSED_ARG(y);
    return cells[x][y];
}

// This function clears the value of a cell in a 2D grid, making it empty.
// It takes two parameters - two unsigned 8-bit integers 'x' and 'y' representing the row and column indices of the cell.
void Assignment3_4StudentImpl::ClearCell(uint8_t x, uint8_t y)
{
    //Set it to zero, i guess
    //It says ints represent the bloicks so hope that 0 doesnt refer to a specific block type
    cells[x][y] = 0;
    UNUSED_ARG(x);
    UNUSED_ARG(y);
}

// This function moves the value of a cell from its old position to a new position in a 2D grid.
// It takes four parameters - four unsigned 8-bit integers 'oldX', 'oldY', 'newX' and 'newY' 
// representing the row and column indices of the old and new positions.
// If the new cell is occupied, it swaps the values of the two cells
void Assignment3_4StudentImpl::MoveCell(uint8_t oldX, uint8_t oldY, uint8_t newX, uint8_t newY)
{
    //Bro theres a built in function for this lets GOOOOO
    swap(cells[oldX][oldY], cells[newX][newY]);
    UNUSED_ARG(oldX);
    UNUSED_ARG(oldY);
    UNUSED_ARG(newX);
    UNUSED_ARG(newY);
}

// ================================================================================================
// Assignment3_5StudentImpl

// This function adds a new integer number to the data storage.
// The function takes an integer 'number' as input parameter which represents the number to be added to the data storage.
void Assignment3_5StudentImpl::AddNumber(int32_t number)
{
    //Use insert because we got that storage data type babey
    abilities.insert(number);
    UNUSED_ARG(number);
}

// This function iterates through the data storage and calls the provided callback function for each element.
// The function takes two parameters as input:
// 1. A pointer to an object of type 'IterateCallback' which represents the callback function to be called for each element.
// 2. A void pointer 'userData' which needs to be passed to the callback each time it is called
void Assignment3_5StudentImpl::Iterate(IterateCallback* callbackFunction, void* userData)
{
    //iterate with autho because its a BEAST, and then call the function with the specified abilitiy (number in this case) and the userdata
    for (auto& number : abilities) 
    {
        callbackFunction(number, userData);
    }
    UNUSED_ARG(callbackFunction);
    UNUSED_ARG(userData);
}

// ================================================================================================
// Assignment3_6StudentImpl

// This function adds a new score with the provided name to the internal storage.
// It takes an integer 'score' and a 'const std::string&' parameter 'name' as input, 
// which represent the score and name of the new score respectively.
void Assignment3_6StudentImpl::AddScore(int32_t score, const std::string& name)
{
    //Std:: makes it easy sometimes
    scores.emplace(score, name);
   
}

// This function iterates over the internal storage of scores and calls a provided callback function for each score.
// The function takes two parameters as input:
// 1. A pointer to an object of type 'IterateCallback' which represents the callback function to be called for each element.
// 2. A void pointer 'userData' which needs to be passed to the callback each time it is called
void Assignment3_6StudentImpl::Iterate(IterateCallback* callbackFunction, void* userData)
{
    for (const auto& scoreNamePair : scores) 
    {
        callbackFunction(scoreNamePair.first, scoreNamePair.second, userData);
    }
    //Iterate through the pairs, calling the function with each of their values
    UNUSED_ARG(callbackFunction);
    UNUSED_ARG(userData);
}

// ================================================================================================
// Assignment3_7StudentImpl

// This function adds a player to the given coordinates (x, y).
// It takes two int64_t parameters 'x' and 'y' as input which represent the coordinates where the player needs to be added.
// It also takes a pointer to a Player object 'player' as input parameter which represents the player to be added.
// If the location is occupied, this function should do nothing and return false
bool Assignment3_7StudentImpl::AddPlayer(int64_t x, int64_t y, Player* player)
{
    //If you iterate through the whole game board without finding the value, then add the player, otherwise if its full, do nothing
    if (gameBoard.find(make_pair(x, y)) == gameBoard.end())
    {
        gameBoard[(make_pair(x, y))] = player;
        return true;
    }
    UNUSED_ARG(x);
    UNUSED_ARG(y);
    UNUSED_ARG(player);
    return false;
}

// This function removes a player from the given coordinates (x, y).
// It takes two int64_t parameters 'x' and 'y' as input which represent the coordinates from where the player needs to be removed.
// If the location is empty, this function should do nothing
void Assignment3_7StudentImpl::RemovePlayer(int64_t x, int64_t y)
{
    //Get rid of that pair
    gameBoard.erase(make_pair(x, y));
    UNUSED_ARG(x);
    UNUSED_ARG(y);
}

// This function moves the player from the old coordinates (oldX, oldY) to the new coordinates (newX, newY).
// It takes four int64_t parameters 'oldX', 'oldY', 'newX', and 'newY' as input which represent the old and 
// new coordinates of the player.
// If the new location is occupied, this function should do nothing and return false
bool Assignment3_7StudentImpl::MovePlayer(int64_t oldX, int64_t oldY, int64_t newX, int64_t newY)
{
    //If the space is empty, just move the player there. and delete it from where it once was
    if (gameBoard.find(std::make_pair(newX, newY)) == gameBoard.end())
    {
        auto it = gameBoard.find(std::make_pair(oldX, oldY));
        if (it != gameBoard.end())
        {
            gameBoard[make_pair(newX, newY)] = it->second;
            gameBoard.erase(it);
            return true;
        }
      
    }
    UNUSED_ARG(oldX);
    UNUSED_ARG(oldY);
    UNUSED_ARG(newX);
    UNUSED_ARG(newY);
    //Otherwise, do nothing and just return false;
    return false;
}

// This function returns a pointer to the player object present at the given coordinates (x, y).
// It takes two int64_t parameters 'x' and 'y' as input which represent the coordinates where the player is present.
// If no player exists at the location, this function should return nullptr
Player* Assignment3_7StudentImpl::GetPlayer(int64_t x, int64_t y)
{
    //If you can find the pair with find, then return the correspodning player, otherwise, return nullptr (since theres no player to point to :( )
    auto it = gameBoard.find(make_pair(x, y));
    if (it != gameBoard.end())
    {
        return it->second;
    }
    UNUSED_ARG(x);
    UNUSED_ARG(y);
    return nullptr;
}