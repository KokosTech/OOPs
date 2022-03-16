#pragma once
#include<iostream>
#include<cstring>
#include "Song.hpp"

class Playlist{
    char* name;
    char* owner;
    size_t songCount;
    
    size_t capacity;
    Song *songs;

    void resize();
    int indexSong(const char *name, const char *artist) const;
public:

    /**
     * @brief Construct a new Playlist object
     * 
     * @param name 
     * @param owner 
     */
    Playlist(const char* name, const char* owner);

    /**
     * @brief Construct a new Playlist object
     * 
     * @param other 
     */
    Playlist(const Playlist &other);

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Playlist& 
     */
    Playlist &operator=(const Playlist &other);

    ~Playlist();

    /**
     * @brief Adding song to the playlist. Check if song with this name and artist exists. If exists return -1
     * 
     * @param other 
     * @return int 
     */
    int addSong(const Song &other);

    /**
     * @brief Remove song from the playlist. Check if song with this name and artist exists. If exists return -1
     * 
     */
    int removeSong(const char* name, const char* artist);

    /**
     * @brief Moving a song from one playlist to another. Check if the song exists in the current playlist. If exists return -1
     * 
     * @param other 
     * @param name 
     * @param artist 
     * @return int 
     */
    int moveSong(Playlist &other, const char* name, const char* artist);
    int moveSongTo(Playlist &other, const char* name, const char* artist);

    /**
     * @brief Get the Song object
     * 
     * @param name 
     * @param artist 
     * @return Song& 
     */
    Song& getSong(const char* name, const char* artist)const;


    /*
        Getters
    */
    char *getName() const;
    char *getOwner() const;
    size_t getSongsCount() const;
    void printPlaylist() const;
};