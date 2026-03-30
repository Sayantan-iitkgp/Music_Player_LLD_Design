#ifndef IPLAY_STRATEGY_H
#define IPLAY_STRATEGY_H
#include <bits/stdc++.h>
using namespace std;
#include "../Models/Song.h"
#include "../Models/Playlist.h"

// This is the interface for the strategy pattern, it will be implemented by all the playing strategies of any playlist songs
class IPlay_Strategy
{
private:
    Playlist *playlist;

public:
    IPlay_Strategy(Playlist *playlist)
    {
        this->playlist = playlist;
    }
    Playlist *getPlaylist() const
    {
        return playlist;
    }
    virtual bool hasNext() = 0; // Pure virtual function to check if there are more songs to play
    virtual Song* next() = 0;   // Pure virtual function to get the next song
    virtual bool hasPrevious() =0; // Virtual function to check if there are previous songs to play, default implementation returns false
    virtual Song* previous() =0; // Virtual function to get the previous song, default implementation returns nullptr
};

#endif // IPLAY_STRATEGY_H