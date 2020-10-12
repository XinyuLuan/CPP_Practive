// Glenn Servantes
// string.hpp
// CS 23001
// Given file has been slightly changed for spelling to accomodate additional functions

//File:        string-interface.hpp
//
//Version:     1.0
//Date:        Spring 2019
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for Project 2, milestone 1.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// You will either have use this interface or call your methods through this interface.
//
// You need to implement all of the methods and funcitons declared here.
//

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <cassert>
#include <vector>   //change

const int STRING_SIZE = 256;  //The size of the String+1 for null terminator

////////////////////////////////////////////////////
// CLASS INV:   str[length()] == 0          &&
//              0 <= length() <= capacity() &&
//              capacity()    == stringSize - 1
//
class String {
public:
            String();                      //Empty string
            String        (char);          //String('x')
            String        (const char[]);  //String("abcd")
            String        (const String&); //Copy Constructor
            ~String();                     //Destructor
    void    swap          (String&);       //Constant time swap
    String& operator=     (String);        //Assignment Copy

    char&   operator[]    (int);                                //Accessor/Modifier/Setter
    char    operator[]    (int)                          const; //Accessor/Getter
    int     capacity()                                   const; //Max chars that are stored (not including null terminator)
    int     length()                                     const; //Number of char in string  (not incl null terminator)
    String  operator+     (const String&)                const; //Concatenation
    String  operator+=    (const String&);                      //Concatenation +=
    bool    operator==    (const String&)                const; //Comparison
    bool    operator<     (const String&)                const; //Less than
    String  substr        (int start, int end)           const; //Returns a substring from start to end position
    int     findch        (int pos,   char ch)           const; //Returns a location of the ch at or after pos, returns -1 if not found
    int     findstr       (int pos,   const String&)     const; //Returns a location of the str at or after the pos, returns -1 if not found
    int toInt();    //new
    std::vector<String> split(char c) const;    //change

    friend  std::istream& operator >> (std::istream&, String&);
    friend  std::ostream& operator<<(std::ostream&, const String&);



private:
            String       (int);               //String(10) - size of 10.
            String       (int, const char[]); //String(10, "abc") - Size 10 with "abc"
    void    resetCapacity(int);               //Resets capacity to be N

    int     stringSize;                       //Size includes NULL terminator
    char    *str;                             //Pointer to character array
};

String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);


#endif
