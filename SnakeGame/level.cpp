#include "level.h"
#include "screen.h"
#include "snake.h"
#include "graphic.h"

vector<function<void()>> level;

Screen gameDisplay;

void drawBorder() {
	gameDisplay.draw.retangle({ 2, 1 }, { 83, 42 }, GREEN, 2, colorXY);
	gameDisplay.draw.retangle({ 5, 2 }, { 63, 40 }, RED, 1, colorXY);
	gameDisplay.draw.retangle({ 134, 2 }, { 16, 40 }, RED, 1, colorXY);
}

void decorate(int index) {
	int x = 137;
	int y = 11;
	int ox = 1;
	int oy = 1;
	int plus = 5;
	gameDisplay.draw.retangle({ 135, 10 }, { 15, 0 }, RED, 1, colorXY);

	textColor(2);
	gotoXY(x + plus + 8, y);
	cout << "  _____    ";
	gotoXY(x + plus + 8, y + oy++);
	cout << " |_   _|   ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "   | |     ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "   | |   _ ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x + plus + 8, y + oy++);
	cout << " |________|";
	gotoXY(x + plus, y + oy++);
	cout << "  ________ ";
	gotoXY(x + plus, y + oy++);
	cout << " |_   __  |";
	gotoXY(x + plus, y + oy++);
	cout << "   | |_ \_|";
	gotoXY(x + plus, y + oy++);
	cout << "   |  _| _ ";
	gotoXY(x + plus, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x + plus, y + oy++);
	cout << " |________|";
	gotoXY(x, y + oy++);
	cout << " ____   ____ ";
	int tempx = x + 17 + 2;
	int tempy = y + oy -1;
	gotoXY(x , y + oy++);
	cout << "|_  _| |_  _|";
	gotoXY(x , y + oy++);
	wcout << "  \\ \\   / /  ";
	gotoXY(x , y + oy++);
	wcout << "   \\ \\ / /   ";
	gotoXY(x , y + oy++);
	cout << "    \\ ' /    ";
	gotoXY(x , y + oy++);
	cout << "     \\_/     ";
	gotoXY(x + plus, y + oy++);
	cout << "  ________ ";
	gotoXY(x + plus, y + oy++);
	cout << " |_   __  |";
	gotoXY(x + plus, y + oy++);
	cout << "   | |_ \\_|";
	gotoXY(x + plus, y + oy++);
	cout << "   |  _| _ ";
	gotoXY(x + plus, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x + plus, y + oy++);
	cout << " |________|";

	gotoXY(x + plus + 8, y + oy++);
	cout << "  _____    ";
	gotoXY(x + plus + 8, y + oy++);
	cout << " |_   _|   ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "   | |     ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "   | |   _ ";
	gotoXY(x + plus + 8, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x + plus + 8, y + oy++);
	cout << " |________|";

	textColor(3);
	gotoXY(x -1 , y++ +22);
	wcout << "   __";
	gotoXY(x - 1, y++ + 22);
	wcout << "  {0O}";
	gotoXY(x - 1, y++ + 22);
	wcout << "  \\__/";
	gotoXY(x - 1, y++ + 22);
	wcout << "  /^/";
	gotoXY(x - 1, y++ + 22);
	wcout << " ( (  ";
	gotoXY(x - 1, y++ + 22);
	wcout << " \\_\\_____";
	gotoXY(x - 1, y++ + 22);
	wcout << " (_______)";
	gotoXY(x - 1, y++ + 22);
	wcout << "(_________()Oo";


	gotoXY(x -1, y++ -8 );
	wcout << " ____";
	gotoXY(x -1, y++ - 8);
	wcout << "/ . .\\    ";
	gotoXY(x - 1, y++ - 8);
	wcout << "\\  ---<  ";
	gotoXY(x -1, y++ - 8);
	wcout << " \\  /  ";
	gotoXY(x -1 , y++ - 8);
	wcout << " / /________  ";
	gotoXY(x -1, y++ - 8);
	wcout << " \\_________:=-";

	/*gotoXY(x + plus, y + oy++);
	cout << "  ________ ";
	gotoXY(x + plus, y + oy++);
	cout << "  ________ ";*/
	/*for (int i = 135; i <= 142; ++i) {
		gotoXY(i, 24);
		cout << (char)(205);
		gotoXY(i, 32);
		cout << (char)(205);
	}
	for (int i = 20; i <= 26 ; ++i) {
		gotoXY(136, i);
		cout << (char)(186);
		gotoXY(145, i);
		cout << (char)(186);
	}*/
	int t = 13;
	if (index == 1) {
		textColor(t);
		gotoXY(tempx, tempy++);
		wcout << L"  __    ";
		gotoXY(tempx, tempy++);
		wcout << L" /' \\   ";
		gotoXY(tempx, tempy++);
		wcout << L" \" || ";
		gotoXY(tempx, tempy++);
		wcout << L"   ||   ";
		gotoXY(tempx, tempy++);
		wcout << L"   ||   ";
		gotoXY(tempx, tempy++);
		wcout << L"  _||_  ";
		gotoXY(tempx, tempy++);
		wcout << L" (_/\\_) ";

	}
	if (index == 2) {
		textColor(t);
		tempy++;
		tempx--;
		gotoXY(tempx, tempy++);
		wcout << L" (O)-.     ";
		gotoXY(tempx, tempy++);
		wcout << L"(_.-. \\    ";
		gotoXY(tempx, tempy++);
		wcout << L"     )/    ";
		gotoXY(tempx, tempy++);
		wcout << L"    //     ";
		gotoXY(tempx, tempy++);
		wcout << L"   /(____; ";
		gotoXY(tempx, tempy++);
		wcout << L"  (____.-' ";

	}
	if (index == 3) {
		textColor(t);
		gotoXY(tempx, tempy++);
		wcout << L"  wWw   ";
		gotoXY(tempx, tempy++);
		wcout << L" _(O)   ";
		gotoXY(tempx , tempy++);
		wcout << L"(__ \\   ";
		gotoXY(tempx , tempy++);
		wcout << L"   ) \\  ";
		gotoXY(tempx, tempy++);
		wcout << L"  (_  ) ";
		gotoXY(tempx, tempy++);
		wcout << L"  _/ /  ";
		gotoXY(tempx, tempy++);
		wcout << L" (__/   ";

	}
	if (index == 4) {
		textColor(t);
		gotoXY(tempx, tempy++);
		wcout << L"\\\\  //   ";
		gotoXY(tempx, tempy++);
		wcout << L"(o)(o)   ";
		gotoXY(tempx , tempy++);
		wcout << L"/ /\\ \\   ";
		gotoXY(tempx , tempy++);
		wcout << L"|(__)|   ";
		gotoXY(tempx, tempy++);
		wcout << L"\\___ |   ";
		gotoXY(tempx, tempy++);
		wcout << L"   | |_  ";
		gotoXY(tempx, tempy++);
		wcout << L"   \\___) ";
	}
	if (index == 5) {
		textColor(t);
		tempy++;
		gotoXY(tempx, tempy++);
		wcout << L"   oo_ ";
		gotoXY(tempx, tempy++);
		wcout << L" .' __)";
		gotoXY(tempx , tempy++);

		wcout << L" | |__ ";
		gotoXY(tempx , tempy++);
		wcout << L" |___ \\";
		gotoXY(tempx, tempy++);
		wcout << L" ____) )";
		gotoXY(tempx, tempy++);
		wcout << L"(_____/ ";

	}
	for (int i = 155; i <= 164; ++i) {
		gotoXY(i, 23);
		cout << (char)(205);
		gotoXY(i, 30);
		cout << (char)(205);
	}
	for (int i = 24; i <= 29; ++i) {
		gotoXY(154, i);
		cout << (char)(186);
		gotoXY(165, i);
		cout << (char)(186);
	}

	gotoXY(154, 23);
	cout << (char)(201);
	gotoXY(154, 30);
	cout << (char)(200);
	gotoXY(165, 23);
	cout << (char)(187);
	gotoXY(165, 30);
	cout << (char)(188);

}
void decorateBonus() {
	gameDisplay.draw.retangle({ 135, 10 }, { 15, 0 }, RED, 1, colorXY);
	textColor(6);
	int col1 = 137, row1 = 12;
	gotoXY(col1, row1++);
	wcout << L"██████ ";
	gotoXY(col1, row1++);
	wcout << L"██   ██";
	gotoXY(col1, row1++);
	wcout << L"██████ ";
	gotoXY(col1, row1++);
	wcout << L"██   ██";
	gotoXY(col1, row1++);
	wcout << L"██████ ";
	row1++;
	col1 = col1 + 5;
	gotoXY(col1, row1++);
	wcout << L" ██████ ";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L" ██████ ";
	row1++;
	col1 = col1 + 5;
	gotoXY(col1, row1++);
	wcout << L"███    ██";
	gotoXY(col1, row1++);
	wcout << L"████   ██";
	gotoXY(col1, row1++);
	wcout << L"██ ██  ██";
	gotoXY(col1, row1++);
	wcout << L"██  ██ ██";
	gotoXY(col1, row1++);
	wcout << L"██   ████";
	row1++;
	col1 = col1 + 5;
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L"██    ██";
	gotoXY(col1, row1++);
	wcout << L" ██████ ";
	row1++;
	col1 = col1 + 5;
	gotoXY(col1, row1++);
	wcout << L"███████ ";
	gotoXY(col1, row1++);
	wcout << L"██     ";
	gotoXY(col1, row1++);
	wcout << L"███████ ";
	gotoXY(col1, row1++);
	wcout << L"     ██ ";
	gotoXY(col1, row1++);
	wcout << L"███████ ";
	textColor(3);
	int x = 138;
	int y = 10;
	gotoXY(x - 1, y++ + 22);
	wcout << "   __";
	gotoXY(x - 1, y++ + 22);
	wcout << "  {0O}";
	gotoXY(x - 1, y++ + 22);
	wcout << "  \\__/";
	gotoXY(x - 1, y++ + 22);
	wcout << "  /^/";
	gotoXY(x - 1, y++ + 22);
	wcout << " ( (  ";
	gotoXY(x - 1, y++ + 22);
	wcout << " \\_\\_____";
	gotoXY(x - 1, y++ + 22);
	wcout << " (_______)";
	gotoXY(x - 1, y++ + 22);
	wcout << "(_________()Oo";
}

