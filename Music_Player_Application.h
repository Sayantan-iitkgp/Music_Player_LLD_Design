#ifndef MUSIC_PLAYER_APPLICATION_H
#define MUSIC_PLAYER_APPLICATION_H
#include "Music_Player_Facade.h"
#include "./Models/Playlist.h"
#include "./Models/Song.h"
#include "./Managers/Playlist_Manager.h"
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// This is the main application class for the music player, it will use the Music_Player_Facade to interact with the complex subsystem of the music player
class Music_Player_Application
{
private:
    ll nextSongId = 1;                // To generate unique song IDs
    Music_Player_Facade *facade;      // Pointer to the music player facade to interact with the music player subsystem
    PlaylistManager *playlistManager; // Pointer to the playlist manager to manage playlists and their songs
    map<ll, Song> allSongs;            // Map to store all songs in the music player for easy access
    unordered_set<ll> songIds;      // Set to store existing song IDs for quick lookup
public:
    Music_Player_Application()
    {
        facade = new Music_Player_Facade();               // Create a new instance of the music player facade
        playlistManager = PlaylistManager::getInstance(); // Get the single instance of the playlist manager
    }

    // Method to demonstrate the functionality of the music player application
    void create_song(st name, st artist, ll duration, ll releaseYear, st path)
    {
        Song newSong(name, artist, duration, releaseYear, path, nextSongId); // Create a new song with the given details and a unique ID
        allSongs.insert({nextSongId, newSong});                                     // Add the new song to the map of all songs
        songIds.insert(nextSongId);                                          // Add the song ID to the set of existing song IDs
        cout << "Created song '" << name << "' by " << artist << " with ID " << nextSongId << "." << endl;
        nextSongId++; // Increment the song ID for the next song
    }

    // create a new playlist with the given name
    void create_playlist(st name)
    {
        playlistManager->createPlaylist(name); // Use the playlist manager to create a new playlist with the given name
    }

    // get a song by its ID
    Song *get_song_by_id(ll songId)
    {
        if (songIds.find(songId) == songIds.end())
        {
            cout << "Song with ID " << songId << " does not exist." << endl;
            return nullptr; // Return nullptr if the song with the given ID does not exist
        }
        return &allSongs[songId]; // Return a pointer to the song with the given ID from the map of all songs
    }

    // add a song to a playlist using their IDs
    void add_song_to_playlist(ll playlistId, Song song)
    {

        playlistManager->addSongToPlaylist(playlistId, song); // Use the playlist manager to add the given song to the specified playlist
    }

    // remove song from a playlist
    void remove_song_from_playlist(ll playlistId, Song song)
    {
        playlistManager->removeSongFromPlaylist(playlistId, song); // Use the playlist manager to remove the given song from the specified playlist
    }

    // delete a song from the music player and all playlists containing it
    void delete_song(Song song)
    {
        playlistManager->deleteSong(song); // Use the playlist manager to delete the given song from all playlists containing it
        songIds.erase(song.getId());       // Remove the song ID from the set of existing song IDs
        allSongs.erase(song.getId());     // Remove the song from the map of all songs
        cout << "Deleted song '" << song.getName() << "' from the music player." << endl;
    }

    // Delete a playlist by its ID
    void delete_playlist(ll playlistId)
    {
        playlistManager->deletePlaylist(playlistId); // Use the playlist manager to delete the specified playlist by its ID
    }

    // Set the audio output device for the music player
    void set_audio_output_device(const string &deviceType)
    {
        facade->setAudioOutputDevice(deviceType); // Use the music player facade to set the audio output device based on the device type
    }

    // play a single song using the music player facade
    void play_song(Song *song)
    {
        if (song == nullptr)
        {
            cout << "Cannot play a null song." << endl;
            return;
        }
        facade->playSong(song); // Use the music player facade to play the given song
    }

    // play songs from a playlist using a specified playing strategy in forward order
    void play_playlist_forward(ll playlistId, string strategyType, vector<Song> customOrder = {})
    {
        Playlist *playlist = playlistManager->getPlaylistById(playlistId); // Get the specified playlist from the playlist manager
        if (playlist == nullptr || playlist->get_playlist_size() == 0)
        {
            cout << "Playlist with ID " << playlistId << " is empty or does not exist." << endl;
            return;
        }
        facade->play_Playlist_forward(playlist, strategyType, customOrder); // Use the music player facade to play songs from the playlist in forward order using the specified playing strategy
    }

    // play songs from a playlist using a specified playing strategy in backward order
    void play_playlist_backward(ll playlistId, string strategyType, vector<Song> customOrder = {})
    {
        Playlist *playlist = playlistManager->getPlaylistById(playlistId); // Get the specified playlist from the playlist manager
        if (playlist == nullptr || playlist->get_playlist_size() == 0)
        {
            cout << "Playlist with ID " << playlistId << " is empty or does not exist." << endl;
            return;
        }
        facade->play_Playlist_Backward(playlist, strategyType, customOrder); // Use the music player facade to play songs from the playlist in backward order using the specified playing strategy
    }

    // get any playlist by its ID
    Playlist *get_playlist_by_id(ll playlistId)
    {
        return playlistManager->getPlaylistById(playlistId); // Use the playlist manager to get and return the specified playlist by its ID
    }

    // pause any song that is currently playing
    void pause()
    {
        facade->pause(); // Use the music player facade to pause the currently playing song
    }
};

#endif // MUSIC_PLAYER_APPLICATION_H