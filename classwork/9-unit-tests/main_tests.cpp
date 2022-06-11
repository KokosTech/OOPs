#define CATCH_CONFIG_MAIN 

#include <cstring>

#include "catch2.hpp"
#include "main.cpp"

TEST_CASE("Constructor with parameters") {
    Song s1("test", "artist", 180);

    SECTION("Valid arguments provided") {
        Song s("test", "artist", 180);

        REQUIRE(strcmp(s.getName(), "test") == 0);
    }

    SECTION("Invalid arguments provided") {
        Song *s;

        REQUIRE_THROWS(s = new Song(nullptr, "test", 100));
        REQUIRE_THROWS_WITH(s = new Song(nullptr, "test", 100), "Song name cannot be empty");
    }

}

TEST_CASE("Add song") {
    SECTION("Valid arguments") {
        Playlist p("test", "test");

        REQUIRE(p.addSong(Song("test", "artist", 180)) == 0);
    }

    SECTION("Invalid arguments") {
        Playlist p("test", "test");

        p.addSong(Song("same", "artist", 180));
        REQUIRE_THROWS(p.addSong(Song("same", "artist", 180)));
    }
}

TEST_CASE("Remove song") {
    SECTION("Valid arguments") {
        Playlist p("test", "test");

        p.addSong(Song("test", "artist", 180));

        REQUIRE(p.removeSong("test", "artist") == 0);
    }

    SECTION("Invalid arguments") {
        Playlist p("test", "test");

        REQUIRE_THROWS(p.removeSong("name", "artist"));
    }
}