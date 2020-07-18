/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Defines.h"
#include "Note.h"
#include "GuitarString.h"
#include "Chord.h"
#include "Fretboard.h"
#include "ChordProgression.h"
#include "Wrapper.h"

int main()
{
    std::cout << std::endl;
    std::cout << "Fretboard Tab V 1.1" << std::endl;
    std::cout << std::endl;

    //Fretboard f = Fretboard();
    FretboardWrapper fretboardWrapper( new Fretboard() );
    fretboardWrapper.ptrToFretboard->reset();
    fretboardWrapper.ptrToFretboard->printTab();

    std::cout << std::endl;

    // play a chord
    fretboardWrapper.ptrToFretboard->chord.setNumFingers(3);
    fretboardWrapper.ptrToFretboard->chord.setNumNotes(3);
    
    Note note1 = Note(2,1,index,'C');
    fretboardWrapper.ptrToFretboard->chord.setNote(note1);
    fretboardWrapper.ptrToFretboard->strings[1].setNote(note1);

    Note note2 = Note(4,2,middle,'E');
    fretboardWrapper.ptrToFretboard->chord.setNote(note2);
    fretboardWrapper.ptrToFretboard->strings[3].setNote(note2);

    Note note3 = Note(5,3,ring,'C');
    fretboardWrapper.ptrToFretboard->chord.setNote(note3);
    fretboardWrapper.ptrToFretboard->strings[4].setNote(note3);

    std::cout << "Fretboard number of notes fretted: " << fretboardWrapper.ptrToFretboard->numNotesFretted << std::endl;
    fretboardWrapper.ptrToFretboard->printNumNotes();

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

    //ChordProgression p;
    //p.setChords();

    ChordProgression p;
    ChordProgressionWrapper chordProgressionWrapper( new ChordProgression() );
    chordProgressionWrapper.ptrToChordProgression->setChords();

    //p.printChords();
    //p.play();

    /*
    std::cout << std::endl;
    std::cout << "Chords octave up: " << std::endl;
    std::cout << std::endl;
    */

    //p.playOctave();
    
    std::cout << "ChordProgression number of chords: " <<  chordProgressionWrapper.ptrToChordProgression->numChords << std::endl;
    
    chordProgressionWrapper.ptrToChordProgression->printNumChords();
}
