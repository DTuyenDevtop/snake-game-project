#pragma once
#pragma comment(lib, "winmm.lib")
#include <windows.h> 
#include <iostream>
#include <mmsystem.h>
#include "gameSound.h"

void playSound(LPCWSTR path){
    PlaySound(path, NULL, SND_SYNC);
}

void playSoundLoop(LPCWSTR path) {
    PlaySound(path, NULL, SND_LOOP | SND_ASYNC);
}

void turnOffSound() {
    PlaySound(NULL, NULL, NULL);
}