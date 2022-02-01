#pragma once
#include "menu.h"

using namespace std;

void initMenu(vector<Menu>& listMenu) {
	Menu items;

	items.x = 85;
	items.y = 24;
	items.data = "PLAY GAME";
	listMenu.push_back(items);

	
	items.x = 85;
	items.y = 26;
	items.data = "LOAD GAME";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 28;
	items.data = "HIGH SCORE";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 30;
	items.data = "GUIDE";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 32;
	items.data = "SETTING";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 34;
	items.data = "OUR TEAM";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 36;
	items.data = "QUIT GAME";
	listMenu.push_back(items);
}

void printMenu(vector<Menu> listMenu) {
	for (int i = 0; i < listMenu.size(); i++) {
		gotoXY(listMenu[i].x, listMenu[i].y); 
		cout << listMenu[i].data;
	}
}

void moveSelect(vector<Menu> listMenu, int& dir, bool& check) {
	while (true) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 72) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0) {
					dir = 6;
				}
				else {
					dir--;
				}

				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				textColor(BYELLOW);
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				break;
			}
			else if (key == 80) { 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); 
				cout << listMenu[dir].data;

				if (dir == 6) {
					dir = 0;
				} 
				else {
					dir++;
				}

				textColor(RED); 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				break;
			}
			else if (key == 13) {
				check = true;
				break;
			}
		}
	}
}
