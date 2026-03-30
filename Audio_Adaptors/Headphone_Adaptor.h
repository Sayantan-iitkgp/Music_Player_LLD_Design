#ifndef HEADPHONE_ADAPTOR_H
#define HEADPHONE_ADAPTOR_H
#include <bits/stdc++.h>
using namespace std;
#include "IAudioAdaptor.h"
#include "../Output_Device_APIs/IOutput_Device_API.h"
#include "../Output_Device_APIs/Headphone_Speaker_API.h"
#include "../Models/Song.h"


class HeadphoneAdaptor : public IAudioAdaptor
{
public:
    HeadphoneAdaptor(IOutputDeviceAPI *api) : IAudioAdaptor(api) {}
    
    void play(Song* song) override
    {
        cout << "HeadphoneAdaptor: Playing '" << song->getName() << "' by " << song->getArtist() << "." << endl;
        getOutputDeviceAPI()->play(song->getPath());
    }
    
    void pause() override
    {
        cout << "HeadphoneAdaptor: Pausing playback." << endl;
        getOutputDeviceAPI()->pause();
    }

};

#endif // HEADPHONE_ADAPTOR_H