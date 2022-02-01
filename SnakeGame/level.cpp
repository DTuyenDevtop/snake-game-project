#include "level.h"
#include "screen.h"

vector<function<void()>> level;

void level1() {

}

void level2() {

}

void level3() {

}

void level4() {

}

void level5() {

}

void initLevel() {
	level.push_back(level1);
	level.push_back(level2);
	level.push_back(level3);
	level.push_back(level4);
	level.push_back(level5);
}

void moveNextLevel() {

}