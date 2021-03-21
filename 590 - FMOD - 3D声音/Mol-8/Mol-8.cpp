// Mol-8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include "inc\fmod.hpp"
#include "inc\fmod_errors.h"
#include <iostream>
#pragma comment(lib, "fmodex_vc.lib")
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
// FMOD 4
FMOD::System * system;
FMOD::System_Create(&system);
system->init(16, FMOD_INIT_NORMAL, 0);
FMOD::Sound * sound; // sound
FMOD::Channel * channel; // sound channel
system->createSound("Classical_Artists.mp3", FMOD_SOFTWARE | FMOD_LOOP_OFF, 0, &sound); // creating sound
system->playSound(FMOD_CHANNEL_FREE, sound, false, 0);// playing sound (assigning it to a channel)
//channel->setPaused(false); // actually play sound

getch();

// FMOD 3

//FSOUND_SAMPLE * handle;
//FSOUND_Init (22050, 32, 0);
//
//handle=FSOUND_Sample_Load (0,"jules.mp3",0, 0, 0); // load and play sample
//
//FSOUND_PlaySound (0,handle);
//
//FSOUND_SetVolume(FSOUND_ALL ,256);
//FSOUND_SetPaused(FSOUND_ALL,false);
//FSOUND_SetLoopMode(FSOUND_ALL,FSOUND_LOOP_NORMAL);

	return 0;
}

