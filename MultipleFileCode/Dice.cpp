#include "Dice.h"
#include <bits/stdc++.h>
using namespace std;

int Dice::roll()
{
    return rand() % 6 + 1;
}