void level1() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	decorate(1);
	//drawInGate(7,6);
	drawOutGate(3,121,38);
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
	gameDisplay.draw.retangle({ 6, 22 }, { 12, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 45, 22 }, { 24, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 106, 22 }, { 12, 0 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 70, 2 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 70, 14 }, { 0, 16 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 70, 35 }, { 0, 7 }, BLACK, 2, colorXY);
	decorate(2);
	//drawInGate(7,6);
	drawOutGate(3,121,38);
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
	decorate(3);
	//drawInGate(7,6);
	drawOutGate(2,121,38);
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
	decorate(4);
	//drawInGate(7,6);
	drawOutGate(2,121,38);
}

void level5() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();

	gameDisplay.draw.retangle({ 120, 8 }, { 0, 12 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 90, 8 }, { 15, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 13, 24 }, { 0, 12 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 13, 36 }, { 15, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 57, 11 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 37, 18 }, { 10, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 57, 25 }, { 0, 8 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 37, 25 }, { 10, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 77, 11 }, { 0, 7 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 77, 18 }, { 10, 0 }, BLACK, 2, colorXY);

	gameDisplay.draw.retangle({ 77, 25 }, { 0, 8 }, BLACK, 2, colorXY);
	gameDisplay.draw.retangle({ 77, 25 }, { 10, 0 }, BLACK, 2, colorXY);
	decorate(5);
	//drawInGate(7,6);
	drawOutGate(1,121,38);
}

