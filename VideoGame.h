#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Text.h"

class VideoGame
{
private:
    Text *title, *developer, *publisher;
    int year;
public:
    //constructor
    VideoGame();
    VideoGame(Text *title, Text *developer, Text *publisher, int year);
    //deconstructor
    ~VideoGame();
    void printVideoGameDetails();
    void printVideoGameDetailsToFile(ofstream &outFile);
    Text* getVideoGameTitle();
};


#endif