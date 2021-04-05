#include "stdafx.h"
#include "inc\fmod.hpp"
#include "inc\fmod_errors.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

// §­§¡§¢ 4. FMod

#pragma comment(lib, "fmodex_vc.lib")
using namespace std;

/*FMOD §Ó §à§ã§ß§à§Ó§ß§à§Þ §ã§à§ã§ä§à§Ú§ä §Ú§Ù 3 §é§Ñ§ã§ä§Ö§Û: System, Sound, Channel.
*
* System - §£§Ù§Ñ§Ú§Þ§à§Õ§Ö§Û§ã§ä§Ó§à§Ó§Ñ§ä§î §ã §ã§Ú§ã§ä§Ö§Þ§à§Û.§Ò§í§Ó§ê§Ú§Û.§é§ä§Ö§ß§Ú§Ö §Ù§Ó§å§Ü§à§Ó§à§Ô§à §à§ä§â§í§Ó§Ü§Ñ §Ú§Ù §ã§Ú§ã§ä§Ö§Þ§í,
*						§å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §Ó§í§ç§à§Õ§ß§å§ð §Ù§Ó§å§Ü§à§Ó§å§ð §Ü§Ñ§â§ä§å, §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §â§Ñ§Ù§Þ§Ö§â §Ò§å§æ§Ö§â§Ñ DSP ...
* Sound -	§°§Ò§â§Ñ§Ù§Ö§è §â§Ö§Ñ§Ý§î§ß§à§Ô§à §Ù§Ó§å§Ü§Ñ, §Ü§à§ä§à§â§í§Û §Ô§à§ä§à§Ó §Ü §à§ä§á§â§Ñ§Ó§Ü§Ö §ß§Ñ §Ù§Ó§å§Ü§à§Ó§å§ð §Ü§Ñ§â§ä§å.
*					§¦§ã§ä§î 3 §ä§Ú§á§Ñ §Ù§Ó§å§Ü§Ñ : §Ò§Ö§Ù §ã§Ø§Ñ§ä§Ú§ñ, §ã§Ø§Ñ§ä§Ú§Ö, §á§à§ä§à§Ü§à§Ó§Ñ§ñ §á§Ö§â§Ö§Õ§Ñ§é§Ñ.
* Channel - §ª§Ô§â§Ñ§ð§ë§Ñ§ñ §Ù§Ñ§á§Ú§ã§î. §®§à§Ø§ß§à §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §Ô§â§à§Þ§Ü§à§ã§ä§î, §Ó§â§Ö§Þ§ñ §Ó§à§ã§á§â§à§Ú§Ù§Ó§Ö§Õ§Ö§ß§Ú§ñ,
*					§Ú§Ý§Ú §Ö§Ô§à §á§à§Ý§à§Ø§Ö§ß§Ú§Ö §Ú §ã§Ü§à§â§à§ã§ä§î §Ó 3d §á§â§à§ã§ä§â§Ñ§ß§ã§ä§Ó§Ö
*
*/

int _tmain(int argc, _TCHAR* argv[])
{
	FMOD_RESULT result;
	FMOD::System* system;
	result = FMOD::System_Create(&system);
	if (result != FMOD_OK) { //check
		cerr << "Unable to create FMOD system: " << FMOD_ErrorString(result) << endl;
		exit(1);
	}
	result = system->init(16, FMOD_INIT_NORMAL, 0);

	FMOD::Sound* sound; // sound
	FMOD::Channel* channel; // sound channel

	//result = system->createSound("Classical_Artists.mp3", FMOD_SOFTWARE | FMOD_LOOP_OFF, 0, &sound); // creating sound
	// creating 3d sound
	result = system->createSound("TheTruthThatYouLeave.mp3", FMOD_LOOP_OFF | FMOD_3D | FMOD_HARDWARE, 0, &sound); 

	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, 0);// playing sound (assigning it to a channel)
	//channel->setPaused(false); // actually play sound

	float music_index = 0.0f;
	float music_step = 0.05f;
	float music_distance = 0.5f;
	FMOD_BOOL playing = 1;
	FMOD_VECTOR pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	while (playing)
	{
		Sleep(10);
		// §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §á§à§Ý§å§é§Ú§ä§î §Ó§Ö§Ü§ä§à§â §á§à§Ý§à§Ø§Ö§ß§Ú§ñ, §Ó§Ö§Ü§ä§à§â §ã§Ü§à§â§à§ã§ä§Ú §Ú §Ó§Ö§Ü§ä§à§â §à§â§Ú§Ö§ß§ä§Ñ§è§Ú§Ú §ã§Ý§å§ê§Ñ§ä§Ö§Ý§ñ
		result = system->set3DListenerAttributes(0, &pos, 0, 0, 0);
		result = system->update();

		std::cout << "(" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";

		pos.x = 2.0f * sin(music_index) + music_distance;
		pos.z = 2.0f * cos(music_index) + music_distance;
		pos.y = 2.0f * sin(music_index) + music_distance;
		music_index += music_step;
	}

}// main

