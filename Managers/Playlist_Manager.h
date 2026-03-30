#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H
#include <bits/stdc++.h>
using namespace std;
#include "../Models/Playlist.h"
#include "../Models/Song.h"
#define ll long long int
#define pb push_back
#define st string

// It is a Singleton class for managing all playlists
class PlaylistManager
{
private:
    ll nextPlaylistId = 1;                      // To generate unique playlist IDs
    map<ll, Playlist> playlists;                // Map of playlist ID to Playlist object
    map<ll, unordered_set<ll>> songToPlaylists;           // Map of song ID to set of playlist IDs containing that song
    static PlaylistManager *instance;           // Singleton instance
    static mutex mtx;                           // Mutex for thread safety
    PlaylistManager() {}                        // Private constructor for Singleton pattern

public:
    static PlaylistManager *getInstance()
    {
        // make it thread safe
        if (instance == nullptr)
        {
            unique_lock<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new PlaylistManager();
            }
        }
        return instance;
    }

    // Create a new playlist
    void createPlaylist(st name)
    {
        Playlist newPlaylist(name, nextPlaylistId);
        playlists.insert({nextPlaylistId, newPlaylist});
        cout << "Created playlist '" << name << "' with ID " << nextPlaylistId << "." << endl;
        nextPlaylistId++;
    }

    // Add a song to a playlist
    void addSongToPlaylist(ll playlistId, Song song)
    {
        auto it = playlists.find(playlistId);
        if (it == playlists.end()) {
            cout << "Playlist with ID " << playlistId << " does not exist." << endl;
            return;
        }
        it->second.addSong(song);
        songToPlaylists[song.getId()].insert(playlistId);
    }

    // Remove a song from a playlist
    void removeSongFromPlaylist(ll playlistId, Song song)
    {
        auto it = playlists.find(playlistId);
        if (it == playlists.end()) {
            cout << "Playlist with ID " << playlistId << " does not exist." << endl;
            return;
        }
        it->second.removeSong(song);
        songToPlaylists[song.getId()].erase(playlistId);
    }

    // Get all playlists containing a specific song
    vector<Playlist> getPlaylistsContainingSong(Song song)
    {
        vector<Playlist> result;
        if (songToPlaylists.find(song.getId()) != songToPlaylists.end()) {
            for (ll playlistId : songToPlaylists[song.getId()]) {
                auto it = playlists.find(playlistId);
                if (it != playlists.end()) {
                    result.push_back(it->second);
                }
            }
        }
        return result;
    }

    // Get a specific playlist by ID
    Playlist *getPlaylistById(ll playlistId)
    {
        if (playlists.find(playlistId) != playlists.end())
        {
            return &playlists[playlistId];
        }
        else
        {
            cout << "Playlist with ID " << playlistId << " does not exist." << endl;
            return nullptr; // Return nullptr if the playlist with the given ID does not exist
        }
    }

    // Get all playlists
    vector<Playlist> getAllPlaylists()
    {
        vector<Playlist> result;
        for (auto it = playlists.begin(); it != playlists.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }

    // Delete a playlist
    void deletePlaylist(ll playlistId)
    {
        if (playlists.find(playlistId) == playlists.end())
        {
            cout << "Playlist with ID " << playlistId << " does not exist." << endl;
            return;
        }
        // Remove the playlist from songToPlaylists mapping
        for (Song song : playlists[playlistId].getSongs())
        {
            songToPlaylists[song.getId()].erase(playlistId);
        }
        playlists.erase(playlistId);
        cout << "Deleted playlist with ID " << playlistId << "." << endl;
    }

    // Delete a song
    void deleteSong(Song song)
    {
        if (songToPlaylists.find(song.getId()) != songToPlaylists.end())
        {
            for (ll playlistId : songToPlaylists[song.getId()])
            {
                playlists[playlistId].removeSong(song);
            }
            songToPlaylists.erase(song.getId());
            cout << "Deleted song '" << song.getName() << "' from all playlists." << endl;
        }
        else
        {
            cout << "Song '" << song.getName() << "' is not in any playlist." << endl;
        }
    }
};

// Initialize static members
PlaylistManager *PlaylistManager::instance = nullptr;
mutex PlaylistManager::mtx;

#endif // PLAYLIST_MANAGER_H