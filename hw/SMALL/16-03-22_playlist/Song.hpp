#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class Song{
    //TODO add name, artist and length in seconds
    char *name;
    char *artist;
    size_t length;

public:
    /**
     * @brief Construct a new Song object
     * 
     */
    Song();

    /**
     * @brief Construct a new Song object
     * 
     * @param name needs validation
     * @param artist needs validation
     * @param length 
     */
    Song(const char *name, const char *artist, size_t length); //DON'T USE ASSERT, USE IF ELSE

    /**
     * @brief Construct a new Song object (Copy constructor)
     * 
     * @param other 
     */
    Song(const Song &rhs);

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Song& 
     */
    Song &operator=(const Song &rhs);

    /**
     * @brief Destroy the Song object
     * 
     */
    ~Song();

    //Add getters and setters

    // setters

    void setName(const char *name);
    void setArtist(const char *artist);
    void setLength(size_t length);

    // getters

    char *getName() const;
    char *getArtist() const;
    size_t getLength() const;
    void printSong() const;
};