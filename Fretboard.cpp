/******************************************************************
    Fretboard.cpp

    implementation of the Fretboard structure
******************************************************************/

#include "Fretboard.h"

Fretboard::Fretboard()
{
    numNotesFretted = 0;
    octave = 1;

    chord.resetChord();

    strings[0] = GuitarString(1);
    strings[1] = GuitarString(2);
    strings[2] = GuitarString(3);
    strings[3] = GuitarString(4);
    strings[4] = GuitarString(5);
    strings[5] = GuitarString(6);

    //std::cout << "Fretboard CTOR" << std::endl;
}

Fretboard::~Fretboard()
{
    //std::cout << "Fretboard DTOR" << std::endl;
}

void Fretboard::reset()
{
    chord.resetChord();
}

void Fretboard::setChord(Chord c)
{
    for (int i = 0; i < NUM_STRINGS; ++i)
    {
        strings[i].setNote(c.notes[i]);
        chord.notes[i] = c.notes[i];
    }
}

void Fretboard::raiseOctave()
{
    int i = 0;
    while (i < NUM_STRINGS)
    {
        Note note = strings[i].note;
        int fret = note.getFretNum();
        fret += 12;
        strings[i].note.setFretNum(fret);
        strings[i].setFrettedNum(fret);
        ++i;
    }
    octave = 2;
    chord.setIsBarred();
}

void Fretboard::printTab()
{
    for(int i = 0; i < NUM_STRINGS; ++i)
    {
        strings[i].printGuitarString();
    }
}

void Fretboard::printNumNotes()
{
    std::cout << "Fretboard number of notes fretted: " << this->numNotesFretted << std::endl;
}
