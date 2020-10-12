// Glenn Servantes
// string.cpp
// CS 23001
// definitions

#include "string.hpp"

using namespace std;

// Empty String
String::String() {
    //stringSize = STRING_SIZE;
    //change
    stringSize = 1; //1
    str = new char[stringSize];
    str[0] = '\0';
}

// Single Character String ('x')
String::String(char ch) {
    //checked
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = '\0';
}

// Constant char array ("abcd")
String::String(const char rhs[]) {
    //change
    stringSize = (int)strlen(rhs)+1;  //1
    str = new char[stringSize];
    int i = 0;
//    stringSize = length();    //2

    while (rhs[i] != '\0') {
        str[i] = rhs[i];
        ++i;
        //if (i >= length()) break; //this check is now useless
    }
    str[i] = '\0';
}

///////////////////////////////////////////////////////////////////////
// Copy Constructor
String::String (const String& rhs) {
    //change
    stringSize = rhs.stringSize;    //1
    str = new char[stringSize];
    int i = 0;
    stringSize = rhs.length();
    for (; rhs[i] != '\0'; ++i) {
        str[i] = rhs[i];
    }
    str[i] = '\0';
}

///////////////////////////////////////////////////////////////////////
// Destructor
String::~String() {
    //change
    delete[] str;
    str = nullptr;  //1
}

///////////////////////////////////////////////////////////////////////
// Constant time swap
void String::swap(String& rhs) {
    //checked
    char *temp = rhs.str;
    rhs.str = str;
    str = temp;
    int tempInt = rhs.stringSize;
    rhs.stringSize = stringSize;
    stringSize = tempInt;
}

///////////////////////////////////////////////////////////////////////
//Assignment operator overloaded using swap
String& String::operator=(String rhs) {
    //checked
    swap(rhs);
    return *this;
}





/////////////////////////////////////////////////////////////////////
// REQUIRES: 0 < = i < length()
// Accessor / Modifier / Setter
char& String::operator[](int i) {
    //checked
    assert(0 <= i);
    return str[i];
}

///////////////////////////////////////////////////////////////////////
// REQUIRES: 0 < = i < length()
// Accessor / Getter
char String::operator[](int i) const {
    //checked
    assert(0 <= i);
    return str[i];
}

///////////////////////////////////////////////////////////////////////
// Capacity
int String::capacity() const {
    //checked
    return stringSize - 1;
}

///////////////////////////////////////////////////////////////////////
// ENSURES: RetVal == i where str[i] == 0)
// Length
int String::length() const {
    //checked
    int result = 0;
    while (str[result] != '\0') ++result;
    return result;
}

//////////////////////////////////////////////////////////////////////
// Concatenation
// ENSURES: RetVal == this + find
// RetVal == "abcxyz"
String String::operator+(const String& rhs) const {
    //change
    String result(length()+rhs.length()+1, str);
//    result.resetCapacity(length()+rhs.length()+1);      //1
    int offset = length(); //Calls length() on this (implicitly)
    int i = 0;
    while (rhs.str[i] != '\0') {
                                                        //2
        result.str[offset + i] = rhs.str[i];
        ++i;
    }
    result.str[offset + i] = '\0';
    return result;
}

