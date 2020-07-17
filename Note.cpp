/******************************************************************
    Note.cpp

    implementation of the Note structure
******************************************************************/

#include "Note.h"

Note::Note()
{
    stringNum = 1;
    fretNum = 0;
    finger = none;
    //std::cout << "Note default CTOR" << std::endl; 
}

Note::Note(int str, int fret, Finger digit, char note)
{
    stringNum = str;
    fretNum = fret;
    finger = digit;

    key = note;

    //std::cout << "Note CTOR" << std::endl;
}

Note::~Note()
{
    //std::cout << "Note DTOR" << std::endl;
}

int Note::getStringNum()
{
    return stringNum;
}

void Note::setStringNum(int strNum)
{
    stringNum = strNum;
}

int Note::getFretNum()
{
    return fretNum;
}

void Note::setFretNum(int fret)
{
    fretNum = fret;
}

Finger Note::getFinger()
{
    return finger;
}

void Note::setFinger(Finger digit)
{
    finger = digit;
}

void Note::setKey(char k)
{
    key = k;
}

char Note::getKey()
{
    return key;
}

char Note::getNextTone()
{
    switch(key)
    {
        case 'A':
            return 'B';
        case 'B':
            return 'C';
        case 'C':
            return 'D';
        case 'D':
            return 'E';
        case 'E':
            return 'F';
        case 'F':
            return 'G';
        case 'G':
            return 'A';
        default:
            return 'A';
    }
}

char Note::getKeyByInternal(int interval)
{
    char semitone = key;

    if(interval == 0)
    {
        return semitone;
    }

    if(interval < 0)
    {
        interval = 12 + interval;
    }

    int i = 0;
    while(i < interval)
    {
        semitone = getNextTone();
        key = semitone;
        ++i;
    }

    return semitone;
}

void Note::printCycle(int interval)
{
    char semitone = 'A';
    for (int i = 1; i <= NUM_KEYS; ++i)
    {
        std::cout << semitone << std::endl;
        semitone = getKeyByInternal(interval);
    }
}

char Note::getTab()
{
    switch (finger)
    {
        case thumb:
            return 'T';
        case index:
            return '1';
        case middle:
            return '2';
        case ring:
            return '3';
        case pinky:
            return '4';
        case none:
            return '-';
    }
}

void Note::printKey()
{
    std::cout << "Note key: " << this->key << std::endl;
}

void Note::printFinger()
{
    std::cout << "Note finger: " << this->finger << std::endl;
}

void Note::printFretNum()
{
    std::cout << "Note fret: " << this->fretNum << std::endl;
}

void Note::printStringNum()
{
    std::cout << "Note string: " << this->stringNum << std::endl;
}
