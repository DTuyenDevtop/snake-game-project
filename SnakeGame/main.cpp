#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "winmm.lib")

// Standard library
#include <thread>
#include <map>
#include <string>
#include <iostream>
#include <conio.h>
#include <iostream>
#include <windows.h>  
#include <mmsystem.h>
#include <winuser.h>
#include <future>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <fstream>
#include <ctime>

// Custom library
#include "graphic.h"
#include "screen.h"
#include "gameSound.h"
#include "menu.h"
#include "snake.h"

using namespace std;

Screen screen;
Status Sound;

vector<Menu> listMenu;
extern vector<Player> savePlayers;
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
    screen.draw.retangle({ 2, 1 }, { 83, 42 }, GREEN, 2, colorXY);
    screen.draw.retangle({ 68, 20 }, { 20, 20 }, BYELLOW, 1, colorXY);
}

void mainMenu() {
    playSoundLoop(L"resources/backgroundmusic.wav"), Sound = Status::ON;
    bool stopShow = true;
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

        showLogo();
        screen.draw.retangle({ 68, 20 }, { 20, 20 }, BYELLOW, 1, colorXY);
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
                string name;
                string dateAndTime;
                fillName(name);
                system("cls");
                playGame(name, dateAndTime);
                
                setup();
            }
            else if (dir == 1) {
                // pass
            }
            else if (dir == 2) {
                loadFileScore(savePlayers);
                highScore(savePlayers, screen);
                while (true) {
                    if (_kbhit()) {
                        int key = _getch();
                        if (key == 27) {
                            break;
                        }
                    }
                }
            }
            else if (dir == 3) {
                guide();
                while (true) {
                    if (_kbhit()) {
                        int key = _getch();
                        if (key == 27) {
                            break;
                        }
                    }
                }
            }
            else if (dir == 4) {
                setting();

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

                    textFillColor(WHITE, BLACK);

                    printMenu(listSetting);

                    textFillColor(RED, BLACK);
                    gotoXY(listSetting[choice].x - 3, listSetting[choice].y);
                    cout << (char)175 << " " << listSetting[choice].data << " ";
                    textFillColor(WHITE, BLACK);

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
            else if (dir == 5) {    
                ourTeam();

                while (true) {
                    if (_kbhit()) {
                        int key = _getch();
                        if (key == 27) {
                            break;
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