#pragma once
#include "menu.h"
#include "screen.h"
#include "graphic.h"
#include <fstream>
#include <string>
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
				textFillColor(RED, BLACK);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLACK);
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

				textFillColor(RED, BLACK);
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLACK);
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

void blackBoard() {
	textFillColor(BLUE, BLACK);
	for (int j = 15; j <= 40; ++j) {
		gotoXY(20, j);
		cout << "                                                                                                                                        ";
		Sleep(8);
	}

	textFillColor(WHITE, BLACK);
	for (int i = 20; i <= 155; ++i) {
		gotoXY(i, 15);
		cout << (char)(205);
		gotoXY(i, 40);
		cout << (char)(205);
	}

	for (int i = 15; i <= 40; ++i) {
		gotoXY(20, i);
		cout << (char)(186);
		gotoXY(155, i);
		cout << (char)(186);
	}

	gotoXY(20, 15);
	cout << (char)(201);

	gotoXY(20, 40);
	cout << (char)(200);

	gotoXY(155, 15);
	cout << (char)(187);

	gotoXY(155, 40);
	cout << (char)(188);
}

void setting() {
	blackBoard();

	int row = 16, col = 60;

	textFillColor(BYELLOW, BLACK);
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

	int row5 = 33, col5 = 43;
	gotoXY(col5, row5++);
	textFillColor(GRAY, 64);
	cout << "                                                                                       ____";
	gotoXY(col5, row5++);
	textFillColor(VIOLET, 64);
	cout << "                                                                                      / . .\\";
	gotoXY(col5, row5++);
	textFillColor(BLUE, 64);
	cout << "                                                                                      \\   -----<";
	gotoXY(col5, row5++);
	textFillColor(GREEN, 64);
	cout << "                                                                                       \\  /";
	gotoXY(col5, row5++);
	textFillColor(BYELLOW, 64);
	cout << "   ____________________________________________________________________________________/ /";
	gotoXY(col5, row5++);
	textFillColor(RED, 64);
	cout << "-=:_____________________________________________________________________________________/";

	textFillColor(WHITE, 64);

	// Exit
	int row6 = 39, col6 = 43;
	gotoXY(col6, row6++);
	cout << "Press ESC to exit. Press enter to change value.";
}

