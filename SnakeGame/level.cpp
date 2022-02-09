#include "level.h"
#include "screen.h"

vector<function<void()>> level;

Screen gameDisplay;

void drawBorder() {
	gameDisplay.draw.retangle({ 2, 1 }, { 85, 42 }, GREEN, 2, colorXY);
	gameDisplay.draw.retangle({ 5, 2 }, { 63, 40 }, RED, 1, colorXY);
	gameDisplay.draw.retangle({ 134, 2 }, { 18, 40 }, RED, 1, colorXY);

}

void level1() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	//gameDisplay.draw.retangle({ 119, 0 }, { 0, 44 }, GREEN, 1, colorXY);
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