/******************************************************************
    Note.h

    structure to encapsulate a note on the guitar fretboard
******************************************************************/
#pragma once
#include "LeakedObjectDetector.h"
#include "Defines.h"

struct Note
{
    int stringNum;
    int fretNum;
    Finger finger;
    char key; 
    
    Note();
    Note(int str, int fret, Finger digit, char note);
    ~Note();

    // Note operator=(const Note & n);

    int getStringNum();
    void setStringNum(int stringNum);
    int getFretNum();
    void setFretNum(int fret);
    Finger getFinger();
    void setFinger(Finger finger);
    char getKey();
    void setKey(char key);

    char getNextTone();
    char getKeyByInternal(int interval);
    void printCycle(int interval);

    char getTab();
    void printKey();
    void printFinger();
    void printFretNum();
    void printStringNum();

    JUCE_LEAK_DETECTOR(Note)
};
