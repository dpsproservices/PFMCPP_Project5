/******************************************************************
    Fretboard.h

    structure to encapsulate a guitar fretboard
******************************************************************/
#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Defines.h"
#include "GuitarString.h"
#include "Chord.h"
#include "Fretboard.h"

struct Fretboard
{   
    int numNotesFretted;
    int octave;
    Chord chord;

    GuitarString strings[NUM_STRINGS];

    Fretboard();
    ~Fretboard();

    void setChord(Chord c);
    void raiseOctave();

    void printTab();
    void reset();
    void printNumNotes();

    JUCE_LEAK_DETECTOR(Fretboard)
};
