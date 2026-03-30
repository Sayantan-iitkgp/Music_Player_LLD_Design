#ifndef CUSTOM_STRATEGY_H
#define CUSTOM_STRATEGY_H
#include "IPlay_Strategy.h"
#include <bits/stdc++.h>
using namespace std;
#include "../Models/Song.h"
#include "../Models/Playlist.h"

// This is the concrete strategy for playing songs in a custom order defined by the user

class Custom_Strategy : public IPlay_Strategy
{
private:
    vector<Song> songs; // Vector to store the songs from the playlist in the custom order
    int currentIndex;   // Index to keep track of the current song

public:
    Custom_Strategy(Playlist *playlist, vector<Song> customOrder,string direction) : IPlay_Strategy(playlist)
    {
        // Get all songs from the playlist and store them in the vector according to the custom order
        for (auto song: customOrder)
        {
            if (getPlaylist()->hasSong(song)) // Check if the song is in the playlist
            {
                songs.push_back(song); // Add the song to the vector in the custom order
            }
        }
        if (direction == "backward")
        {
            reverse(songs.begin(), songs.end());
        }
        currentIndex = 0; // Start from the first song in the custom order
    }

    bool hasNext() override
    {
        // Check if there are more songs to play
        return currentIndex < songs.size();
    }

    Song *next() override
    {
        if (hasNext())
        {
            return &songs[currentIndex++]; // Return the current song and move to the next index
        }
        return nullptr; // Return nullptr if there are no more songs to play
    }

    bool hasPrevious() override
    {
        // Check if there are previous songs to play
        return currentIndex > 0;
    }

    Song *previous() override
    {
        if (hasPrevious())
        {
            return &songs[--currentIndex]; // Move back to the previous index and return the song
        }
        return nullptr; // Return nullptr if there are no previous songs to play
    }
};
#endif // CUSTOM_STRATEGY_H