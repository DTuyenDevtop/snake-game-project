#include "level.h"
#include "screen.h"

vector<function<void()>> level;

Screen gameDisplay;

void drawBorder() {
	gameDisplay.draw.retangle({ 2, 1 }, { 83, 42 }, GREEN, 2, colorXY);
	gameDisplay.draw.retangle({ 5, 2 }, { 63, 40 }, RED, 1, colorXY);
	gameDisplay.draw.retangle({ 134, 2 }, { 16, 40 }, RED, 1, colorXY);

}

void level1() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	gameDisplay.draw.retangle({ 14, 17 }, { 8, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 14, 28 }, { 8, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 105, 17 }, { 8, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 105, 28 }, { 8, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 50, 5 }, { 0, 8 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 85, 5 }, { 0, 8 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 50, 31 }, { 0, 8 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 85, 31 }, { 0, 8 }, BLACK, 2, colorXY);

}

void level2() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	gameDisplay.draw.retangle({ 6, 22 }, { 12, 0 }, BLACK, 1, colorXY);
	gameDisplay.draw.retangle({ 45, 22 }, { 24, 0 }, BLACK, 1, colorXY);
	gameDisplay.draw.retangle({ 106, 22 }, { 12, 0 }, BLACK, 1, colorXY);
	gameDisplay.draw.retangle({ 70, 2 }, { 0, 7 }, BLACK, 1, colorXY);
	gameDisplay.draw.retangle({ 70, 14 }, { 0, 16 }, BLACK, 1, colorXY);
	gameDisplay.draw.retangle({ 70, 35 }, { 0, 7 }, BLACK, 1, colorXY);
}

void level3() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	gameDisplay.draw.retangle({ 15, 7 }, { 0, 10 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 15, 7 }, { 20, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 15, 37 }, { 20, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 15, 27 }, { 0, 10 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 120, 7 }, { 0, 10 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 80, 7 }, { 20, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 80, 37 }, { 20, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 120, 27 }, { 0, 10 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 38, 22 }, { 30, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 68, 12 }, { 0, 20 }, BLACK, 2, colorXY);
}

void level4() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	gameDisplay.draw.retangle({ 6, 15 }, { 53, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 25, 7 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 42, 16 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 59, 7 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 76, 16 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 93, 7 }, { 0, 7 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 22, 29 }, { 53, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 42, 30 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 59, 21 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 76, 30 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 93, 21 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 110, 30 }, { 0, 7 }, BLACK, 2, colorXY);
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