void ourTeam() {
	blackBoard();

	// Ourteam logo
	//int row = 16, col = 70;
	//textFillColor(GRAY, 64);
	//gotoXY(col, row++);
	//cout << "   ____               _______                  ";
	//gotoXY(col, row++);
	//cout << "  / __ \\             |__   __|                  ";
	//gotoXY(col, row++);
	//cout << " | |  | |_   _ _ __     | | ___  __ _ _ __ ___  ";
	//gotoXY(col, row++);
	//cout << " | |  | | | | | '__|    | |/ _ \\/ _` | '_ ` _ \\ ";
	//gotoXY(col, row++);
	//cout << " | |__| | |_| | |       | |  __/ (_| | | | | | |";
	//gotoXY(col, row++);
	//cout << "  \\____/ \\__,_|_|       |_|\\___|\\__,_|_| |_| |_|";

	//textFillColor(WHITE, 64);

	// Ourteam logo
	int row = 16, col = 60;
	textFillColor(RED, 64);
	gotoXY(col, row++);
	wcout << L" ██████╗ ██╗   ██╗██████╗     ████████╗███████╗ █████╗ ███╗   ███╗";
	gotoXY(col, row++);
	wcout << L"██╔═══██╗██║   ██║██╔══██╗    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██████╔╝       ██║   █████╗  ███████║██╔████╔██║";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██╔══██╗       ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║";
	gotoXY(col, row++);
	wcout << L"╚██████╔╝╚██████╔╝██║  ██║       ██║   ███████╗██║  ██║██║ ╚═╝ ██║";
	gotoXY(col, row++);
	wcout << L" ╚═════╝  ╚═════╝ ╚═╝  ╚═╝       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝";
	
	// Team 8 border
	textFillColor(BLUE, 64);
	for (int i = 43; i <= 79; ++i) {
		gotoXY(i, 24);
		cout << (char)(205);
		gotoXY(i, 32);
		cout << (char)(205);
	}
	for (int i = 24; i <= 32; ++i) {
		gotoXY(43, i);
		cout << (char)(186);
		gotoXY(79, i);
		cout << (char)(186);
	}

	gotoXY(43, 24);
	cout << (char)(201);
	gotoXY(43, 32);
	cout << (char)(200);
	gotoXY(79, 24);
	cout << (char)(187);
	gotoXY(79, 32);
	cout << (char)(188);

	textFillColor(WHITE, 64);

	// Teamm 8 logo
	int row1 = 22, col1 = 46;
	textFillColor(BLUE, 64);

	gotoXY(col1, row1++);
	cout << "  _____ ___   _   __  __   ___ ";
	gotoXY(col1, row1++);
	cout << " |_   _| __| /_\\ |  \\/  | ( _ )";
	gotoXY(col1, row1++);
	cout << "   | | | _| / _ \\| |\\/| | / _ \\";
	gotoXY(col1, row1++);
	cout << "   |_| |___/_/ \\_\\_|  |_| \\___/";

	textFillColor(WHITE, 64);
	
	// Team member
	int row2 = 27, col2 = 45;

	gotoXY(col2, row2++);
	textFillColor(RED, 64);
	cout << "Phan Thanh An       - 21127003";

	gotoXY(col2, row2++);
	textFillColor(BYELLOW, 64);
	cout << "Nguyen Nhat Nam     - 21127648";

	gotoXY(col2, row2++);
	textFillColor(CYAN, 64);
	cout << "Vo Nguyen Hoang Kim - 21127090";

	gotoXY(col2, row2++);
	textFillColor(GREEN, 64);
	cout << "Luu Hoang Bach      - 21127493";

	textFillColor(WHITE, 64);

	// Instructor border
	textFillColor(BLUE, 64);
	for (int i = 81; i <= 138; ++i) {
		gotoXY(i, 24);
		cout << (char)(205);
		gotoXY(i, 29);
		cout << (char)(205);
	}

	for (int i = 24; i <= 29; ++i) {
		gotoXY(81, i);
		cout << (char)(186);
		gotoXY(138, i);
		cout << (char)(186);
	}

	gotoXY(81, 24);
	cout << (char)(201);
	gotoXY(81, 29);
	cout << (char)(200);
	gotoXY(138, 24);
	cout << (char)(187);
	gotoXY(138, 29);
	cout << (char)(188);

	textFillColor(WHITE, 64);

	// Instructor logo
	int row3 = 22, col3 = 84;
	textFillColor(BLUE, 64);
	gotoXY(col3, row3++);
	cout << "  ___ _  _ ___ _____ ___ _   _  ___ _____ ___  ___ ";
	gotoXY(col3, row3++);
	cout << " |_ _| \\| / __|_   _| _ \\ | | |/ __|_   _/ _ \\| _ \\";
	gotoXY(col3, row3++);
	cout << "  | || .` \\__ \\ | | |   / |_| | (__  | || (_) |   /";
	gotoXY(col3, row3++);
	cout << " |___|_|\\_|___/ |_| |_|_\\\\___/ \\___| |_| \\___/|_|_\\";
	
	textFillColor(WHITE, 64);

	// Instructor information
	int row4 = 27, col4 = 83;

	gotoXY(col4, row4++);
	textFillColor(VIOLET, 64);
	cout << "Dr.Truong Toan Thinh - Teacher";
	
	textFillColor(WHITE, 64);	

	// Snake image
	/*int flag = 0;
	while (flag == 0) {
		Sleep(100);
		textFillColor(RED, 64);
		snakeImage();
		Sleep(100);
		textFillColor(VIOLET, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(BLUE, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(GREEN, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(BYELLOW, 64);
		snakeImage();
		Sleep(100);
		textFillColor(WHITE, 64);
		snakeImage();
	}*/

	// Snake image
	int row5 = 33, col5 = 41;
	gotoXY(col5, row5++);
	textFillColor(GRAY, 64);
	cout << "                           __    __    __    __    __    __    __    __    __    __ ";
	gotoXY(col5, row5++);
	textFillColor(VIOLET, 64);
	cout << "                          /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\";
	gotoXY(col5, row5++);
	textFillColor(BLUE, 64);
	cout << " ________________________/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\______________";
	gotoXY(col5, row5++);
	textFillColor(GREEN, 64);
	cout << " _______________________/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /_________________";
	gotoXY(col5, row5++);
	textFillColor(BYELLOW, 64);
	cout << "                       /  / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\  \\____";
	gotoXY(col5, row5++);
	textFillColor(RED, 64);
	cout << "                      / /    \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\    o \\";
	gotoXY(col5, row5++);
	cout << "                     //                                                             \\_____/--<";
	textFillColor(WHITE, 64);

	// Exit
	int row6 = 39, col6 = 43;
	gotoXY(col6, row6++);
	cout << "Press ESC to exit.";
}

