#pragma once
#include <string>
#include <vector>
#include "screen.h"

using namespace std;

enum class Status {UP, DOWN, LEFT, RIGHT, ESC, PAUSE, EMPTY, ON, OFF};

struct Infomation {
	string data;
	int x, y;     
	int ox, oy;  

	Infomation () {
		data = "";
		x = y = ox = oy = 0;
	}
};

void init(vector<Infomation>&, Infomation&, Infomation&, bool&, int);

void moveSnake(vector<Infomation>&, Infomation, Infomation&, bool&, int&);

void drawSnake(vector<Infomation>&);

void mainLoop(Status&, Status&, vector<Infomation>&, Infomation&, Infomation&, int&, bool&, int&);

void playGame(string name, string dateAndTime);
void randFood(Infomation &Food);

//void playGame();

