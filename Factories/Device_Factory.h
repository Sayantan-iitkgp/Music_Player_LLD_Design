#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H
#include <bits/stdc++.h>
using namespace std;
#include "../Audio_Adaptors/IAudioAdaptor.h"
#include "../Audio_Adaptors/Wired_Speaker_Adaptor.h"
#include "../Audio_Adaptors/Bluetooth_Adaptor.h"
#include "../Audio_Adaptors/Headphone_Adaptor.h"
#include "../Output_Device_APIs/IOutput_Device_API.h"
#include "../Output_Device_APIs/Wired_Speaker_API.h"
#include "../Output_Device_APIs/Bluetooth_Speaker_API.h"
#include "../Output_Device_APIs/Headphone_Speaker_API.h"

// Factory class to create audio adaptors based on the type of output device
// It is a Singleton class to ensure only one instance of the factory exists throughout the application
class DeviceFactory
{
private:
    static DeviceFactory *instance;
    static mutex mu;   // Singleton instance
    DeviceFactory() {} // Private constructor for Singleton pattern
public:
    static DeviceFactory *getInstance()
    {
        if (instance == nullptr)
        {
            unique_lock<mutex> lock(mu);
            if (instance == nullptr)
            {
                instance = new DeviceFactory();
            }
        }
        return instance;
    }

    // Factory method to create audio adaptors based on the type of output device
    IAudioAdaptor *createAudioAdaptor(string deviceType)
    {
        if (deviceType == "wired_speaker")
        {
            return new WiredSpeakerAdaptor(new WiredSpeakerAPI());
        }
        else if (deviceType == "bluetooth_speaker")
        {
            return new BluetoothAdaptor(new BluetoothSpeakerAPI());
        }
        else if (deviceType == "headphones")
        {
            return new HeadphoneAdaptor(new HeadphoneSpeakerAPI());
        }
        else
        {
            cout << "Invalid device type: " << deviceType << ". Returning nullptr." << endl;
            return nullptr;
        }
    }
};

// Initialize static members
DeviceFactory *DeviceFactory::instance = nullptr;
mutex DeviceFactory::mu;

#endif // DEVICE_FACTORY_H