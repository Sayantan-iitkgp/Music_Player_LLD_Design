#ifndef IAUDIO_OUTPUT_DEVICE_H
#define IAUDIO_OUTPUT_DEVICE_H
#include <bits/stdc++.h>
using namespace std;
#include "./Models/Song.h"

// Interface for audio output devices
class IAudioOutputDevice
{
public:
    virtual void play(Song* song) = 0; // Pure virtual function to play a song
    virtual void pause() = 0;                // Pure virtual function to pause playback
    
};

#endif // IAUDIO_OUTPUT_DEVICE_H