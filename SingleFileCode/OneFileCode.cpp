#include <bits/stdc++.h>
using namespace std;


// Dice class to handle dice rolls
class Dice
{
public:
    int roll()
    {
        return rand() % 6 + 1;
    }
};

// Player class
class Player
{
public:
    char name;
    int position;

    Player(char n)
    {
        name = n;
        position = 1; // all players start from 1
    }
};

// Board class
class Board
{
private:
    int size;
    vector<int> cells;

public:
    Board(int n)
    {
        size = n;
        cells.resize(n * n + 1, -1);
    }

    void addLadder(int start, int end)
    {
        cells[start] = end;
    }

    void addSnake(int start, int end)
    {
        cells[start] = end;
    }

    int getNextPosition(int pos)
    {
        if (pos <= size * size)
        {
            return (cells[pos] == -1) ? pos : cells[pos];
        }
        return pos;
    }

    int getSize() { return size * size; }
};

// Game class
class Game
{
private:
    Board board;
    vector<Player> players;
    Dice dice;
    int totalSteps = 0;

public:
    Game(int boardSize, vector<char> playerNames) : board(boardSize)
    {
        for (char name : playerNames)
        {
            players.emplace_back(name);
        }
    }

    void setupBoard()
    {
        // Add ladders
        board.addLadder(2, 21);
        board.addLadder(15, 24);

        // Add snakes
        board.addSnake(10, 3);
        board.addSnake(18, 7);
    }

    void play()
    {
        queue<int> playerQueue;
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
                // can't move, requeue
                playerQueue.push(idx);
                continue;
            }

            p.position = board.getNextPosition(tentativePos);

            cout << "Player " << p.name << " moves to " << p.position << endl;

            if (p.position == board.getSize())
            {
                cout << "Player " << p.name << " wins the game!" << endl;
                cout << "Total steps taken in game: " << totalSteps << endl;
                break;
            }

            playerQueue.push(idx);
        }
    }
};


int main()
{
    srand(time(0));
    int n = 5;

    int m;
    cout << "Enter number of players: ";
    cin >> m;

    vector<char> playerNames;
    for (int i = 0; i < m; i++)
    {
        playerNames.push_back('A' + i);
    }

    Game game(n, playerNames);
    game.setupBoard();
    game.play();

    return 0;
}
