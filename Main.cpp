#include <bits/stdc++.h>
#include "Music_Player_Application.h"
using namespace std;

int main()
{
    Music_Player_Application *app = new Music_Player_Application(); // Create an instance of the music player application

    // Create some songs
    app->create_song("Shape of You", "Ed Sheeran", 240, 2017, "/path/to/shape_of_you.mp3");
    app->create_song("Blinding Lights", "The Weeknd", 200, 2019, "/path/to/blinding_lights.mp3");
    app->create_song("Levitating", "Dua Lipa", 220, 2020, "/path/to/levitating.mp3");
    app->create_song("Gehra_hua", "Arijit Singh", 300, 2025, "/path/to/gehra_hua.mp3");
    app->create_song("Kesariya", "Arijit Singh", 250, 2022, "/path/to/kesariya.mp3");
    app->create_song("Abhi_mujh_mein_kahin", "Sonu Nigam", 280, 2006, "/path/to/abhi_mujh_mein_kahin.mp3");

    // Create some playlists
    app->create_playlist("My Favorites");
    app->create_playlist("Chill Vibes");
    // Add songs to playlists
    app->add_song_to_playlist(1, Song("Shape of You", "Ed Sheeran", 240, 2017, "/path/to/shape_of_you.mp3", 1));
    app->add_song_to_playlist(1, Song("Blinding Lights", "The Weeknd", 200, 2019, "/path/to/blinding_lights.mp3", 2));
    app->add_song_to_playlist(2, Song("Levitating", "Dua Lipa", 220, 2020, "/path/to/levitating.mp3", 3));
    app->add_song_to_playlist(2, Song("Gehra_hua", "Arijit Singh", 300, 2025, "/path/to/gehra_hua.mp3", 4));
    app->add_song_to_playlist(2, Song("Kesariya", "Arijit Singh", 250, 2022, "/path/to/kesariya.mp3", 5));
    app->add_song_to_playlist(1, Song("Abhi_mujh_mein_kahin", "Sonu Nigam", 280, 2006, "/path/to/abhi_mujh_mein_kahin.mp3", 6));

    // Set audio output device
    app->set_audio_output_device("headphones");
    // Play a single song
    Song *songToPlay = new Song("Galti_se_mistake", "ABCD", 210, 2023, "/path/to/galti_se_mistake.mp3", 7);
    app->play_song(songToPlay);

    // Play a playlist in sequential order
    app->play_playlist_forward(1, "sequential");
    app->play_playlist_backward(1, "sequential");
    // Play a playlist in random order
    app->play_playlist_forward(2, "random");
    app->play_playlist_backward(2, "random");
    // Play a playlist in custom order
    vector<Song> customOrder = {
        Song("Kesariya", "Arijit Singh", 250, 2022, "/path/to/kesariya.mp3", 5),
        Song("Gehra_hua", "Arijit Singh", 300, 2025, "/path/to/gehra_hua.mp3", 4),
        Song("Levitating", "Dua Lipa", 220, 2020, "/path/to/levitating.mp3", 3)};

    app->play_playlist_forward(2, "custom", customOrder);
    app->play_playlist_backward(2, "custom", customOrder);

    //remove a song from a playlist
    app->remove_song_from_playlist(2, Song("Kesariya", "Arijit Singh", 250, 2022, "/path/to/kesariya.mp3", 5));
    //delete a song from the music player and all playlists containing it
    app->delete_song(Song("Abhi_mujh_mein_kahin", " Sonu Nigam", 280, 2006, "/path/to/abhi_mujh_mein_kahin.mp3", 6));

    //Now play a playlist after removing a song and deleting a song to see the changes
    app->play_playlist_forward(1, "sequential");
    app->play_playlist_forward(2, "sequential");


    // Demonstrate pausing a song
    app->play_song(songToPlay); // Play the song again to demonstrate pausing
    app->pause();               // Pause the currently playing song

    //delete all songs and playlists to clean up
        app->delete_song(Song("Shape of You", "Ed Sheeran", 240, 2017, "/path/to/shape_of_you.mp3", 1));
        app->delete_song(Song("Blinding Lights", "The Weeknd", 200, 2019, "/path/to/blinding_lights.mp3", 2));
        app->delete_song(Song("Levitating", "Dua Lipa", 220, 2020, "/path/to/levitating.mp3", 3));
        app->delete_song(Song("Gehra_hua", "Arijit Singh", 300, 2025, "/path/to/gehra_hua.mp3", 4));
        app->delete_song(Song("Kesariya", "Arijit Singh", 250, 2022, "/path/to/kesariya.mp3", 5));
        app->delete_song(Song("Abhi_mujh_mein_kahin", "Sonu Nigam", 280, 2006, "/path/to/abhi_mujh_mein_kahin.mp3", 6));
        app->delete_song(Song("Galti_se_mistake", "ABCD", 210, 2023, "/path/to/galti_se_mistake.mp3", 7));
    
    //delete playlists
    Playlist* playlist1 = app->get_playlist_by_id(1);
    if (playlist1 != nullptr)
    {
        app->delete_playlist(1);
    }
    Playlist* playlist2 = app->get_playlist_by_id(2);
    if (playlist2 != nullptr)
    {
        app->delete_playlist(2);
    }

    //delete the music player application instance to free up resources
    delete app;

    return 0;
}