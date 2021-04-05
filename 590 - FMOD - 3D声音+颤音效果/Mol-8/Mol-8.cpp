#include "stdafx.h"
#include "inc\fmod.hpp"
#include "inc\fmod_errors.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

// ������ 4. FMod

#pragma comment(lib, "fmodex_vc.lib")
using namespace std;

/*FMOD �� ���ߧ�ӧߧ�� ������ڧ� �ڧ� 3 ��ѧ��֧�: System, Sound, Channel.
*
* System - ���٧ѧڧާ�է֧ۧ��ӧ�ӧѧ�� �� ��ڧ��֧ާ��.�ҧ�ӧ�ڧ�.���֧ߧڧ� �٧ӧ�ܧ�ӧ�ԧ� �����ӧܧ� �ڧ� ��ڧ��֧ާ�,
*						����ѧߧ�ӧڧ�� �ӧ���էߧ�� �٧ӧ�ܧ�ӧ�� �ܧѧ���, ����ѧߧ�ӧڧ�� ��ѧ٧ާ֧� �ҧ��֧�� DSP ...
* Sound -	���ҧ�ѧ٧֧� ��֧ѧݧ�ߧ�ԧ� �٧ӧ�ܧ�, �ܧ������ �ԧ���� �� �����ѧӧܧ� �ߧ� �٧ӧ�ܧ�ӧ�� �ܧѧ���.
*					������ 3 ��ڧ�� �٧ӧ�ܧ� : �ҧ֧� ��اѧ�ڧ�, ��اѧ�ڧ�, �����ܧ�ӧѧ� ��֧�֧էѧ��.
* Channel - ���ԧ�ѧ��ѧ� �٧ѧ�ڧ��. ����اߧ� ����ѧߧ�ӧڧ�� �ԧ��ާܧ����, �ӧ�֧ާ� �ӧ�����ڧ٧ӧ֧է֧ߧڧ�,
*					�ڧݧ� �֧ԧ� ���ݧ�ا֧ߧڧ� �� ��ܧ������ �� 3d �������ѧߧ��ӧ�
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
		// ����ѧߧ�ӧڧ�� ���ݧ��ڧ�� �ӧ֧ܧ��� ���ݧ�ا֧ߧڧ�, �ӧ֧ܧ��� ��ܧ������ �� �ӧ֧ܧ��� ���ڧ֧ߧ�ѧ�ڧ� ��ݧ��ѧ�֧ݧ�
		result = system->set3DListenerAttributes(0, &pos, 0, 0, 0);
		result = system->update();

		std::cout << "(" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";

		pos.x = 2.0f * sin(music_index) + music_distance;
		pos.z = 2.0f * cos(music_index) + music_distance;
		pos.y = 2.0f * sin(music_index) + music_distance;
		music_index += music_step;
	}

}// main

