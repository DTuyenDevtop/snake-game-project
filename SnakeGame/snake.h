#pragma once
#include <string>
#include <vector>
#include "screen.h"

using namespace std;

enum class Status {UP, DOWN, LEFT, RIGHT, ESC, PAUSE, EMPTY, ON, OFF, SAVE};

#define WidthGame      120
#define HeightGame     35
#define SPEEDFIRST     80
#define SPEEDLATER	   30

struct Infomation {
	string data;
	int x, y;     
	int ox, oy;  

	Infomation () {
		data = "";
		x = y = ox = oy = 0;
	}
};

struct User {
	char name[20];
	int level;
	int score;
	int snakeLenght;
	char snakeData[100];
	int dirX, dirY;
	vector<Infomation> Snake;
};

void init(vector<Infomation>&, Infomation&, Infomation&, bool&, int);

void moveSnake(vector<Infomation>&, Infomation, Infomation&, bool&, int&);

void drawSnake(vector<Infomation>&);

void mainLoop(Status&, Status&, vector<Infomation>&, Infomation&, Infomation&, double&, bool&, int&);

void playGame(string name, string& dateAndTime);

void randFood(Infomation &Food);

void loadGame();

int loadFileUserData();

void drawLosingSnake(vector<Infomation>& Snake);

void decorateBonus();

void coolDown();
