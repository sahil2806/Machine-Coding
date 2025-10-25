#include "Board.h"
#include <bits/stdc++.h>
using namespace std;

Board::Board(int n)
{
    size = n;
    cells.resize(n * n + 1, -1);
}

void Board::addLadder(int start, int end)
{
    cells[start] = end;
}

void Board::addSnake(int start, int end)
{
    cells[start] = end;
}

int Board::getNextPosition(int pos)
{
    if (pos <= size * size)
    {
        return (cells[pos] == -1) ? pos : cells[pos];
    }
    return pos;
}

int Board::getSize()
{
    return size * size;
}
