/******************************************************************
    ChordProgression.cpp

    implementation of the ChordProgression structure
******************************************************************/

#include "ChordProgression.h"

ChordProgression::ChordProgression()
{
    //std::cout << "ChordProgression CTOR" << std::endl;
    numChords = NUM_CHORDS;
}

ChordProgression::~ChordProgression()
{
    //std::cout << "ChordProgression DTOR" << std::endl;
}

void ChordProgression::setChords()
{
    chords[0].resetChord();
    chords[0].setNumFingers(3);
    chords[0].setNumNotes(3);
    chords[0].setNote(Note(2,1,index,'C'));
    chords[0].setNote(Note(4,2,middle,'E'));
    chords[0].setNote(Note(5,3,ring,'C'));

    chords[1].resetChord();
    chords[1].setNumFingers(4);
    chords[1].setNumNotes(4);
    chords[1].setNote(Note(1,3,pinky,'G'));
    chords[1].setNote(Note(2,3,ring,'D'));
    chords[1].setNote(Note(5,2,index,'B'));
    chords[1].setNote(Note(6,3,middle,'G'));

    chords[2].resetChord();
    chords[2].setNumFingers(2);
    chords[2].setNumNotes(2);
    chords[2].setNote(Note(4,2,ring,'E'));
    chords[2].setNote(Note(5,2,middle,'B'));
}

void ChordProgression::printChords()
{
    for (int i = 0; i < NUM_CHORDS; ++i)
    {
        Chord c = chords[i];
        c.printChord();
    }
}

void ChordProgression::play()
{
    int i = 0;
    while (i < NUM_CHORDS)
    {
        fretboard.reset();
        fretboard.setChord(chords[i]);
        std::cout << "Next chord fretboard: " << std::endl;
        fretboard.printTab();
        std::cout << "Next chord notes are: " << std::endl;
        fretboard.chord.printChord();
        ++i;
    }
}

void ChordProgression::playOctave()
{
    int i = 0;
    while (i < NUM_CHORDS)
    {
        fretboard.reset();
        fretboard.setChord(chords[i]);
        fretboard.raiseOctave();
        std::cout << "Next chord fretboard: " << std::endl;
        fretboard.printTab();
        std::cout << "Next chord notes are: " << std::endl;
        fretboard.chord.printChord();
        ++i;
    }
}

void ChordProgression::printNumChords()
{
    std::cout << "ChordProgression number of chords: " << this->numChords << std::endl;
}
