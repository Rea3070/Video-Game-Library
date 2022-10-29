#include "Text.h"
#include <cstring>
#include <iomanip>
using namespace std;


Text::Text(const char *arrayA)
{
    //int i = 0;
    //while (arrayA[i] != 0)
    //{
    //    i++;
    //}
    //textLength = i;

    textLength = strlen(arrayA);

    char *arrayB = new char[textLength+1];
    strcpy(arrayB, arrayA);
    
    textArray = arrayB;
};
    
Text::~Text()
{
    delete[] textArray;
    cout << "Text destructor: Released memory for textArray." << endl;
}

void Text::displayText()
{
    cout << textArray;
}

const char *Text::getText()
{
    return textArray;
}

int Text::getLength()
{
    return textLength;
}
