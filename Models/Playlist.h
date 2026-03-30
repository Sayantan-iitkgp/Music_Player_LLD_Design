#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <bits/stdc++.h>
#include "Song.h"
using namespace std;
#define ll long long
#define pb push_back
#define st string
// Also Implementing Playlist structure using Dobly linked list
struct Node
{
    Song song;
    Node *prev;
    Node *next;

    Node(Song s) : song(s), prev(nullptr), next(nullptr) {}
};

class Playlist
{
private:
    ll id; // Unique identifier for each playlist
    st name;
    unordered_map<ll, Node *> songMap; // Map to store song ID and corresponding node for O(1) access
    Node *head;
    Node *tail;

public:
    // Default constructor
    Playlist() : id(0), name(""), head(nullptr), tail(nullptr) {}
    // Define operator< for use in set/map (compare by id)
    bool operator<(const Playlist& other) const {
        return id < other.id;
    }
    
    Playlist(st name, ll id)
    {
        this->id = id;
        this->name = name;
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Getters
    ll getId() 
    {
        return id;
    }
    st getName() 
    {
        return name;
    }

    //Getters for head and tail pointers for Sequential_Strategy to access the playlist
    Node* getHead() 
    {
        return head;
    }
    
    Node* getTail() 
    {
        return tail;
    }

    // Get all songs in the playlist
    vector<Song> getSongs() 
    {
        vector<Song> songs;
        for (auto entry : songMap)
        {
            songs.push_back(entry.second->song);
        }
        return songs;
    }

    // Add a song to the playlist
    void addSong(Song song)
    {
        Node *newNode = new Node(song);
        songMap[song.getId()] = newNode; // Store the node in the map for O(1) access
        if (!head)
        {
            head = tail = newNode; // First song in the playlist
        }
        else
        {
            tail->next = newNode; // Append to the end of the list
            newNode->prev = tail;
            tail = newNode; // Update the tail pointer
        }
    }

    // Remove a song from the playlist
    void removeSong(Song song) // Assuming Song has an appropriate comparison operator defined
    {
        auto it = songMap.find(song.getId());
        if (it != songMap.end())
        {
            Node *nodeToRemove = it->second;
            // Update the links of the previous and next nodes
            if (nodeToRemove->prev)
            {
                nodeToRemove->prev->next = nodeToRemove->next;
            }
            else
            {
                head = nodeToRemove->next;
                // If it's the head node
            }
            if (nodeToRemove->next)
            {
                nodeToRemove->next->prev = nodeToRemove->prev;
            }
            else
            {
                tail = nodeToRemove->prev; // If it's the tail node
            }

            delete nodeToRemove; // Free the memory
            songMap.erase(it);   // Remove from the map
        }
    }

    // Check if a song is in the playlist
    bool hasSong(Song song) const
    {
        return songMap.find(song.getId()) != songMap.end(); // Check if the song ID exists in the map
    }

    ll get_playlist_size() 
    {
        return songMap.size(); // Return the number of songs in the playlist
    }
};

#endif // PLAYLIST_H