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
	FMOD::DSP* dsp = 0;
	FMOD_RESULT result;
	FMOD::System* system;
	result = FMOD::System_Create(&system);
	result = system->init(16, FMOD_INIT_NORMAL, 0);

	FMOD::Sound* sound; // sound
	FMOD::Channel* channel; // sound channel

	//result = system->createSound("Classical_Artists.mp3", FMOD_SOFTWARE | FMOD_LOOP_OFF, 0, &sound); // creating sound
	result = system->createSound("Classical_Artists.mp3", FMOD_INIT_NORMAL | FMOD_LOOP_OFF | FMOD_3D | FMOD_HARDWARE, 0, &sound); // creating 3d sound
	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, 0);// playing sound (assigning it to a channel)
	//channel->setPaused(false); // actually play sound

#if 1
	float music_index = 0.0f;
	float music_step = 0.05f;
	float music_distance = 0.5f;
	FMOD_BOOL playing = 1;  // true
	FMOD_VECTOR pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	while (playing)
	{
		Sleep(10);
		result = system->set3DListenerAttributes(0, &pos, 0, 0, 0);
		result = system->update();

		std::cout << "(" << pos.x << ", " << pos.y << ", " << pos.z << ")\t";

		pos.x = 2.0f * sin(music_index) + music_distance;
		pos.z = 2.0f * cos(music_index) + music_distance;
		music_index += music_step;
	}
#endif


	//system->setSpeakerMode(FMOD_SPEAKERMODE::FMOD_SPEAKERMODE_QUAD);
	//result = system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
	//result = system->addDSP(dsp, 0);
	//result = system->update();

#if 0

	int i = -10000;
	while (true)
	{
		FMOD_VECTOR listenerpos = { i / 1000, 0.0f, 0.0f };  // 第一个参数：听者位置

		// set3DMinMaxDistance(float min, float max)
		result = system->set3DListenerAttributes(0, &listenerpos, 0, 0, 0);
		result = system->update();
		std::cout << i << ", ";
		Sleep(5);
		i++;

		if (i == 10000)
		{
			i *= -1;
		}
	}
#endif
	//getch();

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

	//return 0;
}

