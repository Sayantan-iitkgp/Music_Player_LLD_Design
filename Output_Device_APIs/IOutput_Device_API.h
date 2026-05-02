#ifndef IOUTPUT_DEVICE_API_H
#define IOUTPUT_DEVICE_API_H
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define st string

// Forward declaration
class IOutput_Device_API {
public:
    virtual ~IOutput_Device_API() = default;
    virtual void play(st& path) = 0;
    virtual void pause() = 0;
};

#endif // IOUTPUT_DEVICE_API_H