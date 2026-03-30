#ifndef SEQUENTIAL_STRATEGY_H
#define SEQUENTIAL_STRATEGY_H
#include "IPlay_Strategy.h"
#include <bits/stdc++.h>
using namespace std;
#include "../Models/Song.h"
#include "../Models/Playlist.h"


// This is the concrete strategy for playing songs in a sequential order
class Sequential_Strategy : public IPlay_Strategy
{
private:
    Node *currentNode; // Pointer to the current song node in the playlist

public:
    Sequential_Strategy(Playlist *playlist, string direction) : IPlay_Strategy(playlist)
    {
        // Initialize currentNode to the head of the playlist
        if (getPlaylist()->get_playlist_size() > 0)
        {
            if (direction == "forward")
            {
                currentNode = getPlaylist()->getHead();
                // Assuming Playlist has a head pointer to the first song node
            }
            else
            {
                currentNode = getPlaylist()->getTail();
                // Assuming Playlist has a tail pointer to the last song node
            }
        }
        else
        {
            currentNode = nullptr; // No songs in the playlist
        }
    }

    bool hasNext() override
    {
        // Check if there are more songs to play
        return currentNode != nullptr;
    }

    Song *next() override
    {
        if (hasNext())
        {
            Song *currentSong = &(currentNode->song);
            currentNode = currentNode->next; // Move to the next node
            return currentSong;
        }
        return nullptr; // Return nullptr if there are no more songs to play
    }

    bool hasPrevious() override
    {
        // Check if there are previous songs to play
        return currentNode != nullptr && currentNode->prev != nullptr;
    }

    Song *previous() override
    {
        if (hasPrevious())
        {
            currentNode = currentNode->prev; // Move to the previous node
            return &(currentNode->song);
        }
        return nullptr; // Return nullptr if there are no previous songs to play
    }
};

#endif // SEQUENTIAL_STRATEGY_H