#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
class Text
{
private:
    const char *textArray;
    int textLength;
public:
    //constructor
    Text();
    Text(const char *arrayA);
    //decontructor
    ~Text();
    //displays the text
    void displayText();
    //gets the text
    const char *getText();
    //gets the length of text
    int getLength();
};
#endif
