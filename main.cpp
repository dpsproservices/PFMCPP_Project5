/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */
#define NUM_STRINGS 6
#define NUM_FRETS 24
#define NUM_KEYS 12
#define NUM_CHORDS 3
#include <iostream>

enum Finger { thumb, index, middle, ring, pinky, none };

struct Note
{
    int stringNum;
    int fretNum;
    Finger finger;
    char key; 
    
    Note();
    Note(int str, int fret, Finger digit);
    ~Note();

    // Note operator=(const Note & n);

    int getStringNum();
    void setStringNum(int stringNum);
    int getFretNum();
    void setFretNum(int fret);
    Finger getFinger();
    void setFinger(Finger finger);
    char getKey();
    void setKey(char key);

    char getNextTone();
    char getKeyByInternal(int interval);
    void printCycle(int interval);

    char getTab();
};

Note::Note()
{
    stringNum = 1;
    fretNum = 0;
    finger = none;
    //std::cout << "Note default CTOR" << std::endl; 
}

Note::Note(int str, int fret, Finger digit)
{
    stringNum = str;
    fretNum = fret;
    finger = digit;
    //std::cout << "Note CTOR" << std::endl;
}

Note::~Note()
{
    std::cout << "Note DTOR" << std::endl;
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
        i++;
    }

    return semitone;
}

void Note::printCycle(int interval)
{
    char semitone = 'A';
    for (int i = 1; i <= NUM_KEYS; i++)
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
};

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

GuitarString::GuitarString()
{
    //std::cout << "GuitarString default CTOR" << std::endl;
    numFrets = NUM_FRETS;
    stringNum = 1;
    openStringKey = 'E';
    frettedKey = 'E';
    frettedNum = 0;
    note.setStringNum(1);
    note.setFretNum(frettedNum);
    note.setFinger(none);
    note.setKey('E');
}

GuitarString::GuitarString(int strNum)
{
    //std::cout << "GuitarString CTOR" << std::endl;
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

GuitarString::~GuitarString()
{
    //std::cout << "GuitarString DTOR" << std::endl;
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

//Note GuitarString::getNote()
//{
//    return note;
//}

void GuitarString::setNote(Note n)
{
    note.setStringNum(n.getStringNum());
    note.setFretNum(n.getFretNum());
    note.setFinger(n.getFinger());
}

void GuitarString::printGuitarString()
{

    std::cout << stringNum << " " << openStringKey << " |";

    for(int fret = 1; fret <= NUM_FRETS; fret++)
    {
        if(fret == getFrettedNum())
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


struct Chord
{
    int numNotes;
    int numFingers;

    Note notes[NUM_STRINGS];

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
};

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
    std::cout << "Chord DTOR" << std::endl;
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
    notes[i].setStringNum(s); 
    notes[i].setFretNum(0);
    notes[i].setFinger(f);
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
    for ( int i = 0; i < numNotes; i++)
    {
        std::cout << notes[i].getKey() << std::endl;
    }
}

struct Fretboard
{   
    int numNotesFretted;
    int octave;
    Chord chord;

    GuitarString strings[NUM_STRINGS];

    Fretboard();
    ~Fretboard();

    void raiseOctave();

    void printTab();
    void reset();
};

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
    std::cout << "Fretboard DTOR" << std::endl;
}

void Fretboard::reset()
{
    chord.resetChord();
}

void Fretboard::raiseOctave()
{
    int i = 0;
    while (i < NUM_STRINGS)
    {
        GuitarString s = strings[i];
        Note note = s.note;
        int fret = note.getFretNum();
        fret += 12;
        s.note.setFretNum(fret);
        i++;
    }
}

void Fretboard::printTab()
{
    for(int i = 0; i < NUM_STRINGS; i++)
    {
        GuitarString s = strings[i];
        s.printGuitarString();
    }
}

struct ChordProgression
{
    int numChords;
    Chord chords[NUM_CHORDS];
    Fretboard fretboard;

    ChordProgression();
    ~ChordProgression();

    void setChords();
    void printChords();
};

ChordProgression::ChordProgression()
{
    //std::cout << "ChordProgression CTOR" << std::endl;
    numChords = NUM_CHORDS;
}

ChordProgression::~ChordProgression()
{
    std::cout << "ChordProgression DTOR" << std::endl;
}

void ChordProgression::setChords()
{
    chords[0].setNumFingers(3);
    chords[0].setNumNotes(3);
    chords[0].setNote(Note(2,1,index));
    chords[0].setNote(Note(4,2,middle));
    chords[0].setNote(Note(5,3,ring));

    chords[1].setNumFingers(4);
    chords[1].setNumNotes(4);
    chords[1].setNote(Note(1,3,pinky));
    chords[1].setNote(Note(2,3,ring));
    chords[1].setNote(Note(5,2,index));
    chords[1].setNote(Note(6,3,middle));

    chords[2].setNumFingers(2);
    chords[2].setNumNotes(2);
    chords[2].setNote(Note(4,2,ring));
    chords[2].setNote(Note(5,2,middle));
}

void ChordProgression::printChords()
{
    for (int i = 0; i < NUM_CHORDS; i++)
    {
        Chord c = chords[i];
        c.printChord();
    }
}

int main()
{
    std::cout << std::endl;
    std::cout << "Fretboard Tab V 1.0" << std::endl;
    std::cout << std::endl;

    Fretboard f = Fretboard();
    f.reset();
    f.printTab();

    std::cout << std::endl;

    // play a chord
    f.chord.setNumFingers(3);
    f.chord.setNumNotes(3);
    f.chord.setNote(Note(2,1,index));
    f.chord.setNote(Note(4,2,middle));
    f.chord.setNote(Note(5,3,ring));
    
    std::cout << "First chord notes are: " << std::endl;
    f.chord.printChord();

    std::cout << std::endl;

    std::cout << "First chord diagram: " << std::endl;

    f.raiseOctave();
    f.printTab();

    ChordProgression p;
    p.setChords();
    p.printChords();
}
