#pragma once
#include <vector>
#include "graphic.h"

using namespace std;

struct Menu {
	int x, y;
	string data;

	Menu() {
		x = y = 0;
		data = "";
	}
};

void initMenu(vector<Menu>& listMenu);
void printMenu(vector<Menu> listMenu);
void moveSelect(vector<Menu> listMenu, int& dir, bool& check);
void moveSelectSetting(vector<Menu> listMenu, int& dir, bool& check);
void setting();
void ourTeam();