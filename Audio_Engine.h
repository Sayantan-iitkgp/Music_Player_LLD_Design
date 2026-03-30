#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H
#include <bits/stdc++.h>
using namespace std;
#include "IAudio_Output_Device.h"
#include "./Models/Song.h"

// The AudioEngine class is responsible for managing audio playback and connecting to various output devices through adaptors
class AudioEngine
{
private:
    IAudioOutputDevice *current_audioOutputDevice; // Pointer to the current audio output device
    Song *current_song;                            // Pointer to the current playing song

public:
    AudioEngine()
    {
        current_audioOutputDevice = nullptr;
        current_song = nullptr;
    }

    void setAudioOutputDevice(IAudioOutputDevice *device)
    {
        current_audioOutputDevice = device;
    }

    void setCurrentSong(Song* song)
    {
        current_song = song;
    }

    void play(Song* song)
    {
        if (current_audioOutputDevice)
        {
            setCurrentSong(song);
            current_audioOutputDevice->play(current_song);
        }
        else
        {
            cout << "No audio output device connected." << endl;
        }
    }

    void pause()
    {
        if (current_audioOutputDevice)
        {
            if (current_song)
            {
                cout << "Pausing '" << current_song->getName() << "' by " << current_song->getArtist() << "." << endl;
                current_audioOutputDevice->pause();
            }
            else
            {
                cout << "No song is currently playing." << endl;
            }
        }
        else
        {
            cout << "No audio output device connected." << endl;
        }
    }
};
#endif // AUDIO_ENGINE_H