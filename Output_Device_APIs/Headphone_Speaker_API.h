#ifndef HEADPHONE_SPEAKER_API_H
#define HEADPHONE_SPEAKER_API_H
#include "IOutput_Device_API.h"
#include<bits/stdc++.h>
using namespace std;
#define st string
class Headphone_Speaker_API : public IOutput_Device_API
{
public:
    void play(st& path) override
    {
        //Different implementation for playing music through headphones/speakers
        cout << "Playing music through headphones and its path is : " << path << endl;
    }

    void pause() override
    {
        //Different implementation for pausing music through headphones/speakers
        cout << "Pausing music on headphones/speakers." << endl;
    }
};
#endif // HEADPHONE_SPEAKER_API_H