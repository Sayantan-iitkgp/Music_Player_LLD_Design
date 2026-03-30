#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H
#include <bits/stdc++.h>
using namespace std;
#include "../IAudio_Output_Device.h"
#include "../Factories/Device_Factory.h"
//It is a Singleton class for ordering the desired output device to the factory and supply it to the Music Player Facade
class DeviceManager
{
private:
    static DeviceManager *instance; // Singleton instance
    static mutex mtx;               // Mutex for thread safety
    DeviceFactory *deviceFactory;   // Pointer to the device factory

    DeviceManager()
    {
        deviceFactory = DeviceFactory::getInstance();
    } // Private constructor for Singleton pattern  
    
public:
    static DeviceManager *getInstance()
    {
        if (instance == nullptr)
        {
            unique_lock<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new DeviceManager();
            }
        }
        return instance;
    }

    // Method to get the desired audio output device adaptor based on the device type
    IAudioOutputDevice *getAudioOutputDevice(string deviceType)
    {
        return deviceFactory->createAudioAdaptor(deviceType);
    }
};

// Initialize the static instance pointer and mutex
DeviceManager *DeviceManager::instance = nullptr;
mutex DeviceManager::mtx;

#endif // DEVICE_MANAGER_H