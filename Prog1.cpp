#include "VideoGameLibrary.h"
using namespace std;

int main()
{
    
    int maxGames;
    int input = 1;
    cout << "How many video games can your library hold?" << endl;
    cin >> maxGames;

    VideoGameLibrary* newLibrary = new VideoGameLibrary(maxGames);

    while (input != 6)
    {   
        cout<< "What would you like to do?" << endl;
        cout<< "1.  Load video games from file." << endl;
        cout<< "2.  Save video games to a file." << endl;
        cout<< "3.  Add a video game." << endl;
        cout<< "4.  Remove a video game." << endl;
        cout<< "5.  Display all video games." << endl;
        cout<< "6.  Remove ALL video games from this library and end program." << endl;
        cout << "CHOOSE 1-6: "<< endl;
        cin >> input;



        cin.ignore();
        char  string[100];
        switch (input)
        {
        case 1:
            cout << "What file are you wanting to load?" << endl;
            cin.getline(string, 100,'\n');
            newLibrary->loadVideoGamesFromFile(string);
            break;
        case 2:
            cout << "What file are you wanting to load?";
            cin.getline(string, 100,'\n');
            newLibrary->saveToFile(string);
            break;

        case 3: 
            newLibrary->addVideoGameToArray();
            break;

        case 4:
            newLibrary->removeVideoGameFromArray();
            break;

        case 5:
            newLibrary->displayVideoGames();
            break;    
        default:
            break;
        }
    }
    newLibrary->~VideoGameLibrary();
    delete newLibrary;

}