void guide() {
	blackBoard();

	/*int row = 16, col = 70;
	gotoXY(col, row++);
	cout << "   _____ _    _ _____ _____  ______ ";
	gotoXY(col, row++);
	cout << "  / ____| |  | |_   _|  __  \|  ____|";
	gotoXY(col, row++);
	cout << " | |  __| |  | | | | | |  | | |__   ";
	gotoXY(col, row++);
	cout << " | | |_ | |  | | | | | |  | |  __|  ";
	gotoXY(col, row++);
	cout << " | |__| | |__| |_| |_| |__| | |____ ";
	gotoXY(col, row++);
	cout << "  \\_____|\\____/|_____|_____/|______|";*/

	int row = 16, col = 75;
	textFillColor(CYAN, BLACK);
	gotoXY(col, row++);
	wcout << L" ██████╗ ██╗   ██╗██╗██████╗ ███████╗";
	gotoXY(col, row++);
	wcout << L"██╔════╝ ██║   ██║██║██╔══██╗██╔════╝";
	gotoXY(col, row++);
	wcout << L"██║  ███╗██║   ██║██║██║  ██║█████╗ ";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██║██║  ██║██╔══╝ ";
	gotoXY(col, row++);
	wcout << L"╚██████╔╝╚██████╔╝██║██████╔╝███████╗";

	textFillColor(WHITE, 64);
	gotoXY(50, 23);
	cout << "Read me first !!";
	gotoXY(50, 25);
	cout << "You will be a snake finding food to prolong your length.";
	gotoXY(50, 26);
	cout << "              ___";
	gotoXY(50, 27);
	cout << "             | W |";
	gotoXY(50, 28);
	cout << "          ___|___|___  ";
	gotoXY(50, 29);
	cout << "Pressing | A | S | D | to control the direction of the snake. ";
	gotoXY(50, 30);
	cout << "         |___|___|___|";
	
	gotoXY(50, 32);
//	textFillColor(RED, 64);
	cout << "Be carefull!";
	textFillColor(WHITE, 64);
	gotoXY(50, 34);
	cout << "You have to cope with barricades and walls in each level.";
	gotoXY(50, 36);
	cout<<"If you hit one of them, the snake will die.";
	gotoXY(50, 38);
	cout << "Good luck!";
	gotoXY(120, 39);
	cout << "Press ESC to exit.";
		
}

void swap(Player& a, Player& b) {
	Player temp;
	temp = a;
	a = b;
	b = temp;	
}

void loadFileScore(vector<Player> &savePlayers) {
	ifstream filein;
	filein.open("saveScore.txt", ios::in);
	if (filein.fail() == true) {
		cout << "File cannot be found";
	}
	else {
		savePlayers.clear();
		Player x;
		while (!filein.eof()) {
			filein >> x.score;
			filein.ignore();
			getline(filein, x.name);
			getline(filein, x.dateAndTime);
			savePlayers.push_back(x);
		}
	}
}

