#pragma once
#include "graphic.h"   

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

    SetConsoleTextAttribute(hStdOut, wColor);
}

void removeScrollbar() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void colorText(std::string Text, int Color) {
    textColor(RED);
    std::cout << Text;
    textColor(RED);
}

void colorText(char Text, int Color) {
    textColor(RED);
    std::cout << Text;
    textColor(RED);
}


void snakeLogoRight() {
    int line = 2;
    int col = 53;
    gotoXY(col, line++);
    std::cout << "      ___           ___           ___           ___           ___      ";
    gotoXY(col, line++);
    std::cout << "     /  /\\         /  /\\         /  /\\         /  /\\         /  /\\     ";
    gotoXY(col, line++);
    std::cout << "    /  /::\\       /  /::|       /  /::\\       /  /:/        /  /::\\   ";
    gotoXY(col, line++);
    std::cout << "   /__/:/\\:\\     /  /:|:|      /  /:/\\:\\     /  /:/        /  /:/\\:\\  ";
    gotoXY(col, line++);
    std::cout << "  _\\_ \\:\\ \\:\\   /  /:/|:|__   /  /::\\ \\:\\   /  /::\\____   /  /::\\ \\:\\ ";
    gotoXY(col, line++);
    std::cout << " /__/\\ \\:\\ \\:\\ /__/:/ |:| /\\ /__/:/\\:\\_\\:\\ /__/:/\\:::::\\ /__/:/\\:\\ \\:\\ ";
    gotoXY(col, line++);
    std::cout << " \\  \\:\\ \\:\\_\\/ \\__\\/  |:|/:/ \\__\\/  \\:\\/:/ \\__\\/~|:|~~~~ \\  \\:\\ \\:\\_\\/ ";
    gotoXY(col, line++);
    std::cout << "  \\  \\:\\_\\:\\       |  |:/:/       \\__\\::/     |  |:|      \\  \\:\\ \\:\\  ";
    gotoXY(col, line++);
    std::cout << "   \\  \\:\\/:/       |__|::/        /  /:/      |  |:|       \\  \\:\\_\\/  ";
    gotoXY(col, line++);
    std::cout << "    \\  \\::/        /__/:/        /__/:/       |__|:|        \\  \\:\\    ";
    gotoXY(col, line++);
    std::cout << "     \\__\\/         \\__\\/         \\__\\/         \\__\\|         \\__\\/    ";
}

void snakeLogoLeft() {
    int line = 2;
    int col = 53;
    gotoXY(col, line++);
    std::cout << "      ___           ___           ___           ___           ___                      ";
    gotoXY(col, line++);
    std::cout << "     /\___\\         /\\  \\         /\\  \\         /|  |         /\\__\\             ";
    gotoXY(col, line++);
    std::cout << "    /:/ _/_        \\:\\  \\       /::\\  \\       |:|  |        /:/ _/_               ";
    gotoXY(col, line++);
    std::cout << "   /:/ /\\  \\        \\:\\  \\     /:/\\:\\  \\      |:|  |       /:/ /\\__\\         ";
    gotoXY(col, line++);
    std::cout << "  /:/ /::\\  \\   _____\\:\\  \\   /:/ /::\\  \\   __|:|  |      /:/ /:/ _/_           ";
    gotoXY(col, line++);
    std::cout << " /:/_/:/\\:\\__\\ /::::::::\\__\\ /:/_/:/\\:\\__\\ /\\ |:|__|____ /:/_/:/ /\\__\\      ";
    gotoXY(col, line++);
    std::cout << " \\:\\/:/ /:/  / \\:\\~~\\~~\\/__/ \\:\\/:/  \\/__/ \\:\\/:::::/__/ \\:\\/:/ /:/  /    ";
    gotoXY(col, line++);
    std::cout << "  \\::/ /:/  /   \\:\\  \\        \\::/__/       \\::/~~/~      \\::/_/:/  /           ";
    gotoXY(col, line++);
    std::cout << "   \\/_/:/  /     \\:\\  \\        \\:\\  \\        \\:\\~~\\        \\:\\/:/  /       ";
    gotoXY(col, line++);
    std::cout << "     /:/  /       \\:\\__\\        \\:\\__\\        \\:\\__\\        \\::/  /          ";
    gotoXY(col, line++);
    std::cout << "     \\/__/         \\/__/         \\/__/         \\/__/         \\/__/                ";
}