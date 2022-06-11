#include <iostream>
#include <cstring>

using namespace std;

class Song {
    private:
        char *name;
        char *artist;
        size_t length;

    public:
        /**
         * @brief Construct a new Song object
         * 
         */

        Song()
        : name(nullptr), artist(nullptr), length(0) { }

        /**
         * @brief Construct a new Song object
         * 
         * @param name needs validation
         * @param artist needs validation
         * @param length 
         */

        Song(const char* name, const char *artist, size_t length) //DON'T USE ASSERT, USE IF ELSE
        : length(length) {
            try {
                if(!artist || !name) 
                    throw invalid_argument("Name / artist not given!");

                this->name = strdup(name);
                this->artist = strdup(artist);
            } catch(invalid_argument& e) {
                cerr << e.what() << endl;
            }

        }

        /**
         * @brief Construct a new Song object (Copy constructor)
         * 
         * @param other 
         */

        Song(const Song &other) {
            this->name = strdup(other.name);
            this->artist = strdup(other.artist);
            this->length = other.length;
        }

        /**
         * @brief Destroy the Song object
         * 
         */

        ~Song() {
            delete[] this->name;
            delete[] this->artist;
        }

        /**
         * @brief Assign operator
         * 
         * @param other 
         * @return Song& 
         */

        Song &operator=(const Song &other) {
            if(this != &other) {
                delete[] this->name;
                delete[] this->artist;

                this->name = strdup(other.name);
                this->artist = strdup(other.artist);
                this->length = other.length;
            } return *this;
        }

        // setters

        void setName(const char *name) { this->name = strdup(name); }
        void setArtist(const char *artist) { this->artist = strdup(artist); }
        void setLength(size_t length) { this->length = length; }

        // getters

        char *getName() const { return this->name; }
        char *getArtist() const {return this->artist; }
        size_t getLength() const { return this->length; }

};

class Playlist {
    private:

        char *name;
        const char *owner;

        size_t songCount;
        size_t capacity;
        Song *songs;


        void resize() { 
            this->capacity *= 2;
            Song *new_arr = new Song[this->capacity];

            for(int i = 0; i < this->songCount; ++i)
                new_arr[i] = this->songs[i];

            delete [] this->songs;
            this->songs = new_arr;
        }

        void shiftLeft(size_t index) {
            try {
                if(index > this->songCount) 
                    throw out_of_range("Index out of range!");

                for(int i = index; i < this->songCount - 1; ++i)
                    this->songs[i] = this->songs[i + 1];

                --this->songCount;
            } catch(const out_of_range &e) {
                cerr << e.what() << endl;
            }
        }

    public:
        static size_t playlistCount;

        /**
         * @brief Construct a new Playlist object
         * 
         * @param name 
         * @param owner 
         */

        Playlist(const char* name, const char* owner) {
            try{
                if(!name || !owner) 
                    throw invalid_argument("Name / owner not given!");

                ++playlistCount;

                this->name = strdup(name);
                this->owner = strdup(owner);

                this->songCount = 0;
                this->capacity = 2;
                this->songs = new Song[this->capacity];
            } catch(const invalid_argument &e) {
                cerr << e.what() << endl;
            }
        }

        /**
         * @brief Construct a new Playlist object
         * 
         * @param other 
         */

        Playlist(const Playlist &other) {
            ++this->playlistCount;
            this->name = strdup(other.name);
            this->owner = strdup(other.owner);

            this->songCount = other.songCount;
            this->capacity = other.capacity;
            this->songs = new Song[this->capacity];

            for(size_t i = 0; i < other.songCount; ++i)
                this->songs[i] = other.songs[i];
        }

        ~Playlist() {
            --playlistCount;

            delete[] this->name;
            delete[] this->owner;

            delete[] this->songs;
        }

        /**
         * @brief Assign operator
         * 
         * @param other 
         * @return Playlist& 
         */