void highScore(vector<Player>& savePlayers, Screen screen) {
	blackBoard();

	int colHS = 49;
	int rowHS = 17;
	textFillColor(14, BLACK);
	gotoXY(colHS, rowHS++);
	wcout << L"	██╗  ██╗██╗ ██████╗ ██╗  ██╗    ███████╗ ██████╗ ██████╗ ██████╗ ███████╗";
	gotoXY(colHS, rowHS++);
	wcout << L"	██║  ██║██║██╔════╝ ██║  ██║    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝";
	gotoXY(colHS, rowHS++);
	wcout << L"	███████║██║██║  ███╗███████║    ███████╗██║     ██║   ██║██████╔╝█████╗  ";
	gotoXY(colHS, rowHS++);
	wcout << L"	██╔══██║██║██║   ██║██╔══██║    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝  ";
	gotoXY(colHS, rowHS++);
	wcout << L"	██║  ██║██║╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗";
	gotoXY(colHS, rowHS++);
	wcout << L"	╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝";
	
	textFillColor(14, BLACK);
	int a = 118;
	int b = 24;
	gotoXY(a, b++);
	wcout << L"  █████████████████  ";
	gotoXY(a, b++);
	wcout << L" ███████████████████ ";
	gotoXY(a, b++);
	wcout << L"██ ███████████████ ██";
	gotoXY(a, b++);
	wcout << L" ███████████████████ ";
	gotoXY(a, b++);
	wcout << L"  █████████████████  ";
	gotoXY(a, b++);
	wcout << L"   ███████████████   ";
	gotoXY(a, b++);
	wcout << L"     █  ██████  █    ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"       ███████      ";
	gotoXY(a, b++);
	wcout << L"      █████████      ";
	gotoXY(a, b++);
	wcout << L"     ███████████      ";
	gotoXY(a, b++);
	wcout << L"     ███████████      ";
	gotoXY(a, b++);
	wcout << L"     ███████████      ";

	//High score border
	//screen.draw.retangle({ 44, 23 }, { 36, 16 }, 3, 1, colorXY);
	textFillColor(3,BLACK);
	for (int i = 43; i <= 115; i++) {
		gotoXY(i, 23);
		cout << (char)220;
		gotoXY(i, 38);
		cout << (char)223;
		if (i != 43 && i != 53 && i != 65 && i != 86) {
			gotoXY(i, 27);
			cout << (char)223;
		}
		 
	}
	textFillColor(GRAY, BLACK);
	for (int i = 43; i <= 115; i++) {
		gotoXY(i, 27);
		cout << (char)223;
	}
	textFillColor(3, BLACK);
	gotoXY(43, 27);
	cout << char(221);
	for (int i = 24; i <= 37; i++) {
		gotoXY(43, i);
		cout << (char)219;
		gotoXY(53, i);
		cout << (char)219;
		gotoXY(65, i);
		cout << (char)219;
		gotoXY(86, i);
		cout << (char)219;
		gotoXY(115, i);
		cout << (char)219;
	}

	//screen.draw.retangle({ 52, 24 }, { 0, 14 }, 3, 1, colorXY);
	//screen.draw.retangle({ 44, 27 }, { 36, 0 }, 3, 1, colorXY);
	//screen.draw.retangle({ 65, 24 }, { 0, 14 }, 3, 1, colorXY);
	//screen.draw.retangle({ 86, 24 }, { 0, 14 }, 3, 1, colorXY);
	gotoXY(46, 25);
	textFillColor(11, BLACK);
	cout << "RANK";
	gotoXY(57, 25);
	cout << "SCORE";
	gotoXY(74, 25);
	cout << "NAME";
	gotoXY(100, 25);
	cout << "DATE";

	//Sort function
	for (int i = 0; i < savePlayers.size() - 1; i++) {
		for (int j = i + 1 ; j < savePlayers.size(); j++) {
			if (savePlayers[i].score < savePlayers[j].score) {
				swap(savePlayers[i], savePlayers[j]);
			}
		}
	}
	gotoXY(0, 0);
	cout << savePlayers.size();
	//textColor(WHITE);
	
	textFillColor(14, BLACK);
	for (int i = 0; i < savePlayers.size(); i++) {
		if (i >= 10) break;
		gotoXY(48, i + 28);
		cout << i + 1;
		gotoXY(58, i + 28);
		cout << savePlayers[i].score << endl;
		gotoXY(70, i + 28);
		cout << savePlayers[i].name << endl;
		gotoXY(89, i + 28);
		cout << savePlayers[i].dateAndTime << endl;
	}
	
}
void fillName(string &name) {
	system("cls");
	int t = 25;
	Sleep(t);
	textFillColor(3, 7);
	int col1 = 50, row1 = 18;
	gotoXY(col1, row1++);
	wcout << L"██    ██  ██████  ██    ██ ██████      ███    ██  █████  ███    ███ ███████ ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L" ██  ██  ██    ██ ██    ██ ██   ██     ████   ██ ██   ██ ████  ████ ██      ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"  ████   ██    ██ ██    ██ ██████      ██ ██  ██ ███████ ██ ████ ██ █████   ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"   ██    ██    ██ ██    ██ ██   ██     ██  ██ ██ ██   ██ ██  ██  ██ ██      ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"   ██     ██████   ██████  ██   ██     ██   ████ ██   ██ ██      ██ ███████ ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"                                                                            ";
	Sleep(t);
	gotoXY(col1+15, row1++);
	textColor(3);
	cout << "Please fill in your name in the blanks below. ";
	Screen nameScreen;
	nameScreen.draw.retangle({ 30, 12 }, { 60, 25 }, 12, 1, colorXY);
	Sleep(t);
	nameScreen.draw.retangle({ 66, 27 }, { 20, 4 }, 3, 2, colorXY);
	Sleep(t);
	nameScreen.draw.retangle({ 65, 26 }, { 21, 6 }, 3, 1, colorXY);
	Sleep(t);
	gotoXY(78, 29);
	cin >> name;
}
int loseGame() {
	system("cls");
	int t = 25;
	Sleep(t);
	textFillColor(3, 7);
	int col1 = 42, row1 = 18;
	gotoXY(col1, row1++);
	wcout << L"██    ██  ██████  ██    ██      █████  ██████  ███████     ██       ██████  ███████ ███████ ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L" ██  ██  ██    ██ ██    ██     ██   ██ ██   ██ ██          ██      ██    ██ ██      ██      ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"  ████   ██    ██ ██    ██     ███████ ██████  █████       ██      ██    ██ ███████ █████   ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"   ██    ██    ██ ██    ██     ██   ██ ██   ██ ██          ██      ██    ██      ██ ██      ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"   ██     ██████   ██████      ██   ██ ██   ██ ███████     ███████  ██████  ███████ ███████ ";
	Sleep(t);
	gotoXY(col1, row1++);
	wcout << L"                                                                            ";
	Sleep(t);
	gotoXY(col1 + 20, row1+3);
	textColor(3);
	cout << "Do you want to continue playing ? ";
	char c;
	cin >> c;
	//This line for using getch
	Screen nameScreen;
	nameScreen.draw.retangle({ 30, 12 }, { 60, 25 }, 12, 1, colorXY);
	Sleep(t);
	nameScreen.draw.retangle({ 66, 27 }, { 20, 4 }, 3, 2, colorXY);
	Sleep(t);
	nameScreen.draw.retangle({ 65, 26 }, { 21, 6 }, 3, 1, colorXY);
	Sleep(t);
	return 1;
}

