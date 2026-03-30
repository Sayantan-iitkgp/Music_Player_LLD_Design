#ifndef IAUDIO_ADAPTOR_H
#define IAUDIO_ADAPTOR_H
#include <bits/stdc++.h>
using namespace std;
#include "../Output_Device_APIs/IOutput_Device_API.h"
#include "../Models/Song.h"
#include "../IAudio_Output_Device.h"
// Interface for audio adaptors that connect the music player to various output device's APIs

class IAudioAdaptor: public IAudioOutputDevice
{
private:
    IOutputDeviceAPI *outputDeviceAPI; // Pointer to the output device API

public:
    IAudioAdaptor(IOutputDeviceAPI *api) : outputDeviceAPI(api) {}

    IOutputDeviceAPI *getOutputDeviceAPI() const
    {
        return outputDeviceAPI;
    }

    virtual void play(Song* song) = 0; // Pure virtual function to play a song
    virtual void pause() = 0;                // Pure virtual function to pause playback
};
#endif // IAUDIO_ADAPTOR_H