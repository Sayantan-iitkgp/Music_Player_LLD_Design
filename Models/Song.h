#ifndef SONG_H
#define SONG_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define st string

class Song
{
private:
    ll id; // Unique identifier for each song
    st name;
    st artist;
    ll duration; // in seconds
    ll releaseYear;
    st path;

public:
    // Define operator< for use in set/map (compare by id)
    Song() = default;
    bool operator<(const Song& other) const {
        return id < other.id;
    }
    
    Song(st name, st artist, ll duration, ll releaseYear, st path, ll id)
    {
        this->id = id;
        this->name = name;
        this->artist = artist;
        this->duration = duration;
        this->releaseYear = releaseYear;
        this->path = path;
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
    st getArtist() 
    {
        return artist;
    }
    ll getDuration() 
    {
        return duration;
    }
    ll getReleaseYear() 
    {
        return releaseYear;
    }
    st getPath() 
    {
        return path;
    }
};

#endif // SONG_H