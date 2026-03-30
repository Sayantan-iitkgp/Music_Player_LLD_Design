#ifndef RANDOM_STRATEGY_H
#define RANDOM_STRATEGY_H

#include "IPlay_Strategy.h"
#include <bits/stdc++.h>
#include "../Models/Song.h"
#include "../Models/Playlist.h"
using namespace std;

// This is the concrete strategy for playing songs in a random order
class Random_Strategy : public IPlay_Strategy
{
private:
    vector<Song> songs; // Vector to store the songs from the playlist
    int currentIndex;   // Index to keep track of the current song

public:
    Random_Strategy(Playlist *playlist, string direction) : IPlay_Strategy(playlist)
    {
        // Get all songs from the playlist and store them in the vector
        songs = getPlaylist()->getSongs();
        // Shuffle the songs to play them in random order
        random_shuffle(songs.begin(), songs.end());
        if (direction == "backward")
        {
            reverse(songs.begin(), songs.end());
        }
        currentIndex = 0; // Start from the first song in the shuffled list
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

#endif // RANDOM_STRATEGY_H