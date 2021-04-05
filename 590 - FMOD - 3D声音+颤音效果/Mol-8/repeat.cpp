#include "stdafx.h"
#include "inc\fmod.hpp"
#include "inc\fmod_errors.h"
#include <conio.h>
#include <windows.h>
#include <iostream>


int _tmain_repeat(int argc, _TCHAR* argv[])
{
  FMOD::System* system = NULL;
  FMOD::Sound* sound = NULL;
  FMOD::Channel* channel = NULL;

  FMOD_RESULT result = FMOD::System_Create(&system);
  system->init(32, FMOD_INIT_NORMAL, NULL);

  //creat sound stream
  system->createStream("TheTruthThatYouLeave.mp3", FMOD_HARDWARE, NULL, &sound);
  sound->setMode(FMOD_LOOP_NORMAL);

  system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
  channel->setVolume(1);

  std::cout << "Effect: echo\n";
  system->setSpeakerMode(FMOD_SPEAKERMODE::FMOD_SPEAKERMODE_QUAD);
  FMOD::DSP* echo = 0;
  result = system->createDSPByType(FMOD_DSP_TYPE_ECHO, &echo);

  result = system->addDSP(echo, 0);

  // play
  if (getchar() == VK_RETURN) {
    sound->release();
    system->close();
    system->release();
  }
  


  
  return 0;
}