void randXY(Infomation& Food, const std::string label) {
	Food.x = 5 + rand() % (WidthGame - 5);
	Food.y = 5 + rand() % (HeightGame - 5);

	while (colorXY[Food.x][Food.y] == "DANGER") {
		srand((unsigned int)time(0));
		Food.x = 5 + rand() % (WidthGame - 5);
		Food.y = 5 + rand() % (HeightGame - 5);
	}
	colorXY[Food.x][Food.y] = label;
}

void bonusLevel() {
	decorateBonus();
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();	

	Infomation Food;
	for (int i = 0; i < 10; ++i) {
		randXY(Food, "FOOD_BINC");
		gotoXY(Food.x, Food.y);
		colorText(254, snakeColor);
	}

	for (int i = 0; i < 10; ++i) {
		randXY(Food, "FOOD_BST");
		gotoXY(Food.x, Food.y);
		colorText(254, BYELLOW);
	}

	//drawInGate(7,6);
	drawOutGate(3,121,38);
}

void initLevel() {
	level.push_back(level1);
	level.push_back(level2);
	level.push_back(level3);
	level.push_back(level4);
	level.push_back(level5);
	level.push_back(bonusLevel);
}

void drawInGate(int col, int row) {
	//int col = 7, row = 6;
	gotoXY(col, row);
	for (int i = 0; i < 9; i++) {
		if (i < 3 || i > 5) {
			colorXY[col + i][row] = "DANGER";
		}
	}
	cout << (char)205 << (char)202 << (char)205 << "   " << (char)205 << (char)202 << (char)205;
	col++; row--;
	gotoXY(col, row);
	colorXY[col][row] = "DANGER";
	colorXY[col + 6][row] = "DANGER";
	cout << (char)186 << "     " << (char)186;
	row--;

	gotoXY(col, row);
	for (int i = 0; i < 6; i++) {
		colorXY[col + i][row] = "DANGER";
	}
	cout << (char)201 << (char)205 << (char)205 << (char)79 << (char)205 << (char)205 << (char)187;
}

