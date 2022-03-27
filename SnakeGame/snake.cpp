#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "snake.h"
#include "graphic.h"
#include "gameSound.h"
#include "level.h"
#include "menu.h"

#include <vector>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

std::string studentIds = "21127003211276482112709021127493";
int position = 8;
string colorXY[205][85], userName;
short snakeColor;
vector<Player> savePlayers;
Status Sound;
double Speed = SPEEDFIRST;
int requirement[] = { 1, 1, 1, 1, 1, 99999};
int currRequirement, currentLevel;
time_t now;
int bonus = 5;

void randFood(Infomation& Food) {
	Food.x = 5 + rand() % (WidthGame - 5);
	Food.y = 5 + rand() % (HeightGame - 5);

	while (colorXY[Food.x][Food.y] == "DANGER") {
		srand((unsigned int)time(0));
		Food.x = 5 + rand() % (WidthGame - 5);
		Food.y = 5 + rand() % (HeightGame - 5);
	}
	colorXY[Food.x][Food.y] = "FOOD_INC";
}

void init(vector<Infomation>& Snake, Infomation& Food, Infomation&Direction, bool& endGame, int score) {
	Infomation Body;
	endGame = false;

	gotoXY(147, 5);  
	colorText("Score: ", RED); 
	cout << score;
	gotoXY(143, 6);
	colorText("Requirement: ", RED);
	cout << currRequirement << " / " << requirement[currentLevel];
	gotoXY(145, 7);
	colorText("Speed: ", RED);
	cout << (int)-Speed + 120 << " km/h";
	
	drawInGate(7, 5);
	for (int i = 0; i < 8; i++) {
		Body.data = studentIds[i];
		Body.x = 11; Body.y = 3;
		Snake.push_back(Body);
	}

	randFood(Food);
	gotoXY(Food.x, Food.y);
	colorText(254, snakeColor);

	// Init direction
	Direction.x = 0;
	Direction.y = 1;
}

int maxTime = 15;
int tmp = 15;

void moveSnake(vector<Infomation>& Snake, Infomation dir, Infomation& Food, bool& endGame, int& score) {
	Infomation Add;
	size_t size = Snake.size();

	for (size_t i = 0; i < size_t(size); i++) {
		if (i == 0) {
			// Move the head
			Snake[0].ox = Snake[0].x;    
			Snake[0].oy = Snake[0].y;
			
			Snake[0].x += dir.x;         
			Snake[0].y += dir.y;
		}
		else {
			// Move the body
			Snake[i].ox = Snake[i].x;         
			Snake[i].oy = Snake[i].y;
			
			Snake[i].x = Snake[i - 1].ox;     
			Snake[i].y = Snake[i - 1].oy;
		}

		// Pass the width and height
		//if (Snake[i].x >= WidthGame) {
		//	Snake[i].x = 0;
		//}

		//if (Snake[i].x < 0) {
		//	Snake[i].x = WidthGame - 1;
		//}
		//if (Snake[i].y >= HeightGame) { 
		//	Snake[i].y = 0; 
		//}
		//if (Snake[i].y < 0) {
		//	Snake[i].y = HeightGame - 1;
		//}

		if (colorXY[Snake[0].x][Snake[0].y] == "DANGER") {
			position = 8;
			currRequirement = 0;
			Speed = SPEEDFIRST;
			currentLevel = 0;
			maxTime = 15;
			endGame = true;
		}

		// Check seft-hitting
		if (i != 0 && (Snake[0].x == Snake[i].x && Snake[0].y == Snake[i].y)) {
			position = 8;
			currRequirement = 0;
			currentLevel = 0;
			Speed = SPEEDFIRST;
			maxTime = 15;
			gotoXY(Food.x, Food.y); 
			cout << " ";
			endGame = true;
		}
	}
	
	// Eat food
	if (colorXY[Snake[0].x][Snake[0].y] == "FOOD_INC") {
		colorXY[Food.x][Food.y] = "SAFE";
		
		if (Sound == Status::OFF) {
			playSound(L"resources/eatfood.wav");
		}

		if (position == studentIds.size() - 1) {
			position = 0;
		}

		Add.data = studentIds[position++];
		Add.x = Snake[size - 1].ox;
		Add.y = Snake[size - 1].oy;
		Snake.push_back(Add);

		score += 100;
		currRequirement += 1;

		if (currRequirement < requirement[currentLevel]) {
			// Creat new food
			randFood(Food);

			gotoXY(Food.x, Food.y);
			colorXY[Food.x][Food.y] = "FOOD_INC";
			colorText(254, snakeColor);
		}
	} 
	else if (colorXY[Snake[0].x][Snake[0].y] == "FOOD_BINC") { // Bonus increase, increase length and score
		colorXY[Food.x][Food.y] = "SAFE";

		if (Sound == Status::OFF) {
			playSound(L"resources/eatfood.wav");
		}

		if (position == studentIds.size() - 1) {
			position = 0;
		}

		Add.data = studentIds[position++];
		Add.x = Snake[size - 1].ox;
		Add.y = Snake[size - 1].oy;
		Snake.push_back(Add);

		score += 100;
		currRequirement += 1;
		//gotoXY(147, 5);
		//colorText("Score: ", RED);
		//cout << score;
	}
	else if (colorXY[Snake[0].x][Snake[0].y] == "FOOD_BST") { // Just increase score
		colorXY[Food.x][Food.y] = "SAFE";

		if (Sound == Status::OFF) {
			playSound(L"resources/eatfood.wav");
		}

		score += 100;
		currRequirement += 1;
		//gotoXY(147, 5);
		//colorText("Score: ", RED);
		//cout << score;
	}
}

