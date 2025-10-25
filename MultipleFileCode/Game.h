#pragma once

#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include <bits/stdc++.h>
using namespace std;

class Game {

public:
    Board board;
    vector<Player> players;
    Dice dice;
    int totalSteps = 0;


    Game(int boardSize,vector<char> playerNames);
    void setupBoard();
    void play();
};
