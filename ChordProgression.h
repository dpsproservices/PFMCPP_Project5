/******************************************************************
    ChordProgression.h

    structure to encapsulate a chord progression across the guitar fretboard
******************************************************************/
#pragma once
#include "LeakedObjectDetector.h"
#include "Defines.h"
#include "Chord.h"
#include "Fretboard.h"

struct ChordProgression
{
    int numChords;
    Chord chords[NUM_CHORDS];
    Fretboard fretboard;

    ChordProgression();
    ~ChordProgression();

    void setChords();
    void printChords();

    void play();
    void playOctave();
    void printNumChords();

    JUCE_LEAK_DETECTOR(ChordProgression)
};
