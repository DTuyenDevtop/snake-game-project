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
					dir = listMenu.size() - 1;
				}
				else {
					dir--;
				}

				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				textColor(RED);
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				//break;
			}
			else if (key == 80) { 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); 
				cout << listMenu[dir].data;

				if (dir == listMenu.size() - 1) {
					dir = 0;
				} 
				else {
					dir++;
				}

				textColor(RED); 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				//break;
			}
			else if (key == 13) {
				check = true;
				break;
			}
		}
	}
}

void moveSelectSetting(vector<Menu> listMenu, int& dir, bool& check) {
	while (true) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 72) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0) {
					dir = listMenu.size() - 1;
				}
				else {
					dir--;
				}

				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				textFillColor(RED, BLUE);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLUE);
				//break;
			}
			else if (key == 80) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y);
				cout << listMenu[dir].data;

				if (dir == listMenu.size() - 1) {
					dir = 0;
				}
				else {
					dir++;
				}

				textFillColor(RED, BLUE);
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLUE);
				//break;
			}
			else if (key == 13) {
				check = true;
				break;
			}
			else if (key == 27) {
				check = true;
				dir = -1;
				break;
			}
		}
	}
}

void setting() {
	textFillColor(BLUE, BLUE);
	for (int j = 15; j <= 40; ++j) {
		gotoXY(40, j);
		cout << "                                                                                                     ";
		Sleep(8);
	}

	textFillColor(WHITE, 65);
	for (int i = 40; i <= 140; ++i) {
		gotoXY(i, 15);
		cout << (char)(205);
		gotoXY(i, 40);
		cout << (char)(205);
	}

	for (int i = 15; i <= 40; ++i) {
		gotoXY(40, i);
		cout << (char)(186);
		gotoXY(140, i);
		cout << (char)(186);
	}

	gotoXY(40, 15);
	cout << (char)(201);

	gotoXY(40, 40);
	cout << (char)(200);

	gotoXY(140, 15);
	cout << (char)(187);

	gotoXY(140, 40);
	cout << (char)(188);

	int row = 16, col = 60;
	//gotoXY(col, row++);
	//cout << "  ____  _____ _____ _____ ___ _   _  ____  ";
	//gotoXY(col, row++);
	//cout << " / ___|| ____|_   _|_   _|_ _| \\ | |/ ___| ";
	//gotoXY(col, row++);
	//cout << " \\___ \\|  _|   | |   | |  | ||  \\| | |  _  ";
	//gotoXY(col, row++);
	//cout << "  ___) | |___  | |   | |  | || |\\  | |_| | ";
	//gotoXY(col, row++);
	//cout << " |____/|_____| |_|   |_| |___|_| \\_|\\____| ";
	//gotoXY(col, row++);
	textFillColor(BYELLOW, BLUE);
	gotoXY(col, row++);
	wcout << L"	███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ";
	gotoXY(col, row++);
	wcout << L"	██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ";
	gotoXY(col, row++);
	wcout << L"	███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗";
	gotoXY(col, row++);
	wcout << L"	╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║";
	gotoXY(col, row++);
	wcout << L"	███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝";
	gotoXY(col, row++);
	wcout << L"	╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝	";
	gotoXY(col, row++);
}