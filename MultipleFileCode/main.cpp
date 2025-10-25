#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int n = 5;

    int m;
    std::cout << "Enter number of players: ";
    std::cin >> m;

    std::vector<char> playerNames;
    for (int i = 0; i < m; i++)
    {
        playerNames.push_back('A' + i);
    }

    Game game(n, playerNames);
    game.setupBoard();
    game.play();

    return 0;
}
