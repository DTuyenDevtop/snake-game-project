#pragma comment(lib, "winmm.lib")

// Standard library
#include <thread>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>  
#include <mmsystem.h>

// Custom library
#include "theme.h"
#include "gameSound.h"

using namespace std;

int main() {
    resizeConsole(WIDTH, HEIGHT);
    fixConsoleWindow();
    changeConsoleColor(WHITE);   
    
    thread sound_track(playSoundLoop, L"resources/backgroundmusic.wav");

    drawBoard();
    
    scanf_s("%*c");
    return 0;
}