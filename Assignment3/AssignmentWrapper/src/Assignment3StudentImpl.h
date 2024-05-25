#pragma once
#include "IAssignment3.h"
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<utility>


//Series of player scores (int)
// Players may join midgame
// Players that leave keep their score
// Scores will be modified after being entered
class Assignment3_1StudentImpl : public IAssignment3_1
{
    //Classic vector moment here
    //Make or own and then use the built ins (add new vals, edit current ones, and return specified values)
private:
    std::vector<int32_t> playerScores;
public:
    void NewPlayer(int32_t startingScore) final;
    int32_t GetPlayer(size_t index) final;
    void SetPlayer(size_t index, int32_t value) final;
};

//Series of players(objects)
// Can add or remove at any time
// Will often iterate across all players
// Will not need to look up a specific player except during removal
// Object pointers will be saved elsewhere and cannot be invalidated
class Assignment3_2StudentImpl : public IAssignment3_2
{
    //Im skiping this one, its broken my poroject 1 too many times
    //Now its time
private:
    std::vector<Player*> players;
public:
    Player* AddPlayer() final;
    void RemovePlayer(Player* player) final;
    void Iterate(IterateCallback* callbackFunction, void* userData) final;
};

//A series of player waypoints to follow
// New waypoints always added to the end
// Waypoints followed in order and removed from the front
class Assignment3_3StudentImpl : public IAssignment3_3
{
    //FIFO you say .... Sounds like a qeueueue is what we need xd
private:
    std::queue<Waypoint> waypoints;
public:
    Waypoint& AddWaypoint(void) final;
    Waypoint& GetNextWaypoint(void) final;
    void RemoveNextWaypoint(void) final;
};

//A tetris-style game board(int)
// Fixed size 10x, 20y
// Need to be able to move blocks to adjacent cells
// Int represents block type
class Assignment3_4StudentImpl : public IAssignment3_4
{
    //Knowing adjacent tile means youd need forward and back iteration
    //There's apparently a 2D list typ in C++ already so I'm gonna use that.
    //Big swag, passed all my tests :)
private:
    int32_t cells[10][20];
public:
    void SetCell(uint8_t x, uint8_t y, int32_t value) final;
    int32_t GetCell(uint8_t x, uint8_t y) final;
    void ClearCell(uint8_t x, uint8_t y) final;
    void MoveCell(uint8_t oldX, uint8_t oldY, uint8_t newX, uint8_t newY) final;
};

//Unlocked abilities by ID(int)
// Numbers 0 - 100
// Can be added in any order
// Adding duplicates should have no effect
// Will want to iterate in sorted order after all are entered
class Assignment3_5StudentImpl : public IAssignment3_5
{
private:
    //Use a set since duplicates SUCK and we HATE them
    std::set<int32_t> abilities;
public:
    void AddNumber(int32_t number) final;
    void Iterate(IterateCallback* callbackFunction, void* userData) final;
};

//Sorted student scores with names(int, string)
// Same as above, but with additional string data associated with each
class Assignment3_6StudentImpl : public IAssignment3_6
{
private:
    std::multimap<int32_t, std::string> scores;
public:
    void AddScore(int32_t score, const std::string& name) final;
    void Iterate(IterateCallback* callbackFunction, void* userData) final;
};

//Massive game board(int64, int64, objptr)
// Can be any size up to max int
// Don’t have to worry about enforcing board dimensions
// Will want to check a board location for any object present
class Assignment3_7StudentImpl : public IAssignment3_7
{
    //Created a single hash given the two intial values, then raising the first to the power of the second
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ hash2;
        }
    };
    //Given two std pairs, return true if they are the same (identical first and second values), and false otherwise. This helps check for duplicates within the map
    struct pair_equal {
        template <class T1, class T2>
        bool operator () (const std::pair<T1, T2>& pair1, const std::pair<T1, T2>& pair2) const {
            return pair1.first == pair2.first && pair1.second == pair2.second;
        }
    };
private:
    std::unordered_map<std::pair<int64_t, int64_t>, Player*, pair_hash, pair_equal> gameBoard;
public:
    bool AddPlayer(int64_t x, int64_t y, Player* player) final;
    void RemovePlayer(int64_t x, int64_t y) final;
    bool MovePlayer(int64_t oldX, int64_t oldY, int64_t newX, int64_t newY) final;
    Player* GetPlayer(int64_t x, int64_t y) final;
};