// Concatenation +=
String String::operator+=(const String& rhs) {
    //change
    resetCapacity(length()+rhs.length()+1);     //1
    int offset = length();
    int i = 0;
    while (rhs.str[i] != '\0') {
//        if (offset + i == length()) break;    //2
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = '\0';
    return *this;
}

//////////////////////////////////////////////////////////////////////
// Relational operator
bool String::operator==(const String& rhs) const {
    //checked
    int i = 0;
    while ((str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];
}

//////////////////////////////////////////////////////////////////////
// REQUIRES: find.str.[i] != '\0', str[i] != '\0';
// Less than
bool String::operator<(const String& rhs) const {
    //checked
    int i = 0;
    while ((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

//////////////////////////////////////////////////////////////////////////
// REQUIRES: [0] <= start < length() && [0] <= end < length() && start <= end
// ENSURES: RetVal == str[start, ... , end]
// Substring
String String::substr(int start, int end) const {
    //change
    if (start < 0)         start = 0;
//    if (start <= length()) return "";     //1
    if (start > end)       return String("");
    if (end < 0)           return String("");
    if (end >= length())   end = length() - 1;

    String result(end-start+1);             //2
    int j = 0;
    for (int i = start; i <= end; ++i) {
        result.str[j] = str[i];
        ++j;                                //3
    }
    result.str[j] = '\0';
    return result;
}

String operator+ (char lhs, const String& rhs) {
    return String(lhs) + rhs;
}

String operator+ (const char lhs[], const String& rhs) {
    return String(lhs) + rhs;
}

///////////////////////////////////////////////////////////////////////////
// REQUIRES: (length() > 0) && ([0] <= pos < '\0') to return a valid result
// Find character
int String::findch(int pos, char ch) const {

    if (pos < 0)        pos = 0;
    if (pos > length()) return -1;
    if (length() < 1)   return -1;

    for (int i = pos; i < length(); ++i) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}


////////////////////////////////////////////////////////////////////////
// REQUIRES: (length() > 0) && ([0] <= pos < '\0') to return a valid result
// Find substring
int String::findstr(int pos, const String& rhs) const {
    //change
    if (pos < 0)               pos =   0;
    if (pos > rhs.length())    return -1;
    if (rhs.length() < 1)      return -1;

    for (int i = 0; i < length(); i++) {
        int j = 0;

        if (str[i] == rhs[j]) { // If the first characters match
            int k      = i;
            int result = i;

            while (str[i] == rhs[j] && j < rhs.length()) {      //1
                i++;
                j++;
            }

            if (j == rhs.length()) {                            //2
                return result;
            }
            else {
                i = k; // Re-initialize i to its original value
            }
        }
    }
    return -1;
}


std::vector<String> String::split(char c) const{
    //new
    std::vector<String> res;
    int start = 0, i = 0;
    while(str[i] != '\0'){
        if(str[i] == c){
            res.push_back(substr(start, i-1));
            start = i+1;
        }
        i++;
    }
    res.push_back(substr(start, i-1));
    return res;
}

///////////////////////////////////////////////////////////////////////
// toInt
int String::toInt() {
    int startindex = stringSize - 1;

    if (str[startindex] == '-') {
        return 0;
    }

    int value = 0;
    int tens = 1;

    for (int i = startindex; i >= 0; --i) {
        value = value + (int(str[i] - int('0')) * tens);
        tens *= 10;
    }

    return value;
}

///////////////////////////////////////////////////////////////////////
// Insertion-Extraction operators
std::istream& operator >> (std::istream& in, String& rhs) {
    in >> rhs.str;
    return in;
}

//Insertion
std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}




// Reset capacity
void String::resetCapacity(int size) {
    //change
    //----------------------------------
    stringSize = size+1;
    String temp(size);
    int i = 0;
    while(i < size && str[i] != '\0'){
        temp[i] = str[i];
        i++;
    }
    temp[i] = '\0';
    //----------------------------------
    swap(temp);
}

// String Constructor with a given capacity parameter for resetcap
String::String(int cap) {
    //change
    stringSize = cap+1;     //1
    str = new char[stringSize];     //2
    str[0] = '\0';
}


String::String(int cap, const char rhs[]){
    stringSize = cap+1;
    str = new char[stringSize];

    int i = 0;
    while(rhs[i] != '\0'){
        str[i] = rhs[i];
        ++i;
    }
    str[i] = '\0';
}


bool operator==(char lhs,         const String& rhs) { return String(lhs) == rhs; }
bool operator==(const char lhs[], const String& rhs) { return String(lhs) == rhs; }
bool operator< (char lhs,         const String& rhs) { return String(lhs) < rhs; }
bool operator< (const char lhs[], const String& rhs) { return String(lhs) < rhs; }

bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator>=(const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator<=(const String& lhs, const String& rhs) { return !(lhs > rhs); }
bool operator> (const String& lhs, const String& rhs) { return !(lhs <= rhs); }

