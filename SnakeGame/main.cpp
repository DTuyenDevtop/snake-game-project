#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "winmm.lib")

// Standard library
#include <thread>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>  
#include <mmsystem.h>
#include <winuser.h>

// Custom library
#include "graphic.h"
#include "screen.h"
#include "gameSound.h"
#include "menu.h"
#include "snake.h"

using namespace std;

Screen screen;
vector<Menu> listMenu;
bool stopShow = false;

void setup() {
    resizeConsole(WIDTH, HEIGHT);
    removeScrollbar();
    fixConsoleWindow();
    hideCursor();
    changeConsoleColor(BACKGROUND_COLOR);

    //playSoundLoop(L"resources/backgroundmusic.wav");

    screen.clear();
    screen.resetScreenColor(colorXY);
    screen.draw.retangle({ 2, 1 }, { 85, 42 }, GREEN, 2, colorXY);
    screen.draw.retangle({ 68, 20 }, { 20, 20 }, BYELLOW, 1, colorXY);
}

void showLogo() {
    while (!stopShow) {
        Sleep(500);
        textColor(VIOLET);
        snakeLogoLeft();
        Sleep(500);
        textColor(BYELLOW);
        snakeLogoRight();
    }
}

void mainMenu() {
    initMenu(listMenu);

    int dir = 0;
    bool checkChoose = false;

    thread logo(showLogo);
    HANDLE t1 = logo.native_handle();

    while (true) {
        textColor(BLUE);
        printMenu(listMenu);

        textColor(RED);
        gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
        cout << (char)175 << " " << listMenu[dir].data << " ";
        textColor(BLUE);
        hideCursor();
        moveSelect(listMenu, dir, checkChoose);

        if (checkChoose == true) {
            checkChoose = false;
            if (dir == 5) {
                exit(0);
            }
            else if (dir == 0) {
                SuspendThread(t1);
                system("cls");

                playGame();
                setup();
                ResumeThread(t1);
            }
            else if (dir == 1) {
                ResumeThread(t1);
            }
        }
    }
}

int main() {
    setup();
    mainMenu();

    return 0;
}