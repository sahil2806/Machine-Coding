#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

Game::Game(int boardSize, vector<char> playerNames) : board(boardSize)
{
    for (char name : playerNames)
    {
        players.emplace_back(name);
    }
}

void Game::setupBoard()
{
    board.addLadder(2, 21);
    board.addLadder(15, 24);
    board.addSnake(10, 3);
    board.addSnake(18, 7);
}

void Game::play()
{
    std::queue<int> playerQueue;
    for (int i = 0; i < players.size(); i++)
    {
        playerQueue.push(i);
    }

    while (true)
    {
        totalSteps++;
        int idx = playerQueue.front();
        playerQueue.pop();
        Player &p = players[idx];

        int diceRoll = dice.roll();

        int tentativePos = p.position + diceRoll;

        if (tentativePos > board.getSize())
        {
            playerQueue.push(idx);
            continue;
        }

        p.position = board.getNextPosition(tentativePos);

        std::cout << "Player " << p.name << " moves to " << p.position << std::endl;

        if (p.position == board.getSize())
        {
            std::cout << "Player " << p.name << " wins the game!" << std::endl;
            std::cout << "Total steps taken in game: " << totalSteps << std::endl;
            break;
        }

        playerQueue.push(idx);
    }
}
