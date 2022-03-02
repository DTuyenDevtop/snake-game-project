#include "level.h"
#include "screen.h"

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
	textColor(1);
	gotoXY(x, y);
	cout << "  _____    ";
	gotoXY(x, y + oy++);
	cout << " |_   _|   ";
	gotoXY(x, y + oy++);
	cout << "   | |     ";
	gotoXY(x, y + oy++);
	cout << "   | |   _ ";
	gotoXY(x, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x, y + oy++);
	cout << " |________|";
	gotoXY(x, y + oy++);
	cout << "  ________ ";
	gotoXY(x, y + oy++);
	cout << " |_   __  |";
	gotoXY(x, y + oy++);
	cout << "   | |_ \_|";
	gotoXY(x, y + oy++);
	cout << "   |  _| _ ";
	gotoXY(x, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x, y + oy++);
	cout << " |________|";
	gotoXY(x, y + oy++);
	cout << " ____   ____ ";
	int tempx = x+ 16;
	int tempy = y + oy -1;
	gotoXY(x, y + oy++);
	cout << "|_  _| |_  _|";
	gotoXY(x, y + oy++);
	wcout << "  \\ \\   / /  ";
	gotoXY(x, y + oy++);
	wcout << "   \\ \\ / /   ";
	gotoXY(x, y + oy++);
	cout << "    \\ ' /    ";
	gotoXY(x, y + oy++);
	cout << "     \\_/     ";
	gotoXY(x, y + oy++);
	cout << "  ________ ";
	gotoXY(x, y + oy++);
	cout << " |_   __  |";
	gotoXY(x, y + oy++);
	cout << "   | |_ \_|";
	gotoXY(x, y + oy++);
	cout << "   |  _| _ ";
	gotoXY(x, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x, y + oy++);
	cout << " |________|";

	gotoXY(x, y + oy++);
	cout << "  _____    ";
	gotoXY(x, y + oy++);
	cout << " |_   _|   ";
	gotoXY(x, y + oy++);
	cout << "   | |     ";
	gotoXY(x, y + oy++);
	cout << "   | |   _ ";
	gotoXY(x, y + oy++);
	cout << "  _| |__/ |";
	gotoXY(x, y + oy++);
	cout << " |________|";
	if (index == 1) {
		textColor(RED);
		gotoXY(tempx, tempy++);
		wcout << L"    __    ";
		gotoXY(tempx, tempy++);
		wcout << L"   /' \   ";
		gotoXY(tempx, tempy++);
		wcout << L"   \" || ";
		gotoXY(tempx, tempy++);
		wcout << L"     ||   ";
		gotoXY(tempx, tempy++);
		wcout << L"     ||   ";
		gotoXY(tempx, tempy++);
		wcout << L"    _||_  ";
		gotoXY(tempx, tempy++);
		wcout << L"   (_/\_) ";

	}
	if (index == 2) {
		textColor(RED);
		gotoXY(tempx, tempy++);
		wcout << L" (O)-.     ";
		gotoXY(tempx, tempy++);
		wcout << L"(_.-. \    ";
		gotoXY(tempx - 1, tempy++);
		wcout << L"     )/    ";
		gotoXY(tempx - 2, tempy++);
		wcout << L"    //     ";
		gotoXY(tempx, tempy++);
		wcout << L"   /(____; ";
		gotoXY(tempx, tempy++);
		wcout << L"  (____.-' ";

	}
	if (index == 3) {
		textColor(RED);
		gotoXY(tempx, tempy++);
		wcout << L"    wWw   ";
		gotoXY(tempx, tempy++);
		wcout << L"   _(O)   ";
		gotoXY(tempx , tempy++);
		wcout << L"  (__ \\   ";
		gotoXY(tempx , tempy++);
		wcout << L"     ) \\  ";
		gotoXY(tempx, tempy++);
		wcout << L"    (_  ) ";
		gotoXY(tempx, tempy++);
		wcout << L"    _/ /  ";
		gotoXY(tempx, tempy++);
		wcout << L"   (__/   ";

	}
	if (index == 4) {
		textColor(RED);
		gotoXY(tempx, tempy++);
		wcout << L"  \\\\  //   ";
		gotoXY(tempx, tempy++);
		wcout << L"  (o)(o)   ";
		gotoXY(tempx , tempy++);
		wcout << L"  / /\\ \\   ";
		gotoXY(tempx , tempy++);
		wcout << L"  |(__)|   ";
		gotoXY(tempx, tempy++);
		wcout << L"  \\___ |   ";
		gotoXY(tempx, tempy++);
		wcout << L"     | |_  ";
		gotoXY(tempx, tempy++);
		wcout << L"     \\___) ";
	}
	if (index == 5) {
		textColor(RED);
		gotoXY(tempx, tempy++);
		wcout << L"     oo_   ";
		gotoXY(tempx, tempy++);
		wcout << L"   .' __)  ";
		gotoXY(tempx - 1, tempy++);

		wcout << L"   | |__   ";
		gotoXY(tempx - 2, tempy++);
		wcout << L"   |___ \\  ";
		gotoXY(tempx, tempy++);
		wcout << L"   ____) ) ";
		gotoXY(tempx, tempy++);
		wcout << L"  (_____/  ";

	}
}

void level1() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
	decorate(5);
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
	decorate(2);
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
}

void bonusLevel() {
	gameDisplay.resetScreenColor(colorXY);
	drawBorder();
}

void initLevel() {
	level.push_back(level1);
	level.push_back(level2);
	level.push_back(level3);
	level.push_back(level4);
	level.push_back(level5);
	level.push_back(bonusLevel);
}

void moveNextLevel() {

}