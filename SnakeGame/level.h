#pragma once
#include <functional>
#include <vector>

using namespace std;

extern vector<function<void()>> level;

void level1();

void level2();

void level3();

void level4();

void level5();

void initLevel();

void bonusLevel();

void moveNextLevel();