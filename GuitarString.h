/******************************************************************
    GuitarString.h

    structure to encapsulate a note on the guitar string
******************************************************************/
#pragma once
#include "LeakedObjectDetector.h"
#include "Defines.h"
#include "Note.h"
#include "GuitarString.h"

struct GuitarString
{
    int stringNum;
    int numFrets;
    char openStringKey;
    char frettedKey;

    int frettedNum;

    Note note;

    GuitarString();
    GuitarString(int stringNum);
    ~GuitarString();

    int getStringNum();
    void setStringNum(int stringNum);

    int getNumFrets();
    char getOpenStringKey();

    void setFrettedKey(char key);
    char getFrettedKey();

    char getOpenString(int stringNum);

    int getFrettedNum();
    void setFrettedNum(int fretNum);

    //Note getNote();
    void setNote(Note note);

    void printGuitarString();

    JUCE_LEAK_DETECTOR(GuitarString)
};
