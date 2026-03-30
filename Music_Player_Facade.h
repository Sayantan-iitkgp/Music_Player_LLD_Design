#ifndef MUSIC_PLAYER_FACADE_H
#define MUSIC_PLAYER_FACADE_H
#include "./Models/Playlist.h"
#include "./Playing_Strategies/IPlay_Strategy.h"
#include "./Factories/Strategy_Factory.h"
#include "./Managers/Strategy_Manager.h"
#include "./IAudio_Output_Device.h"
#include "./Factories/Device_Factory.h"
#include "./Managers/Device_Manager.h"
#include "./Models/Song.h"
#include <bits/stdc++.h>
#include "Audio_Engine.h"
using namespace std;

// This is the Facade class that provides a simplified interface to the complex subsystem of the music player
class Music_Player_Facade
{
private:
    Strategy_Manager *strategyManager; // Pointer to the strategy manager to manage playing strategies
    DeviceManager *deviceManager;      // Pointer to the device manager to manage audio output devices
    AudioEngine *audioEngine;          // Pointer to the audio engine to play songs

public:
    Music_Player_Facade()
    {
        strategyManager = Strategy_Manager::getInstance(); // Get the single instance of the strategy manager
        deviceManager = DeviceManager::getInstance();      // Get the single instance of the device manager
        audioEngine = new AudioEngine();                   // Create a new instance of the audio engine
    }

    // set the audio output device for the music player
    void setAudioOutputDevice(string deviceType)
    {
        IAudioOutputDevice *device = deviceManager->getAudioOutputDevice(deviceType); // Get the desired audio output device adaptor based on the device type
        audioEngine->setAudioOutputDevice(device);                                    // Connect the audio engine to the selected audio output device
    }

    // play a single given song
    void playSong(Song *song)
    {
        audioEngine->play(song); // Use the audio engine to play the given song
    }

    // play songs from a given playlist using a specified playing strategy
    void play_Playlist_forward(Playlist *playlist, string strategyType, vector<Song> customOrder = {})
    {
        IPlay_Strategy *playStrategy = strategyManager->getStrategy(playlist, strategyType, customOrder, "forward"); // Get a playing strategy for the given playlist and strategy type
        while (playStrategy->hasNext())
        {
            Song *currentSong = playStrategy->next(); // Get the next song to play from the strategy
            audioEngine->play(currentSong);           // Use the audio engine to play the current song
        }
    }

    // pause the currently playing song
    void pause()
    {
        audioEngine->pause(); // Use the audio engine to pause the currently playing song
    }

    // play any  playlist song in reverse order if the strategy supports it
    void play_Playlist_Backward(Playlist *playlist, string strategyType, vector<Song> customOrder = {})
    {
        IPlay_Strategy *playStrategy = strategyManager->getStrategy(playlist, strategyType, customOrder, "backward"); // Get a playing strategy for the given playlist and strategy type
        while (playStrategy->hasPrevious())
        {
            Song *currentSong = playStrategy->previous(); // Get the previous song to play from the strategy
            audioEngine->play(currentSong);               // Use the audio engine to play the current song
        }
    }
};

#endif // MUSIC_PLAYER_FACADE_H