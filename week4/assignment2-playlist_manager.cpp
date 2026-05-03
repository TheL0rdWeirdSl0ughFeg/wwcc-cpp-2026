#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

struct Artist {
    string name;
    string hometown;
};

struct Song {
    string title;
    Artist artist;
    string genre;
    int durationSeconds;
};

string formatDuration(int seconds);
void songInfo(const Song& song);
string toLower(string text);

int main(){
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    Song playlist[5];
    int total = 0;
    int longest = 0;

    cout << "PERSONAL PLAYLIST MANAGER" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Enter information for Song " << i + 1 << ": " << endl;
        cout << "Title: ";
        getline(cin, playlist[i].title);
        cout <<  "Artist name: " ;
        getline(cin, playlist[i].artist.name);
        cout << "Artist hometown: ";
        getline(cin, playlist[i].artist.hometown);
        cout << "Genre: ";
        getline(cin, playlist[i].genre);
        cout << "Duration (seconds): ";
        cin >> playlist[i].durationSeconds;
        cin.ignore(1000, '\n');
        cout << endl;

    }

    cout << "YOUR PLAYLIST" << endl;
    cout << "-----------------" << endl;

    for (int i = 0; i < 5; i++) {
        songInfo(playlist[i]);
        cout << endl;

        total += playlist[i].durationSeconds;

        if (playlist[i].durationSeconds > playlist[longest].durationSeconds) {
            longest = i;
        }
    }

    cout << "Total playlist runtime: " << formatDuration(total) << endl;
    cout << endl;

    cout << "Longest song:" << endl;
    songInfo(playlist[longest]);
    cout << endl;

    string artistName;

    cout << "Enter an artist name to search: ";
    getline(cin, artistName);

    bool found = false;
    string searchName = toLower(artistName);

    cout << "Songs by " << artistName << ":" << endl;
    for (int i = 0; i < 5; i++) {
        if (toLower(playlist[i].artist.name) == searchName) {
            songInfo(playlist[i]);
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found for that artist." << endl;
    }

    cout << endl;

    string genreName;
    cout << "Enter a genre to search: ";
    getline(cin, genreName);

    found = false;
    string genreSearch = toLower(genreName);

    cout << "Songs in genre " << genreSearch << ":" << endl;
    for (int i = 0; i < 5; i++) {
        if (toLower(playlist[i].genre) == genreSearch) {
            songInfo(playlist[i]);
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found for that genre." << endl;
    }

    return 0;
}

string formatDuration(int seconds) {
    int minutes = seconds / 60;
    int remainder = seconds % 60;

    if (remainder < 10) {
        return to_string(minutes) + ":0" + to_string(remainder);
    }

        return to_string(minutes) + ":" + to_string(remainder);
}

void songInfo(const Song& song) {
    cout << "Title: " << song.title << endl;
    cout << "Artist: " << song.artist.name << endl;
    cout << "Hometown: " << song.artist.hometown << endl;
    cout << "Genre: " << song.genre << endl;
    cout << "Duration: " << formatDuration(song.durationSeconds) << endl;
}

string toLower(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}