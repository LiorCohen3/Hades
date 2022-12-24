#pragma once

class IdGenerator
{
private:
    int     lastID;
public:
    IdGenerator(int i) { lastID = i; }
    int createNewID() { return ++lastID; }
    int getLastID() { return lastID; }
};
