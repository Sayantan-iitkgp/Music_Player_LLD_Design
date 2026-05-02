#ifndef BLUETOOTH_SPEAKER_API_H
#define BLUETOOTH_SPEAKER_API_H
#include "IOutput_Device_API.h"
#include<bits/stdc++.h>
using namespace std;
#define st string

class Bluetooth_Speaker_API : public IOutput_Device_API
{
public:
    void play(st& path) override
    {
        //Different implementation for playing music through Bluetooth speaker
        cout << "Playing music through Bluetooth speaker and its path is : " << path << endl;
    }

    void pause() override
    {
        //Different implementation for pausing music through Bluetooth speaker
        cout << "Pausing music on Bluetooth speaker." << endl;
    }
};
#endif // BLUETOOTH_SPEAKER_API_H