
#include "VideoGameLibrary.h"

using namespace std;


VideoGameLibrary::VideoGameLibrary(int mGames)
{
    maxGames = mGames;
    videoGamesArray = new VideoGame*[maxGames];
    cout << "max: " << maxGames << endl;
    numGames = 0;
}

VideoGameLibrary::~VideoGameLibrary()
{
    for (size_t i = 0; i <= maxGames; i++)
    {
        videoGamesArray[i]->~VideoGame();
    }
    delete [] videoGamesArray;
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
}

void VideoGameLibrary::displayVideoGames()
{
    for (size_t i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetails();
    }
}

void VideoGameLibrary::displayVideoGameTitles()
{
    for (size_t i = 0; i < numGames; i++)
    {
        Text* gameTitle = videoGamesArray[i]->getVideoGameTitle();
        cout << i + 1 << ": ";
        gameTitle->displayText();
        cout << endl;    
    }
}



void VideoGameLibrary::loadVideoGamesFromFile(char* fileName)
{
   
    ifstream inFile;
    inFile.open(fileName);
    


    char text[1000000];
    int yearReleased = 0;
    int total = 0;
    
    while (inFile.good())
    {
        inFile.getline(text, 1000000);
        Text *title = new Text(text);
        cout << "title" << endl;


        inFile.getline(text, 1000000);
        Text *developer = new Text(text);
        cout << "title2" << endl;


        inFile.getline(text, 1000000);
        Text *publisher = new Text(text); 
        cout << "title3" << endl;


        inFile >> yearReleased;
        inFile.ignore();
        cout << "title4" << endl;

        VideoGame *newGame = new VideoGame(title, developer, publisher, yearReleased);

        if (numGames == maxGames)
        {
            resizeVideoGameArray(); 
        }
        videoGamesArray[numGames] = newGame;
        numGames++;

        total++;
    }
    cout << total << " games were added to the library." << endl;
    inFile.close();
}

void VideoGameLibrary::saveToFile(char* fileName)
{
    ofstream theFile;
    theFile.open(fileName);
    for (size_t i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetailsToFile(theFile);
    }
    theFile.close();

    cout << "All video games printed to " << fileName << "." << endl;
}

void VideoGameLibrary::resizeVideoGameArray()
{
    maxGames = maxGames * 2;
    VideoGame* *newVideoGamesArray = new VideoGame*[maxGames];
    
    for (size_t i = 0; i < numGames; i++)
    {
        newVideoGamesArray[i] = videoGamesArray[i];
    }
    delete [] videoGamesArray;
    videoGamesArray = newVideoGamesArray;
    cout << "Resized." << endl;
}

void VideoGameLibrary::addVideoGameToArray()
{
    char text[100000];
    int yearReleased = 0;

    
    cout <<"Title:        ";
    cin.getline(text, 100000, '\n');
    cout << text <<endl;
    Text *title = new Text(text);

    cout <<"Developer:    ";
    cin.getline(text, 100000, '\n');
    cout << text <<endl;
    Text *developer = new Text(text);

    cout <<"Publisher:    ";
    cin.getline(text, 100000, '\n');
    cout << text <<endl;
    Text *publisher = new Text(text); 

    cout <<"Year Released:";
    cin >> yearReleased;
    cout << text <<endl;
    cin.ignore();

    VideoGame *newGame = new VideoGame(title, developer, publisher, yearReleased);


    if (numGames == maxGames)
    {
        resizeVideoGameArray(); 
    }
    
    
    videoGamesArray[numGames] = newGame;
    
    numGames++;
    

}


void VideoGameLibrary::removeVideoGameFromArray()
{
    if (numGames < 1)
    {
        cout <<"There must always be 1 game in the library or you'll get bored." << endl;
        return;
    }

    displayVideoGameTitles();

    int pos;
    cout << "Choose a game to remove between 1 and " << numGames;
    cin >> pos;
    pos = pos - 1;
    Text* title = videoGamesArray[pos]->getVideoGameTitle();
    title->displayText();
    cout << "has been deleted." << endl;
    videoGamesArray[pos]->~VideoGame();
    for (size_t i = pos; i < numGames+1; i++)
    {
        videoGamesArray[i] = videoGamesArray[i+1];
    }
    numGames--;
}
