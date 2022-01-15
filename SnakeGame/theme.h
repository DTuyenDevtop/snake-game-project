#pragma once
#include <windows.h>          
#include <stdio.h>     

// Define color
#define BLACK 0
#define GREEN 2
#define BLUE 3
#define RED 4
#define VIOLET 5
#define BYELLOW 6
#define GRAY 7
#define WHITE 15

// Define console
#define WIDTH 1080
#define HEIGHT 680

const int BACKGROUND_COLOR = GRAY;

// Change the console color
void changeConsoleColor(int BackC);

// Lock resize console windows
void fixConsoleWindow();

// Resize the console with width and height
void resizeConsole(int width, int height);

// Change the text color
void textColor(int n);

// Move the cursor pointer the location (x, y)
void gotoXY(short x, short y);

// Draw border of the board
void drawBoard();