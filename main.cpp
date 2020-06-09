/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
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
    Note(int str, int fret, Finger digit, char note);
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
    void printKey();
    void printFinger();
    void printFretNum();
    void printStringNum();
};

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
};

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

int main()
{
    std::cout << std::endl;
    std::cout << "Fretboard Tab V 1.1" << std::endl;
    std::cout << std::endl;

    Fretboard f = Fretboard();
    f.reset();
    f.printTab();

    std::cout << std::endl;

    // play a chord
    f.chord.setNumFingers(3);
    f.chord.setNumNotes(3);
    
    Note note1 = Note(2,1,index,'C');
    f.chord.setNote(note1);
    f.strings[1].setNote(note1);

    Note note2 = Note(4,2,middle,'E');
    f.chord.setNote(note2);
    f.strings[3].setNote(note2);

    Note note3 = Note(5,3,ring,'C');
    f.chord.setNote(note3);
    f.strings[4].setNote(note3);

    std::cout << "Fretboard number of notes fretted: " << f.numNotesFretted << std::endl;
    f.printNumNotes();

    std::cout << "Note key: " <<  note1.key << std::endl;
    note1.printKey();

    std::cout << "Note string: " <<  note1.stringNum << std::endl;
    note1.printStringNum();

    std::cout << "Note fret: " <<  note1.fretNum << std::endl;
    note1.printFretNum();

    /*
    std::cout << std::endl;
    std::cout << "First chord notes are: " << std::endl;
    std::cout << std::endl;
    */

    //f.chord.printChord();

    /*
    std::cout << std::endl;
    std::cout << "First chord diagram: " << std::endl;
    std::cout << std::endl;
    */
    
    //f.printTab();

    /*
    std::cout << std::endl;
    std::cout << "First chord octave up: " << std::endl;
    std::cout << std::endl;
    */

    //f.raiseOctave();
    //f.printTab();

    /*
    std::cout << std::endl;
    std::cout << "First chord octave up: " << std::endl;
    std::cout << std::endl;
    */

    ChordProgression p;
    p.setChords();
    //p.printChords();
    //p.play();

    /*
    std::cout << std::endl;
    std::cout << "Chords octave up: " << std::endl;
    std::cout << std::endl;
    */

    //p.playOctave();
    
    std::cout << "ChordProgression number of chords: " <<  p.numChords << std::endl;
    p.printNumChords();
}