        Playlist &operator=(const Playlist &other){
            if(this != &other){
                delete [] this->name;
                delete [] this->owner;


                this->name = strdup(other.name);
                this->owner = strdup(other.owner);

                this->songCount = other.songCount;
                this->capacity = other.capacity;

                delete [] this->songs;

                this->songs = new Song[this->capacity];

                for(size_t i = 0; i < other.songCount; ++i)
                    this->songs[i] = other.songs[i];
            }
            return *this;
        }

        /**
         * @brief Adding song to the playlist. Check if song with this name and artist exists. If exists return -1
         * 
         * @param other 
         * @return int 
         */

        int addSong(const Song &other) {
            try {
                for(int i = 0; i < this->songCount; ++i)
                    if (!strcmp(this->songs[i].getName(), other.getName()) 
                    && !strcmp(this->songs[i].getArtist(), other.getArtist()))
                        throw invalid_argument("Song already exists in the playlist");

                if(this->songCount == this->capacity) this->resize();

                this->songs[this->songCount] = other;
                ++this->songCount;

                return 0;
            } catch(const invalid_argument &e) {
                cerr << e.what() << endl;
                return -1;
            }
        }

        /**
         * @brief Remove song from the playlist. Check if song with this name and artist exists. If exists return -1
         * 
         */

        int removeSong(const char *name, const char *artist) {
            try {
                for(int i = 0; i < this->songCount; ++i) {
                    if(this->songs[i].getName() == name 
                    && this->songs[i].getArtist() == artist) {
                        this->shiftLeft(i);
                        this->songCount--;
                        throw invalid_argument("Song not found in the playlist");
                    }
                }
                return 0;
            } catch(const invalid_argument &e) {
                cerr << e.what() << endl;
                return -1;
            }
        }

        /**
         * @brief Moving a song from one playlist to another. Check if the song exists in the current playlist. If exists return -1
         * 
         * @param other 
         * @param name 
         * @param artist 
         * @return int 
         */

        int moveSong(Playlist &other, const char *name, const char *artist) {
            try {
                size_t length;
                
                for(int i = 0; i < other.songCount; ++i) {
                    if(strcmp(this->songs[i].getName(), name) 
                    && strcmp(this->songs[i].getArtist(), artist)) {
                        length = this->songs[i].getLength();
                        throw invalid_argument("Song not found in the playlist");
                    }
                }

                Song* new_song = new Song(name, artist, length);
                other.removeSong(name, artist);
                this->addSong(*new_song);

                return 0;
            } catch(const invalid_argument &e) {
                cerr << e.what() << endl;
                return -1;
            }
        }

        // getters

        /**
         * @brief Get the Song object
         * 
         * @param name 
         * @param artist 
         * @return Song& 
         */

        Song &getSong(const char *name, const char *artist) const {
            for (int i = 0; i < this->songCount; i++)
                if(!strcmp(this->songs[i].getName(), name)
                && !strcmp(this->songs[i].getArtist(), artist))
                    return songs[i];
        }
        
        const char *getName() const { return this->name; }
        const char *getOwner() const { return this->owner; }
        size_t getSongsCount() const { return this->songCount; }

        static size_t getPlaylistCount() { return playlistCount; }
};

size_t Playlist::playlistCount = 0;

/* int main(int argc, char* argv[]){
    Song s1("song1", "artist1", 20);
    Song s2("song2", "artist2", 30);

    Playlist p1("Playlist1", "owner1");
    p1.addSong(s1);
    p1.addSong(s2);
    cout << p1.getSongsCount() << endl;
    
    Song s3 = p1.getSong("song2", "artist2");

    Playlist p2("Playlist2", "owner2");
    Playlist p = p1;
    p2 = p;

    cout << "WTH: " <<  p1.moveSong(p2, "song not found lol", "artist not found lol") << endl;

    cout << "TEST: " << p2.getOwner() << endl;

    cout << s3.getName() << endl << s3.getArtist() << endl << s3.getLength() << endl;
    
    cout << "Playlist count: " << Playlist::getPlaylistCount() << endl;

    return 0;
} */