#include "Playlist.hpp"

void Playlist::resize(){
    Song *newSongs = new Song[this->capacity * 2];

    for (size_t i = 0; i < this->songCount; i++)
        newSongs[i] = this->songs[i];

    delete[] this->songs;
    this->songs = newSongs;
    this->capacity *= 2;
}

int Playlist::indexSong(const char *name, const char *artist) const{
    if (!name || !artist) return -1;

    for (int i = 0; i < this->songCount; i++)
        if(!strcmp(this->songs[i].getName(), name)
        && !strcmp(this->songs[i].getArtist(), artist))
            return i;

    return -1;
}

Playlist::Playlist(const char* name, const char* owner){
    if(!name || !owner) return;

    this->name = strdup(name);
    this->owner = strdup(owner);
    this->songCount = 0;
    this->capacity = 2;
    this->songs = new Song[this->capacity];
}

Playlist::Playlist(const Playlist &other){
    this->name = strdup(other.name);
    this->owner = strdup(other.owner);
    this->songCount = other.songCount;
    this->capacity = other.capacity;
    this->songs = new Song[this->capacity];

    for(size_t i = 0; i < other.songCount; i++)
        this->songs[i] = other.songs[i];
}

Playlist &Playlist::operator=(const Playlist &other){
    if(this != &other){
        delete [] this->name;
        delete [] this->owner;
        this->name = strdup(other.name);
        this->owner = strdup(other.owner);

        this->songCount = other.songCount;
        this->capacity = other.capacity;

        delete [] this->songs;

        this->songs = new Song[this->capacity];

        for(size_t i = 0; i < other.songCount; i++)
            this->songs[i] = other.songs[i];
    }
    return *this;
}

Playlist::~Playlist(){
    delete [] this->name;
    delete [] this->owner;
    delete [] this->songs;
}

int Playlist::addSong(const Song &other){
    if(this->indexSong(other.getName(), other.getArtist()) != -1) return -1;
    if(this->songCount >= this->capacity) this->resize();

    this->songs[this->songCount++] = other;
    return 0;
}

int Playlist::removeSong(const char* name, const char* artist){
    if(!name || !artist) return -1;

    int index = this->indexSong(name, artist);
    if(index == -1) return -1;

    for(int i = index; i < this->songCount - 1; ++i)
        this->songs[i] = this->songs[i + 1];

    --this->songCount;
    return 0;
}

int Playlist::moveSong(Playlist &other, const char* name, const char* artist){
    if(!name || !artist) return -1;

    int indx = this->indexSong(name, artist);
    if(indx == -1 || other.indexSong(name, artist) != -1) return -1;

    Song song = this->songs[indx];
    this->removeSong(name, artist);
    other.addSong(song);
    return 0;
}

int Playlist::moveSongTo(Playlist &other, const char* name, const char* artist){
    if(!name || !artist) return -1;

    int indx = other.indexSong(name, artist);
    if(indx == -1 || this->indexSong(name, artist) != 1) return -1;

    Song song = other.songs[indx];
    other.removeSong(name, artist);
    this->addSong(song);
    return 0;
}

Song& Playlist::getSong(const char* name, const char* artist)const{
    int indx = this->indexSong(name, artist);
    if(indx != -1) return this->songs[indx];}

char *Playlist::getName() const{ 
    return this->name;
}

char *Playlist::getOwner() const{ 
    return this->owner;
}

size_t Playlist::getSongsCount() const{
    return this->songCount;
}

void Playlist::printPlaylist() const{
    cout << "Playlist: " << this->name << endl;
    cout << "Owner: " << this->owner << endl;
    cout << "Songs: " << this->songCount << endl;
    cout << "Capacity: " << this->capacity << endl;
    cout << "Songs: " << endl;
    for(size_t i = 0; i < this->songCount; i++)
        songs[i].printSong();
    cout << "==========================" << endl;
}