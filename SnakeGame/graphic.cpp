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

void textFillColor(int colorCode, int BackC) {
    //int BackC = BACKGROUND_COLOR;
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
    textColor(Color);
    std::cout << Text;
    textColor(Color);
}

void colorText(char Text, int Color) {
    textColor(Color);
    std::cout << Text;
    textColor(Color);
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

void snakeGraphic1() {
    cout << "   _________         _________" << endl;
    cout << "  /         \\       /         \\ " << endl;
    cout << " /  /~~~~~\\  \\     /  /~~~~~\\  \\" << endl;
    cout << " |  |     |  |     |  |     |  |" << endl;
    cout << " |  |     |  |     |  |     |  |" << endl;
    cout << " |  |     |  |     |  |     |  |         /" << endl;
    cout << " |  |     |  |     |  |     |  |       //" << endl;
    cout << "(o  o)    \\  \\_____/  /      \\  \\_____/ /" << endl;
    cout << " \\__/      \\         /        \\        /" << endl;
    cout << "  |         ~~~~~~~~~         ~~~~~~~~" << endl;
    cout << "  ^";
}

void snakeGraphic2() {
    cout << "                       __    __    __    __    __    __    __    __    __    __    __ " << endl;
    cout << "                      /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\  /  \\" << endl;
    cout << " ____________________/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\/  __\\_____________________________" << endl;
    cout << " ___________________/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /__/  /________________________________" << endl;
    cout << "                   /  / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\   / \\  \\____" << endl;
    cout << "                  / /    \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\    o \\" << endl;
    cout << "                 //                                                                   \\_____/--<" << endl;
    cout << "                /";
}

void snakeGraphic3() {
    cout << "      {0O}" << endl;
    cout << "      \\__/" << endl;
    cout << "      /^/" << endl;
    cout << "     ( (       " << endl;
    cout << "     \\_\\_____" << endl;
    cout << "     (_______)" << endl;
    cout << "    (_________()Oo" << endl;
}

void showLogo1() {
    textColor(BYELLOW);
    int line = 3;
    int col = 41;
    gotoXY(col, line++);
    cout << "           /^\\/^\\" << endl;
    gotoXY(col, line++);
    cout << "         _|__|  O|                                                                   /" << endl;
    gotoXY(col, line++);
    cout << "\\/     /~     \\_/ \\                                                                //" << endl;
    gotoXY(col, line++);
    cout << " \\____|__________/ \\                                                             _//" << endl;
    gotoXY(col, line++);
    cout << "        \\_______    \\                                                           / /" << endl;
    gotoXY(col, line++);
    cout << "                `\\   \\                                                         / / " << endl;
    gotoXY(col, line++);
    cout << "                  |   |   _______..__   __.      ___       __  ___  _______   |  |"<< endl;
    gotoXY(col, line++);
    cout << "                 /   /   /       ||  \\ |  |     /   \\     |  |/  / |   ____|  \\  \\" << endl;
    gotoXY(col, line++);
    cout << "                /   /   |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__      |  |" << endl;
    gotoXY(col, line++);
    cout << "                |   \\    \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|     /  /" << endl;
    gotoXY(col, line++);
    cout << "                \\    `----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |_______/  /" << endl;
    gotoXY(col, line++);
    cout << "                 \\___________/    |__| \\__| /__/     \\__\\ |__|\\__\\ |____________/" << endl;
}