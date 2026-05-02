#ifndef WIRED_SPEAKER_API_H
#define WIRED_SPEAKER_API_H
#include "IOutput_Device_API.h"
#include<bits/stdc++.h>
using namespace std;
#define st string

class Wired_Speaker_API : public IOutput_Device_API
{
public:
    void play(st& path) override
    {
        //Different implementation for playing music through wired speaker
        cout << "Playing music through wired speaker and its path is : " << path << endl;
    }

    void pause() override
    {
        //Different implementation for pausing music through wired speaker
        cout << "Pausing music on wired speaker." << endl;
    }
};
#endif // WIRED_SPEAKER_API_H