void drawOutGate(int width, int col, int row) {
	int x = 0;
	switch (width) {
		case 3:
			x = 0;
			break;
		case 2:
			x = 1;
			break;
		case 1:
			x = 2;
			break;
	}

	//int col = 121, row = 38;
	gotoXY(col, row);

	for (int i = 0; i < 9; i++) {
		if (i < 3 || i > 5 - x) {
			colorXY[col + i][row] = "DANGER";
		}
	}
	
	if (width == 3) {
		cout << (char)205 << (char)203 << (char)205 << "   " << (char)205 << (char)203 << (char)205;
	}
	else if(width == 2) {
		cout << (char)205 << (char)203 << (char)205 << "  " << (char)205 << (char)203 << (char)205;
	}
	else {
		cout << (char)205 << (char)203 << (char)205 << " " << (char)205 << (char)203 << (char)205;
	}
	
	col++; row++;
	gotoXY(col, row);
	colorXY[col][row] = "DANGER";
	colorXY[col + 5 - x][row] = "DANGER";
	
	if (width == 3) {
		cout << (char)186 << "     " << (char)186;
	} 
	else if (width == 2) {
		cout << (char)186 << "    " << (char)186;
	}
	else {
		cout << (char)186 << "   " << (char)186;
	}

	row++;
	gotoXY(col, row);
	colorXY[col][row] = "DANGER";
	colorXY[col + 6-x][row] = "DANGER";
	if (width == 3) {
		cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;
	}
	else if (width == 2) {
		cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;
	}
	else {
		cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)188;
	}
}

void deleteBorder()
{
	textColor(1);
	int col = 5, row = 2;
	for (int i = 0; i < 127; i++) {
		gotoXY(col + i, row);
		cout << (char)220;
		Sleep(1);
	}
	col = 131; row = 3;
	for (int i = 0; i < 39; i++) {
		gotoXY(col, row + i);
		cout << (char)219;
		Sleep(1);
	}
	row = 42; col = 131;
	for (int i = 0; i < 127; i++) {
		gotoXY(col - i, row);
		cout << (char)223;
		Sleep(1);
	}
	col = 5; row = 41;
	for (int i = 0; i < 39; i++) {
		gotoXY(col, row - i);
		cout << (char)219;
		Sleep(1);
	}
}

void moveNextLevel() {

}
