#ifndef WIRED_SPEAKER_ADAPTOR_H
#define WIRED_SPEAKER_ADAPTOR_H
#include <bits/stdc++.h>
using namespace std;
#include "IAudioAdaptor.h"
#include "../Output_Device_APIs/IOutput_Device_API.h"
#include "../Output_Device_APIs/Wired_Speaker_API.h"
#include "../Models/Song.h"


class WiredSpeakerAdaptor : public IAudioAdaptor
{
public:
    WiredSpeakerAdaptor(IOutputDeviceAPI *api) : IAudioAdaptor(api) {}
    
    void play(Song* song) override
    {
        cout << "WiredSpeakerAdaptor: Playing '" << song->getName() << "' by " << song->getArtist() << "." << endl;
        getOutputDeviceAPI()->play(song->getPath());
    }
    
    void pause() override
    {
        cout << "WiredSpeakerAdaptor: Pausing playback." << endl;
        getOutputDeviceAPI()->pause();
    }

};

#endif // WIRED_SPEAKER_ADAPTOR_H