void drawSnake(vector<Infomation>& Snake) {
	size_t size = Snake.size();
	textColor(snakeColor);
	for (int i = 0; i < size; i++) {
		gotoXY(Snake[i].x, Snake[i].y);
		cout << Snake[i].data;
	}
	gotoXY(Snake[size - 1].ox, Snake[size - 1].oy);
	cout << " "; 
}

void mainLoop (
	Status& StatusMove, Status& StatusGame, 
	vector<Infomation>& Snake, 
	Infomation& Direction, Infomation& Food, 
	double& Speed, bool& endGame, int& score
) {
	gotoXY(147, 5);
	colorText("Score: ", RED);
	cout << score;
	gotoXY(143, 6);
	colorText("Requirement: ", RED);
	cout << currRequirement << " / " << requirement[currentLevel];
	gotoXY(145, 7);
	colorText("Speed: ", RED);
	cout << (int)-Speed + 120 << " km/h";
	moveSnake(Snake, Direction, Food, endGame, score);
	
	if (currentLevel == bonus) {
		gotoXY(10, 10);
		time_t currSec = time(0);
		if (maxTime != 0) {
			maxTime = tmp - (int)(currSec - now);
		}
		printf("%02d", maxTime);
	}

	if (_kbhit()) {
		int key = _getch();

		if (key < 97 && key > 65) { // A - Z
			key += 32;
		}

		if (key == 'a') {
			StatusMove = Status::LEFT;
		}
		else if (key == 'd') {
			StatusMove = Status::RIGHT;
		}
		else if (key == 'w') {
			StatusMove = Status::UP;
		}
		else if (key == 's') {
			StatusMove = Status::DOWN;
		}
		else if (key == 'l') {
			StatusGame = Status::SAVE;
		}
		else if (key == 32) { // Space - pause game
			pauseGame();
			StatusGame = Status::PAUSE;
		}
		else if (key == 27) {
			StatusGame = Status::ESC; // ESC - Exit game
		}
	}

	if (StatusMove == Status::LEFT) {
		if (Direction.x != 1) {
			Direction.x = -1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == Status::RIGHT) {
		if (Direction.x != -1) {
			Direction.x = 1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == Status::UP) {
		if (Direction.y != 1) {
			Direction.y = -1;
			Direction.x = 0;
		}
	}
	else if (StatusMove == Status::DOWN) {
		if (Direction.y != -1) {
			Direction.y = 1;
			Direction.x = 0;
		}
	}

	if (StatusGame == Status::PAUSE) {
		while (true) {
			if (_kbhit()) { // Wait for pressing space again
				int key = _getch();

				if (key == 32) {
					system("cls");
					level[currentLevel]();
					
					if (currRequirement != requirement[currentLevel]) {
						gotoXY(Food.x, Food.y);
						colorXY[Food.x][Food.y] = "FOOD_INC";
						colorText(254, snakeColor);
					}

					if (currRequirement == requirement[currentLevel]) {
						drawOutGate(3, 121, 38);
					}
					
					StatusGame = Status::EMPTY;
					break;
				}
				else {
					continue;
				}
			}
		}
	}

	if (StatusGame == Status::ESC) {
		position = 8;
		currRequirement = 0;
		endGame = true;
	}

	if (StatusGame == Status::SAVE) {
		ofstream fOut;
		fOut.open("gameData.txt", ios::app);
		fOut << "\n\nUser: " << userName << "\n";
		fOut << "Level: " << currentLevel + 1 << "\n";
		fOut << "Length: " << Snake.size() << "\n";
		fOut << "Snake Data: ";
		for (int i = 0; i < Snake.size(); ++i) {
			fOut << Snake[i].data;
		}
		fOut << "\n";
		fOut << "Snake Position: ";
		for (int i = 0; i < Snake.size(); ++i) {
			fOut << Snake[i].x << ' ' << Snake[i].y << ' ';
		}
		fOut << "\n";
		fOut << "Direction: " << Direction.x << ' ' << Direction.y << "\n";
		fOut << "Score: " << score;

		position = 8;
		currRequirement = 0;
		
		endGame = true;
	}
}

void playGame(string name, string& dateAndTime) {
	system("cls");

	userName = name;
	vector<Infomation> Snake;
	Infomation Direction, Food;
	Status StatusMove, StatusGame;
	string oldSnake = "";

	srand((unsigned int)time(0));


	int score = 0;
	bool endGame = false, isDrawGate = false;

	currentLevel = 0;
	currRequirement = 0;

	initLevel();

	level[currentLevel]();

	init(Snake, Food,Direction, endGame, score);

	while (!endGame) {
		Sleep(Speed);
		mainLoop(StatusMove, StatusGame, Snake,Direction, Food, Speed, endGame, score);
		drawSnake(Snake);
		
		int xStart = Snake[0].x;
		int yStart = Snake[0].y;

		if (colorXY[xStart][yStart] == "SAFE") {
			oldSnake.resize(Snake.size());
			for (int i = 0; i < Snake.size(); ++i) {
				oldSnake[i] = (Snake[i].data[0]);
			}
		}

		if (colorXY[xStart][yStart] == "PASS" && Snake.size() > 1) {
			Snake.erase(Snake.begin());
		}

		int xEnd = Snake[Snake.size() - 1].x;
		int yEnd = Snake[Snake.size() - 1].y;

		if (colorXY[xEnd][yEnd] == "DONE") {
			clearInGate(7, 5);
		}

		if ((maxTime == 0 || currRequirement == requirement[currentLevel]) && !isDrawGate) {
			if (currentLevel < 2) {
				drawOutGate(3, 121, 38);
			}
			else if (currentLevel < 4) {
				drawOutGate(2, 121, 38);
			}
			else {
				drawOutGate(1, 121, 38);
			}
			isDrawGate = true;
		}

		if (maxTime == 0) {
			for (int i = 5; i <= WidthGame; ++i) {
				for (int j = 5; j <= HeightGame; ++j) {
					if (colorXY[i][j] == "FOOD_BINC" || colorXY[i][j] == "FOOD_BST" || colorXY[i][j] == "FOOD_INC") {
						gotoXY(i, j);
						colorXY[i][j] = "SAFE";
						colorText(254, BACKGROUND_COLOR);
					}
				}
			}
			gotoXY(Food.x, Food.y);
			colorXY[Food.x][Food.y] = "SAFE";
			colorText(254, BACKGROUND_COLOR);
		}

		if ((maxTime == 0 || currRequirement == requirement[currentLevel]) && colorXY[xEnd][yEnd] == "PASS") {
			isDrawGate = false;
			system("cls");

			if (maxTime == 0) {
				maxTime = 15;
			}


			if (currentLevel <= bonus - 1) {
				++currentLevel;
				level[currentLevel]();
				if (Speed > 30) Speed -= 10;
				else Speed = Speed / 1.25;
			}
			else {
				currentLevel = 0;
				level[currentLevel]();
				if (Speed > 30) Speed -= 10;
				else Speed = Speed / 1.25;
			}
			

			drawInGate(7, 5);

			Sleep(2000);

			currRequirement = 0;
			//score = 0;
			
			Snake.resize(oldSnake.size());
			for (int i = 0; i < oldSnake.size(); ++i) {
				Snake[i].data = oldSnake[i];
				Snake[i].x = 11;
				Snake[i].y = 3;
			}

			Snake[0].ox = Snake[0].x;
			Snake[0].oy = Snake[0].y;

			Snake[0].x = 11;
			Snake[0].y = 3;

			for (size_t i = 1; i < Snake.size(); ++i) {
				Snake[i].x = Snake[i - 1].x;
				Snake[i].y = Snake[i - 1].y;
			}

			StatusMove = Status::DOWN;
			Direction.x = 0;
			Direction.y = 1;

			randFood(Food);
			gotoXY(Food.x, Food.y);
			colorText(254, snakeColor);

			if (currentLevel == bonus) {
				now = time(0);
			}
			
			mainLoop(StatusMove, StatusGame, Snake,Direction, Food, Speed, endGame, score);
			drawSnake(Snake);
		}
	}

	// end game
	while (true)
	{
		playSoundLoop(L"resources/losegame.wav");
		drawLosingSnake(Snake);
		deleteBorder();
		turnOffSound();
		break;
	}

	if (Sound == Status::ON)
	{
		playSoundLoop(L"resources/backgroundmusic.wav");
	}
	
	
	Sleep(1);
	loseGame(name, dateAndTime);

	time_t now = time(0);
	dateAndTime = ctime(&now);
	dateAndTime.pop_back();

	Player t;
	t.score = score;
	t.name = name;
	t.dateAndTime = dateAndTime;
	savePlayers.push_back(t);
	ofstream fileout;
	
	fileout.open("saveScore.txt", ios::app);
	if (fileout.fail() == true) {
		cout << "File cannot be found";
	}
	else {
		fileout << endl << t.score << endl;
		fileout << t.name << endl;
		fileout << t.dateAndTime;
	}
}

extern User user[100];

int loadFileUserData() {
	FILE* file;
	fopen_s(&file, "gameData.txt", "rt");
	int cnt = 0;

	for (int i = 0; i < 100; ++i) {
		user[cnt].Snake.clear();
	}

	if (file != nullptr) {
		while (!feof(file)) {
			fscanf_s(file, "User: %s\n", user[cnt].name, 20);
			fscanf_s(file, "Level: %d\n", &user[cnt].level);
			user[cnt].level--;

			fscanf_s(file, "Length: %d\n", &user[cnt].snakeLenght);
			printf("%d", user[cnt].snakeLenght);

			fscanf_s(file, "Snake Data: %s\n", user[cnt].snakeData, 100);

			fscanf_s(file, "Snake Position: ");
			Infomation data;
			for (int i = 0; i < user[cnt].snakeLenght; ++i) {
				int x = 0, y = 0;
				fscanf_s(file, "%d %d", &x, &y);
				data.data = user[cnt].snakeData[i];
				data.x = x;
				data.y = y;
				user[cnt].Snake.push_back(data);
			}

			fscanf_s(file, "\nDirection: %d %d\n", &user[cnt].dirX, &user[cnt].dirY);

			fscanf_s(file, "Score: %d", &user[cnt].score);
			++cnt;
		}
	}
	return cnt;
}

void loadGame() {
	int cnt = loadFileUserData();
	loadGameGraphic();
	string uName;
	cin >> uName;
	int pos = -1;

	for (int i = 0; i < cnt; ++i) {
		if (user[i].name == uName) {
			pos = i;
		}
	}

	if (pos == -1) {
		gotoXY(40, 10);
		textColor(RED);
		cout << "Invalid user name!";
		gotoXY(40, 11);
		cout << "You will be brought into main in 3s";
		Sleep(1000);
		gotoXY(40, 11);
		cout << "You will be brought into main in 2s";
		Sleep(1000);
		gotoXY(40, 11);
		cout << "You will be brought into main in 1s";
		Sleep(1000);
		gotoXY(40, 11);
		cout << "You will be brought into main in 0s"; 
		Sleep(1000);
		return;
	}

	system("cls");

	vector<Infomation> Snake = user[pos].Snake;
	Infomation Direction, Food;
	Status StatusMove, StatusGame;
	string oldSnake = "";

	srand((unsigned int)time(0));

	double Speed = SPEEDFIRST;
	int score = 0;
	bool endGame = false, isDrawGate = false;

	currentLevel = user[pos].level;
	currRequirement = user[pos].score / 100;

	initLevel();

	level[currentLevel]();

	//init(Snake, Food, Direction, endGame, score);

	randFood(Food);
	gotoXY(Food.x, Food.y);
	colorText(254, snakeColor);

	Direction.x = user[pos].dirX;
	Direction.y = user[pos].dirY;

	drawSnake(Snake);
	Sleep(1000);

	while (!endGame) {
		Sleep(Speed);
		mainLoop(StatusMove, StatusGame, Snake, Direction, Food, Speed, endGame, score);
		drawSnake(Snake);

		int xStart = Snake[0].x;
		int yStart = Snake[0].y;

		if (colorXY[xStart][yStart] == "SAFE") {
			oldSnake.resize(Snake.size());
			for (int i = 0; i < Snake.size(); ++i) {
				oldSnake[i] = (Snake[i].data[0]);
			}
		}

		if (colorXY[xStart][yStart] == "PASS" && Snake.size() > 1) {
			Snake.erase(Snake.begin());
		}

		int xEnd = Snake[Snake.size() - 1].x;
		int yEnd = Snake[Snake.size() - 1].y;

		if (colorXY[xEnd][yEnd] == "DONE") {
			clearInGate(7, 5);
		}

		if (currRequirement == requirement[currentLevel] && !isDrawGate) {
			drawOutGate(3, 121, 38);
			isDrawGate = true;
		}

		if (currRequirement == requirement[currentLevel] && colorXY[xEnd][yEnd] == "PASS") {
			isDrawGate = false;
			system("cls");

			if (currentLevel < level.size() - 1) {
				++currentLevel;
				level[currentLevel]();
				if (Speed > 30) Speed -= 10;
				else Speed = Speed / 1.25;
			}
			else {
				currentLevel = 0;
				level[currentLevel]();
				if (Speed > 30) Speed -= 10;
				else Speed = Speed / 1.25;
			}

			drawInGate(7, 5);

			Sleep(2000);

			currRequirement = 0;
			//score = 0;

			Snake.resize(oldSnake.size());
			for (int i = 0; i < oldSnake.size(); ++i) {
				Snake[i].data = oldSnake[i];
				Snake[i].x = 11;
				Snake[i].y = 3;
			}

			Snake[0].ox = Snake[0].x;
			Snake[0].oy = Snake[0].y;

			Snake[0].x = 11;
			Snake[0].y = 3;

			for (size_t i = 1; i < Snake.size(); ++i) {
				Snake[i].x = Snake[i - 1].x;
				Snake[i].y = Snake[i - 1].y;
			}

			StatusMove = Status::DOWN;
			Direction.x = 0;
			Direction.y = 1;

			randFood(Food);
			gotoXY(Food.x, Food.y);
			colorText(254, snakeColor);

			mainLoop(StatusMove, StatusGame, Snake, Direction, Food, Speed, endGame, score);
			drawSnake(Snake);
		}
	}

	// end game
	while (true)
	{
		playSoundLoop(L"resources/losegame.wav");
		drawLosingSnake(Snake);
		deleteBorder();
		turnOffSound();
		break;
	}

	if (Sound == Status::ON)
	{
		playSoundLoop(L"resources/backgroundmusic.wav");
	}

	Sleep(1);
	string pName;
	for (int i = 0; i < strlen(user[pos].name); ++i) {
		pName.push_back(user[pos].name[i]);
	}

	time_t now = time(0);
	string dateAndTime = ctime(&now);
	dateAndTime.pop_back();
	loseGame(pName, dateAndTime);
}

void drawLosingSnake(vector<Infomation>& Snake) {
	size_t size = Snake.size();
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0)
		{
			textColor(snakeColor);
			gotoXY(Snake[i].x, Snake[i].y);
			cout << Snake[i].data;
			Sleep(30);
		}
		else
		{
			textColor(WHITE);
			gotoXY(Snake[i].x, Snake[i].y);
			cout << Snake[i].data;
			Sleep(30);
		}
	}

	for (int i = 0; i < size; i++) {
		if (i % 2 != 0)
		{
			textColor(snakeColor);
			gotoXY(Snake[i].x, Snake[i].y);
			cout << Snake[i].data;
			Sleep(30);
		}
		else
		{
			textColor(WHITE);
			gotoXY(Snake[i].x, Snake[i].y);
			cout << Snake[i].data;
			Sleep(30);
		}
	}

	for (int i = 0; i < size; i++) {
		textColor(GRAY);
		gotoXY(Snake[i].x, Snake[i].y);
		cout << Snake[i].data;
		Sleep(30);
	} 

	gotoXY(Snake[size - 1].ox, Snake[size - 1].oy);
	cout << " ";
}
