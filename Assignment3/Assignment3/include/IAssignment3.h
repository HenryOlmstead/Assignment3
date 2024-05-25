#pragma once
#include <cstdint>
#include <string>
#include "DummyObj.h"

class IAssignment3_1
{
public:
    virtual void NewPlayer(int32_t startingScore) = 0;
    virtual int32_t GetPlayer(size_t index) = 0;
    virtual void SetPlayer(size_t index, int32_t value) = 0;
};

class IAssignment3_2
{
public:
    typedef void IterateCallback(Player* currentPlayer, void* userData);

    virtual Player* AddPlayer() = 0;
    virtual void RemovePlayer(Player* player) = 0;
    virtual void Iterate(IterateCallback* callbackFunction, void* userData) = 0;
};

class IAssignment3_3
{
public:
    virtual Waypoint& AddWaypoint(void) = 0;
    virtual Waypoint& GetNextWaypoint(void) = 0;
    virtual void RemoveNextWaypoint(void) = 0;
};

class IAssignment3_4
{
public:
    virtual void SetCell(uint8_t x, uint8_t y, int32_t value) = 0;
    virtual int32_t GetCell(uint8_t x, uint8_t y) = 0;
    virtual void ClearCell(uint8_t x, uint8_t y) = 0;
    virtual void MoveCell(uint8_t oldX, uint8_t oldY, uint8_t newX, uint8_t newY) = 0;
};

class IAssignment3_5
{
public:
    typedef void IterateCallback(int32_t currentNumber, void* userData);

    virtual void AddNumber(int32_t number) = 0;
    virtual void Iterate(IterateCallback* callbackFunction, void* userData) = 0;
};

class IAssignment3_6
{
public:
    typedef void IterateCallback(int32_t currentScore, const std::string& name, void* userData);

    virtual void AddScore(int32_t score, const std::string& name) = 0;
    virtual void Iterate(IterateCallback* callbackFunction, void* userData) = 0;
};

class IAssignment3_7
{
public:
    virtual bool AddPlayer(int64_t x, int64_t y, Player* player) = 0;
    virtual void RemovePlayer(int64_t x, int64_t y) = 0;
    virtual bool MovePlayer(int64_t oldX, int64_t oldY, int64_t newX, int64_t newY) = 0;
    virtual Player* GetPlayer(int64_t x, int64_t y) = 0;
};
