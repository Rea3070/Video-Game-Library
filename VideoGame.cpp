#include <iostream>
#include <cstring>
#include <iomanip>
#include "Text.h"
#include "VideoGame.h"

using namespace std;

VideoGame::VideoGame(Text* t, Text* d, Text* p, int y)
{
    title = t; 
    developer = d;
    publisher = p;
    year = y;

};



VideoGame::~VideoGame()
{
    cout<<"VideoGame destructor: Released memory for title, developer, & publisher." << endl;
    title->~Text();
    developer->~Text();
    publisher->~Text();
    
}

void VideoGame::printVideoGameDetailsToFile(ofstream &outFile)
{
    const char *fileTitle = title->getText();
    const char *fileDev = developer->getText();
    const char *filePublish = publisher->getText();

    outFile<<"Title:     "<< fileTitle  <<endl;
    outFile<<"Developer: "<< fileDev   <<endl;
    outFile<<"Publisher: "<< filePublish  <<endl;
    outFile<<"Year:      "<< year <<endl;
}

void VideoGame::printVideoGameDetails(){

    cout << "Title:     ";
    title->displayText();
    cout << endl;
    cout << "Developer: ";
    developer->displayText();
    cout << endl;
    cout << "Publisher: ";
    publisher->displayText();
    cout << endl;
    cout << "Year:      "<< year <<endl;
}



Text* VideoGame::getVideoGameTitle()
{
    return title;
}