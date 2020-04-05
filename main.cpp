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

#include <iostream>


/*
 copied UDT 1:
 */
struct FloatType
{
    float f;
    
    FloatType();
    ~FloatType();

    float add( float lhs, float rhs );
    float subtract( float lhs, float rhs );
    float multiply( float lhs, float rhs );
    float divide( float lhs, float rhs );

    void doWhile();
    void doFor();
};

/*
 copied UDT 2:
 */
struct DoubleType
{
    double d;
    
    DoubleType();
    ~DoubleType();

    double add( double lhs, double rhs );
    double subtract( double lhs, double rhs );
    double multiply( double lhs, double rhs );
    double divide( double lhs, double rhs );

    void doWhile();
    void doFor();    
};

/*
 copied UDT 3:
 */
struct IntType
{
    int i;
    
    IntType();
    ~IntType();

    int add( int lhs, int rhs );
    int subtract( int lhs, int rhs );
    int multiply( int lhs, int rhs );
    int divide( int lhs, int rhs );

    void doWhile();
    void doFor();    
};

/*
 new UDT 4:
 */
struct Stars
{
    IntType it;
    FloatType ft;
    DoubleType dt;

    Stars();
    ~Stars();

    void doStuff();
};

/*
 new UDT 5:
 */
struct Stripes
{
    IntType it;
    FloatType ft;
    DoubleType dt;

    Stripes();
    ~Stripes();

    void doStuff();    
};




FloatType::FloatType()
{
    this->f = 0.0f;
    std::cout << "FloatType ctor" << std::endl;
}
FloatType::~FloatType()
{
    std::cout << "FloatType dtor" << std::endl;
}

void FloatType::doWhile()
{
    int count = 0;
    while(count < 3)
    {
        this->f = this->add(this->f,count);
        std::cout << "FloatType doWhile " << this->f << std::endl;
        count++;
    }
}

void FloatType::doFor()
{
    for(int count = 0; count < 3; count++)
    {
        this->f = this->add(this->f,count);
        std::cout << "FloatType doFor " << this->f << std::endl;
    }
}

float FloatType::add( float lhs, float rhs )
{
    return lhs + rhs;
}

float FloatType::subtract( float lhs, float rhs )
{
    return lhs - rhs;
}

float FloatType::multiply( float lhs, float rhs )
{
    return lhs * rhs;
}

float FloatType::divide( float lhs, float rhs )
{
    if ( rhs <= 0.0f )
    {
        std::cout << "Warning division by zero." << std::endl;
    }
    return lhs / rhs;
}


DoubleType::DoubleType()
{
    this->d = 0.0;
    std::cout << "DoubleType ctor" << std::endl;
}
DoubleType::~DoubleType()
{
    std::cout << "DoubleType dtor" << std::endl;
}

void DoubleType::doWhile()
{
    int count = 0;
    while(count < 3)
    {
        this->d = this->add(this->d,count);
        std::cout << "DoubleType doWhile " << this->d << std::endl;
        count++;
    }
}

void DoubleType::doFor()
{
    for(int count = 0; count < 3; count++)
    {
        this->d = this->add(this->d,count);
        std::cout << "DoubleType doFor " << this->d << std::endl;
    }
}

double DoubleType::add( double lhs, double rhs )
{
    return lhs + rhs;
}

double DoubleType::subtract( double lhs, double rhs )
{
    return lhs - rhs;
}

double DoubleType::multiply( double lhs, double rhs )
{
    return lhs * rhs;
}

double DoubleType::divide( double lhs, double rhs )
{
    if ( rhs <= 0.0 )
    {
        std::cerr << "Warning division by zero." << std::endl;
    }
    return lhs / rhs;
}


IntType::IntType()
{
    this->i = 0.0;
    std::cout << "IntType ctor" << std::endl;
}
IntType::~IntType()
{
    std::cout << "IntType dtor" << std::endl;
}

void IntType::doWhile()
{
    int count = 0;
    while(count < 3)
    {
        this->i = this->add(this->i,count);        
        std::cout << "IntType doWhile " << this->i << std::endl;
        count++;
    }
}

void IntType::doFor()
{
    for(int count = 0; count < 3; count++)
    {
        this->i = this->add(this->i,count);
        std::cout << "IntType doFor " << this->i << std::endl;
    }
}

int IntType::add( int lhs, int rhs )
{
    return lhs + rhs;
}

int IntType::subtract( int lhs, int rhs )
{
    return lhs - rhs;
}

int IntType::multiply( int lhs, int rhs )
{
    return lhs * rhs;
}

int IntType::divide( int lhs, int rhs )
{
    if ( rhs <= 0.0 )
    {
        std::cerr << "Warning division by zero." << std::endl;
        return lhs;
    } 
    else 
    {
        return lhs / rhs;
    }
}

Stars::Stars()
{
    std::cout << "Stars ctor" << std::endl;
}

Stars::~Stars()
{
    std::cout << "Stars dtor" << std::endl;
}

void Stars::doStuff()
{
    std::cout << "Stars doStuff" << std::endl;
    this->ft.doWhile();
    this->dt.doFor();
    this->it.doWhile();

} 

Stripes::Stripes()
{
    std::cout << "Stripes ctor" << std::endl;
}

Stripes::~Stripes()
{
    std::cout << "Stripes dtor" << std::endl;
}
void Stripes::doStuff()
{
    auto resultFT = this->ft.add(3.2f, 23.f );       
    std::cout << "result of ft.add(): " << resultFT << std::endl;

    resultFT = this->ft.subtract(3.2f, 23.f );
    std::cout << "result of ft.subtract(): " << resultFT << std::endl;

    resultFT = this->ft.multiply(3.2f, 23.f );        
    std::cout << "result of ft.multiply(): " << resultFT << std::endl;

    resultFT = this->ft.divide(3.2f, 23.f );     
    std::cout << "result of ft.divide(): " << resultFT << std::endl;

    auto resultDT = this->dt.add(3.2, 23. );       
    std::cout << "result of dt.add(): " << resultDT << std::endl;

    resultDT = this->dt.subtract(3.2, 23. );
    std::cout << "result of dt.subtract(): " << resultDT << std::endl;

    resultDT = this->dt.multiply(3.2, 23. );        
    std::cout << "result of dt.multiply(): " << resultDT << std::endl;

    resultDT = this->dt.divide(3.2, 23. );     
    std::cout << "result of dt.divide(): " << resultDT << std::endl;

    auto resultIT = this->it.add(3, 23 );       
    std::cout << "result of it.add(): " << resultIT << std::endl;

    resultIT = this->it.subtract(3, 23 );
    std::cout << "result of it.subtract(): " << resultIT << std::endl;

    resultIT = this->it.multiply(3, 23 );        
    std::cout << "result of it.multiply(): " << resultIT << std::endl;

    resultIT = this->it.divide(3, 23 );     
    std::cout << "result of it.divide(): " << resultIT << std::endl;
}

int main()
{
    Stars stars;

    stars.doStuff();

    Stripes stripes;

    stripes.doStuff();

    std::cout << "good to go!" << std::endl;
}
