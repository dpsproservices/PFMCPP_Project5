/******************************************************************
    GuitarString.cpp

    implementation of the GuitarString structure
******************************************************************/

#include "GuitarString.h"

GuitarString::GuitarString()
{
    //std::cout << "GuitarString default CTOR" << std::endl;
    initializeString(1);
}

GuitarString::GuitarString(int strNum)
{
    //std::cout << "GuitarString CTOR" << std::endl;
    initializeString(strNum);
}

GuitarString::~GuitarString()
{
    //std::cout << "GuitarString DTOR" << std::endl;
}

void GuitarString::initializeString(int strNum)
{
    numFrets = NUM_FRETS;
    stringNum = strNum;
    openStringKey = getOpenString(strNum);
    frettedKey = openStringKey;
    frettedNum = 0;

    note.setStringNum(strNum);
    note.setFretNum(frettedNum);
    note.setFinger(none);
    note.setKey(openStringKey);
}

char GuitarString::getOpenString(int strNum)
{
    switch (strNum)
    {
        case 1:
            return 'E';
        case 2:
            return 'B';
        case 3:
            return 'G';
        case 4:
            return 'D';
        case 5:
            return 'A';
        case 6:
            return 'E';
        default:
            return 'E';
    }
}

int GuitarString::getStringNum()
{
    return stringNum;
}

void GuitarString::setStringNum(int strNum)
{
    stringNum = strNum;
}

int GuitarString::getNumFrets()
{
    return numFrets;
}

char GuitarString::getOpenStringKey()
{
    return openStringKey;
}

void GuitarString::setFrettedKey(char key)
{
    frettedKey = key;
}

char GuitarString::getFrettedKey()
{
    return frettedKey;
}

int GuitarString::getFrettedNum()
{
    return frettedNum;
}

void GuitarString::setFrettedNum(int fretNum)
{
    frettedNum = fretNum;
}

void GuitarString::setNote(Note n)
{
    note.setStringNum(n.getStringNum());
    note.setFretNum(n.getFretNum());
    note.setFinger(n.getFinger());
    note.setKey(n.getKey());

    frettedKey = n.getKey();
    frettedNum = n.getFretNum();
}

void GuitarString::printGuitarString()
{
    std::cout << stringNum << " " << openStringKey << " |";

    for(int fret = 1; fret <= NUM_FRETS; ++fret)
    {
        if(fret == frettedNum)
        {
            std::cout << note.getTab();
        }
        else 
        {
            std::cout << "-";
        }
    }

    std::cout << std::endl;
}
