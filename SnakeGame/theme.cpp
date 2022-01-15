#pragma once
#include "theme.h"          

void fixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void gotoXY(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void changeConsoleColor(int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleTextAttribute(hStdOut, wColor);

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

        SetConsoleCursorPosition(hStdOut, coord);
    }
}

void textColor(int colorCode) {
    int BackC = BACKGROUND_COLOR;
    int ForgC = colorCode;
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleTextAttribute(hStdOut, wColor);
}

void drawBoard() {
    system("cls");
    textColor(GREEN);
    
    for (int i = 3; i <= 141; ++i) {
        gotoXY(i, 1);
        printf("%c", 219);

        gotoXY(i, 37);
        printf("%c", 219);
    }

    for (int i = 2; i <= 37; ++i) {
        gotoXY(3, i);
        printf("%c%c", 219, 219);

        gotoXY(140, i);
        printf("%c%c", 219, 219);
    }
}
