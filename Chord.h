/******************************************************************
    Chord.h

    structure to encapsulate a chord on the guitar fretboard
******************************************************************/
#pragma once
#include "LeakedObjectDetector.h"
#include "Defines.h"
#include "Note.h"

struct Chord
{
    int numNotes;
    int numFingers;

    Note notes[NUM_STRINGS];
    bool isBarred;

    Chord();
    ~Chord();

    // Chord operator=(const Chord & c);

    int getNumNotes();
    void setNumNotes(int num);

    int getNumFingers();
    void setNumFingers(int digits);

    void setNote(Note note);
    void resetChord();

    void printChord();

    bool getIsBarred();
    void setIsBarred();

    JUCE_LEAK_DETECTOR(Chord)
};
