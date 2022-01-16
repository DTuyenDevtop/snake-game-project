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
#include "theme.h"
#include "screen.h"
#include "gameSound.h"

using namespace std;

Screen screen;

void setup() {
    removeScrollbar();
    resizeConsole(WIDTH, HEIGHT);
    fixConsoleWindow();
    changeConsoleColor(BACKGROUND_COLOR);

    playSoundLoop(L"resources/backgroundmusic.wav");

    screen.clear();
    screen.draw.retangle({ 2, 1 }, { 71, 37 }, GREEN, 2);
    screen.draw.retangle({ 100, 5 }, { 15, 30 }, RED, 1);
}

int main() {
    setup();

    //thread sound_track(playSoundLoop, L"resources/backgroundmusic.wav");
    //HANDLE handle_t1 = sound_track.native_handle();
    cout << "\n\t\t Turn off/on music(x/y):";
    while (1) {
        char x = _getch();
        if (x == 'x') {
            turnOffSound();
        } 
        else {
            playSoundLoop(L"resources/backgroundmusic.wav");
        }
    }
    
    return 0;
}