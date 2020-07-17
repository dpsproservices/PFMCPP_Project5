/******************************************************************
    Chord.cpp

    implementation of the Chord structure
******************************************************************/

#include "Chord.h"

Chord::Chord()
{
    //std::cout << "Chord CTOR" << std::endl;
    notes[0].setStringNum(1); 
    notes[0].setFretNum(0);
    notes[0].setFinger(none);
    notes[0].setKey('E');

    notes[1].setStringNum(2); 
    notes[1].setFretNum(0);
    notes[1].setFinger(none);
    notes[1].setKey('B');

    notes[2].setStringNum(3); 
    notes[2].setFretNum(0);
    notes[2].setFinger(none);
    notes[2].setKey('G');

    notes[3].setStringNum(4); 
    notes[3].setFretNum(0);
    notes[3].setFinger(none);
    notes[3].setKey('D');

    notes[4].setStringNum(5); 
    notes[4].setFretNum(0);
    notes[4].setFinger(none);
    notes[4].setKey('A');

    notes[5].setStringNum(6); 
    notes[5].setFretNum(0);
    notes[5].setFinger(none);
    notes[5].setKey('E');
}

Chord::~Chord()
{
    //std::cout << "Chord DTOR" << std::endl;
}

int Chord::getNumNotes()
{
    return numNotes;
}

void Chord::setNumNotes(int num)
{   
    numNotes = num;
}

int Chord::getNumFingers()
{
    return numFingers;
}

void Chord::setNumFingers(int digits)
{
    numFingers = digits;
}

void Chord::setNote(Note note)
{
    int s = note.getStringNum();
    int i = s - 1;
    Finger f = note.getFinger();
    char key = note.getKey();
    int fret = note.getFretNum();

    notes[i].setStringNum(s); 
    notes[i].setFretNum(fret);
    notes[i].setFinger(f);
    notes[i].setKey(key);
}

void Chord::resetChord()
{
    notes[0].setStringNum(1); 
    notes[0].setFretNum(0);
    notes[0].setFinger(none);
    notes[0].setKey('E');

    notes[1].setStringNum(2); 
    notes[1].setFretNum(0);
    notes[1].setFinger(none);
    notes[1].setKey('B');

    notes[2].setStringNum(3); 
    notes[2].setFretNum(0);
    notes[2].setFinger(none);
    notes[2].setKey('G');

    notes[3].setStringNum(4); 
    notes[3].setFretNum(0);
    notes[3].setFinger(none);
    notes[3].setKey('D');

    notes[4].setStringNum(5); 
    notes[4].setFretNum(0);
    notes[4].setFinger(none);
    notes[4].setKey('A');

    notes[5].setStringNum(6); 
    notes[5].setFretNum(0);
    notes[5].setFinger(none);
    notes[5].setKey('E');
}

void Chord::printChord()
{
    for ( int i = 0; i < NUM_STRINGS; ++i)
    {
        std::cout << notes[i].getKey() << std::endl;
    }
}

bool Chord::getIsBarred()
{
    return isBarred;
}

void Chord::setIsBarred()
{
    isBarred = !isBarred;
}