void pauseGame() {
	//Black board
	textFillColor(BLUE, BLACK);
	for (int j = 16; j <= 29; ++j) {
		gotoXY(27, j);
		cout << "                                                                                    ";
		Sleep(8);
	}

	//Horizontal border
	textFillColor(WHITE, BLACK);
	for (int i = 27; i <= 110; ++i) {
		gotoXY(i, 16);
		cout << (char)(205);
		gotoXY(i, 29);
		cout << (char)(205);
	}

	//Veritcal border
	for (int i = 17; i <= 28; ++i) {
		gotoXY(26, i);
		cout << (char)(186);
		gotoXY(110, i);
		cout << (char)(186);
	}

	gotoXY(26, 16); // Top right
	cout << (char)(201);

	gotoXY(26, 29); // Bottom right
	cout << (char)(200);

	gotoXY(110, 16); // Top left
	cout << (char)(187);

	gotoXY(110, 29); // Bottom left
	cout << (char)(188);

	//Graphic
	textFillColor(3, 64);
	int col1 = 29, row1 = 19;
	gotoXY(col1, row1++);
	wcout << L"██████   █████  ██    ██ ███████ ███████     ██████   █████  ███    ███ ███████ ";
	gotoXY(col1, row1++);
	wcout << L"██   ██ ██   ██ ██    ██ ██      ██         ██       ██   ██ ████  ████ ██      ";
	gotoXY(col1, row1++);
	wcout << L"██████  ███████ ██    ██ ███████ █████      ██   ███ ███████ ██ ████ ██ █████   ";
	gotoXY(col1, row1++);
	wcout << L"██      ██   ██ ██    ██      ██ ██         ██    ██ ██   ██ ██  ██  ██ ██      ";
	gotoXY(col1, row1++);
	wcout << L"██      ██   ██  ██████  ███████ ███████     ██████  ██   ██ ██      ██ ███████ ";

	//Text
	gotoXY(col1 + 22, row1 + 2);
	textFillColor(WHITE, BLACK);
	cout << "Press spacebar again to continue";
	textColor(snakeColor);
}