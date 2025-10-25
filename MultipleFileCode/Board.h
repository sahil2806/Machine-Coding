#pragma once

#include <bits/stdc++.h>
using namespace std;

class Board
{
private:
    int size;
    vector<int> cells;

public:
    Board(int n);
    void addLadder(int start, int end);
    void addSnake(int start, int end);
    int getNextPosition(int pos);
    int getSize();
};
