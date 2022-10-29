#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"

class VideoGameLibrary
{
private:
    VideoGame* *videoGamesArray;
    int maxGames;
    int numGames;

public:
    VideoGameLibrary();
    VideoGameLibrary(int maxGames);
    ~VideoGameLibrary();
    void resizeVideoGameArray();
    void addVideoGameToArray();
    void displayVideoGames();
    void displayVideoGameTitles();
    void loadVideoGamesFromFile(char* fileName);
    void removeVideoGameFromArray();
    void saveToFile(char* fileName);
};






#endif