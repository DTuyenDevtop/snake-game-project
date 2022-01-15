#pragma once
#pragma comment(lib, "winmm.lib")
#include <windows.h> 
#include <iostream>
#include <mmsystem.h>
#include "gameSound.h"

void playSound(LPCWSTR path){
    PlaySound(path, NULL, SND_SYNC);
    //PlaySound(path, NULL, SND_FILENAME); 
}

void playSoundLoop(LPCWSTR path) {
    while (true) {
        playSound(path);
        //PlaySound(path, NULL, SND_LOOP | SND_ASYNC);
    }
}