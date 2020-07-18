/******************************************************************
    Wrapper.h

    Define Wrapper structures
******************************************************************/
#pragma once
#include "LeakedObjectDetector.h"
#include "Note.h"
#include "GuitarString.h"
#include "Chord.h"
#include "Fretboard.h"
#include "ChordProgression.h"

struct NoteWrapper 
{
    NoteWrapper( Note* notePtr ) : ptrToNote(notePtr) {}
    ~NoteWrapper()
    {
        delete ptrToNote;
    }
    Note* ptrToNote = nullptr;
    JUCE_LEAK_DETECTOR(NoteWrapper)
};

struct GuitarStringWrapper 
{
    GuitarStringWrapper( GuitarString* guitarStringPtr ) : ptrToGuitarString(guitarStringPtr) {}

    ~GuitarStringWrapper()
    {
        delete ptrToGuitarString;
    }
    GuitarString* ptrToGuitarString = nullptr;
    JUCE_LEAK_DETECTOR(GuitarStringWrapper)
};

struct ChordWrapper 
{
    ChordWrapper( Chord* chordPtr ) : ptrToChord(chordPtr) {}

    ~ChordWrapper()
    {
        delete ptrToChord;
    }
    Chord* ptrToChord = nullptr;
    JUCE_LEAK_DETECTOR(ChordWrapper)
};

struct FretboardWrapper 
{
    FretboardWrapper( Fretboard* fretboardPtr ) : ptrToFretboard(fretboardPtr) {}

    ~FretboardWrapper()
    {
        delete ptrToFretboard;
    }
    Fretboard* ptrToFretboard = nullptr;
    JUCE_LEAK_DETECTOR(FretboardWrapper)
};

struct ChordProgressionWrapper 
{
    ChordProgressionWrapper( ChordProgression* chordProgressionPtr ) : ptrToChordProgression(chordProgressionPtr) {}

    ~ChordProgressionWrapper()
    {
        delete ptrToChordProgression;
    }
    ChordProgression* ptrToChordProgression = nullptr;
    JUCE_LEAK_DETECTOR(ChordProgressionWrapper)
};
