#include <iostream>
#include "Song.hpp"
#include "Playlist.hpp"

int main(){
    Playlist p1("Your likes", "Kaloyan");
    p1.addSong(Song("Turn Up!", "Big Naughty", 405));
    Playlist p2 = p1;
    Song s1("B.O.T.B.", "Gaeko, CHANGMO, Don Mills & Los", 266);
    p2.addSong(s1);
    p2.addSong(Song("VENI VIDI VICI", "ZICO", 194));
    Playlist p3("sdfsdf", "sdfsdf");
    p3 = p2;
    p3.printPlaylist();
    p3.moveSong(p1, "VENI VIDI VICI", "ZICO");
    p3.printPlaylist();
    p1.printPlaylist();
    return 0;
}