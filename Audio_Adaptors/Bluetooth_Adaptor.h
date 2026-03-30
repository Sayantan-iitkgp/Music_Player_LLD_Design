#ifndef BLUETOOTH_ADAPTOR_H
#define BLUETOOTH_ADAPTOR_H
#include <bits/stdc++.h>
using namespace std;
#include "IAudioAdaptor.h"
#include "../Output_Device_APIs/IOutput_Device_API.h"
#include "../Output_Device_APIs/Bluetooth_Speaker_API.h"
#include "../Models/Song.h"


class BluetoothAdaptor : public IAudioAdaptor
{
public:
    BluetoothAdaptor(IOutputDeviceAPI *api) : IAudioAdaptor(api) {}
    
    void play(Song* song) override
    {
        cout << "BluetoothAdaptor: Playing '" << song->getName() << "' by " << song->getArtist() << "." << endl;
        getOutputDeviceAPI()->play(song->getPath());
    }
    
    void pause() override
    {
        cout << "BluetoothAdaptor: Pausing playback." << endl;
        getOutputDeviceAPI()->pause();
    }

};

#endif // BLUETOOTH_ADAPTOR_H