#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "winmm.lib")

// Standard library
#include <thread>
#include <map>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>  
#include <mmsystem.h>
#include <winuser.h>
#include <future>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

// Custom library
#include "graphic.h"
#include "screen.h"
#include "gameSound.h"
#include "menu.h"
#include "snake.h"

using namespace std;

Screen screen;
vector<Menu> listMenu;
Status Sound;
map<int, pair<int, string>> color;

void setup() {
    resizeConsole(WIDTH, HEIGHT);
    removeScrollbar();
    fixConsoleWindow();
    hideCursor();
    changeConsoleColor(BACKGROUND_COLOR);

    // Current OEM code page
    setlocale(LC_CTYPE, ".OCP"); // ref: https://xoax.net/cpp/ref/cstd/incl/clocale/fn/setlocale/

    color[0] = { 0, "BLACK" };
    color[1] = { 1, "BLUE" };
    color[2] = { 2, "GREEN" };
    color[3] = { 3, "CYAN" };
    color[4] = { 4, "RED" };
    color[5] = { 5, "VIOLET" };
    color[6] = { 6, "BROWN YELLOW" };

    screen.clear();
    screen.resetScreenColor(colorXY);
    screen.draw.retangle({ 2, 1 }, { 85, 42 }, GREEN, 2, colorXY);
}

void showLogo() {
    textColor(RED);
    int line = 2;
    int col = 55;
    gotoXY(col, line++);
    wcout << L"  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄    ▄  ▄▄▄▄▄▄▄▄▄▄▄   " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌▐░░░░░░░░░░░▌  " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌ ▐░▌ ▐░█▀▀▀▀▀▀▀▀▀   " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░▌          ▐░▌▐░▌    ▐░▌▐░▌       ▐░▌▐░▌▐░▌  ▐░▌            " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌░▌   ▐░█▄▄▄▄▄▄▄▄▄   " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░░░░░░░░░░░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░░▌    ▐░░░░░░░░░░░▌  " << endl;
    gotoXY(col, line++);
    wcout << L"  ▀▀▀▀▀▀▀▀▀█░▌▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌   ▐░█▀▀▀▀▀▀▀▀▀   " << endl;
    gotoXY(col, line++);
    wcout << L"           ▐░▌▐░▌    ▐░▌▐░▌▐░▌       ▐░▌▐░▌▐░▌  ▐░▌            " << endl;
    gotoXY(col, line++);
    wcout << L"  ▄▄▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░▌       ▐░▌▐░▌ ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄   " << endl;
    gotoXY(col, line++);
    wcout << L" ▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░▌       ▐░▌▐░▌  ▐░▌▐░░░░░░░░░░░▌  " << endl;
    gotoXY(col, line++);
    wcout << L"  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀         ▀  ▀    ▀  ▀▀▀▀▀▀▀▀▀▀▀   " << endl;
    gotoXY(col, line++);
}

void mainMenu() {
    playSoundLoop(L"resources/backgroundmusic.wav"), Sound = Status::ON;
    initMenu(listMenu);
    int dir = 0;
    bool checkChoose = false;
    snakeColor = RED;

    map<int, pair<int, string>>::iterator it;
    it = color.begin();

    bool firstTime = true;

    while (true) {
        if (!firstTime) {
            for (int i = 40; i >= 15; --i) {
                gotoXY(5, i);
                textFillColor(BACKGROUND_COLOR, BACKGROUND_COLOR);
                cout << "                                                                                                                                         ";
                Sleep(10);
            }
        }
        firstTime = false;

        screen.draw.retangle({ 68, 20 }, { 20, 20 }, BYELLOW, 1, colorXY);
        showLogo();
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
            if (dir == 0) {
                system("cls");
                playGame();
                
                setup();
            }
            else if (dir == 1) {
                // pass
            }
            else if (dir == 2) {
                //pass
            }
            else if (dir == 4) {
                setting();
                gotoXY(60, 23);
                cout << "Press ESC to exit and press enter to change value";

                int choice = 0;
                bool check = false;

                while (true) {
                    vector<Menu> listSetting;
                    Menu items;

                    items.x = 85;
                    items.y = 25;

                    if (Sound == Status::OFF) {
                        items.data = "MUSIC: OFF";
                    }
                    else {
                        items.data = "MUSIC: ON";
                    }
                    listSetting.push_back(items);

                    items.x = 85;
                    items.y = 27;
                    items.data = "SNAKE COLOR: ";
                    items.data += color[snakeColor].second + "          ";
                    listSetting.push_back(items);

                    textFillColor(WHITE, BLUE);

                    printMenu(listSetting);

                    textFillColor(RED, BLUE);
                    gotoXY(listSetting[choice].x - 3, listSetting[choice].y);
                    cout << (char)175 << " " << listSetting[choice].data << " ";
                    textFillColor(WHITE, BLUE);

                    moveSelectSetting(listSetting, choice, check);
                    
                    if (choice == -1) {
                        break;
                    }

                    if (check == true) {
                        check = false;
               
                        if (choice == 0) {
                            if (Sound == Status::ON) {
                                turnOffSound();
                                listSetting[choice].data = "MUSIC: OFF";
                                Sound = Status::OFF;
                            }
                            else {
                                playSoundLoop(L"resources/backgroundmusic.wav");
                                listSetting[choice].data = "MUSIC: ON";
                                Sound = Status::ON;

                            }
                        } 
                        else if (choice == 1) {
                            if (it != --color.end()) {
                                it++;
                            }
                            else {
                                it = color.begin();
                            }
                            snakeColor = it->second.first;
                            listSetting[choice].data = "SNAKE COLOR: " + it->second.second + "           ";
                        }
                    }
                }
            }
            else if (dir == 6) {
                exit(0);
            }
        }
    }
}

int main() {
    setup();
    mainMenu();
    return 0;
}