#include "Song.hpp"

Song::Song() {
    this->name = nullptr;
    this->artist = nullptr;
    this->length = 0;
}

Song::Song(const char *name, const char *artist, size_t length)
    : length(length){
    if(!name || !artist) return;

    this->name = strdup(name);
    this->artist = strdup(artist);
}

Song::Song(const Song &rhs){
    this->name = strdup(rhs.name);
    this->artist = strdup(rhs.artist);
    this->length = rhs.length;
}

Song &Song::operator=(const Song &rhs){
    if(this != &rhs){
        delete[] this->name;
        delete[] this->artist;

        this->name = strdup(rhs.name);
        this->artist = strdup(rhs.artist);
        this->length = rhs.length;
    }
    return *this;
}

Song::~Song(){
    delete[] this->name;
    delete[] this->artist;
}

// setters

void Song::setName(const char *name){
    if(!name) return;
    if(this->name) delete[] this->name;
    this->name = strdup(name);
}

void Song::setArtist(const char *artist){
    if(!artist) return;
    if(this->artist) delete[] this->artist;
    this->artist = strdup(artist);
}

void Song::setLength(size_t length){
    this->length = length;
}

// getters

char *Song::getName() const {
    return this->name;
}

char *Song::getArtist() const {
    return this->artist;
}

size_t Song::getLength() const {
    return this->length;
}

void Song::printSong() const {
    cout << "-----------------------------" << endl;
    cout << "Artist: " << this->artist << endl;
    cout << "Song title: " << this->name << endl;
    cout << "Song lenght: " << this->length << endl;
} 