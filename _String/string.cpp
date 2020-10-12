// Glenn Servantes
// string.cpp
// CS 23001
// definitions

#include "string.hpp"

// Empty String
String::String() {
    //stringSize = STRING_SIZE;
    str = new char[stringSize];
    str[0] = '\0';
}

// Single Character String ('x')
String::String(char ch) {
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = '\0';
}

// Constant char array ("abcd")
String::String(const char rhs[]) {
//    stringSize = sizeof(rhs);
    str = new char[stringSize];
    int i = 0;
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
    //???????
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
    delete[] str;
}

///////////////////////////////////////////////////////////////////////
// Constant time swap
void String::swap(String& rhs) {
    char *temp = rhs.str;
    rhs.str = str;
    str = temp;
    int tempInt = rhs.stringSize;
    stringSize = tempInt;
    rhs.stringSize = stringSize;
}

///////////////////////////////////////////////////////////////////////
//Assignment operator overloaded using swap
String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}





/////////////////////////////////////////////////////////////////////
// REQUIRES: 0 < = i < length()
// Accessor / Modifier / Setter
char& String::operator[](int i) {
    assert(0 <= i);
    return str[i];
}

///////////////////////////////////////////////////////////////////////
// REQUIRES: 0 < = i < length()
// Accessor / Getter
char String::operator[](int i) const {
    assert(0 <= i);
    return str[i];
}

///////////////////////////////////////////////////////////////////////
// Capacity
int String::capacity() const {
    return stringSize - 1;
}

///////////////////////////////////////////////////////////////////////
// ENSURES: RetVal == i where str[i] == 0)
// Length
int String::length() const {
    int result = 0;
    while (str[result] != '\0') ++result;
    return result;
}

//////////////////////////////////////////////////////////////////////
// Concatenation
// ENSURES: RetVal == this + find
// RetVal == "abcxyz"
String String::operator+(const String& rhs) const {
    //???????
    String result(str);
    result.resetCapacity(length()+rhs.length()+1);
    int offset = length(); //Calls length() on this (implicitly)
    int i = 0;
    while (rhs.str[i] != '\0') {
//        if (offset + i == result.length()) break;
        result.str[offset + i] = rhs.str[i];
        ++i;
    }
    result.str[offset + i] = '\0';
    return result;
}

// Concatenation +=
String String::operator+=(const String& rhs) {
    //???????
    //Mark

    int offset = length();
    std:: cout << "offset: " << offset << "   " << " rhs.length() " <<rhs.length() << std::endl;

    resetCapacity(length() + rhs.length() + 1);
    int i = 0;
    while (rhs.str[i] != '\0') {
//        if (offset + i == length()) break;
        str[offset + i] = rhs.str[i];
        std::cout << "The element is: " << str[offset + i] << std::endl;
        ++i;
    }
    str[offset + i] = '\0';

    std:: cout << "here is the +=    " << *this << std::endl;
    for(int i = 0; i < length(); i++){
        std::cout << str[i] << " ";
    }
    std::cout << "-----------------------" << std::endl;
    String t(str);
    return t;
}

//////////////////////////////////////////////////////////////////////
// Relational operator
bool String::operator==(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];
}

//////////////////////////////////////////////////////////////////////
// REQUIRES: find.str.[i] != '\0', str[i] != '\0';
// Less than
bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

//////////////////////////////////////////////////////////////////////////
// REQUIRES: [0] <= start < length() && [0] <= end < length() && start <= end
// ENSURES: RetVal == str[start, ... , end]
// Substring
String String::substr(int start, int end) const {
    if (start < 0)         start = 0;
//    if (start <= length()) return "";
    if (start > end)       return "";
    if (end < 0)           return "";
    if (end >= length())   end = length() - 1;

    // modified
    String result(end-start+2);
    int j = 0;
    for (int i = start; i <= end; ++i) {
        std::cout << str[j] << " ";
        result.str[j] = str[i];
        std::cout << result.str[j] << " ";
        j++;
    }
//    std::cout << std::endl;
    result.str[j] = '\0';
//    std::cout << "The end of substr" << std::endl;
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

    if (pos < 0)               pos =   0;
    if (pos > rhs.length())    return -1;
    if (rhs.length() < 1)      return -1;

    for (int i = 0; i < length(); i++) {
        int j = 0;

        if (str[i] == rhs[j]) { // If the first characters match
            int k      = i;
            int result = i;

            while (str[i] == rhs[j] && j < rhs.length() -1) {
                i++;
                j++;
            }

            if (j == rhs.length() -1) {
                return result;
            }
            else {
                i = k; // Re-initialize i to its original value
            }
        }
    }
    return -1;
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
    //??????
    //mark
    String temp(size);
    int i = 0;
    while(str[i] != '\0' && i < size){
        temp[i] = str[i];
        ++i;
    }
    temp[i] = '\0';
    swap(temp);
}

// String Constructor with a given capacity parameter for resetcap
String::String(int cap) {
    stringSize = cap;
    str = new char[cap];
    str[0] = '\0';
}

std::vector<String> String::split(char c) const{
    std::cout << "Come in split" << std::endl;
    std::vector<String> res;
    int start = 0;
    int i = 0;
    std::cout << "Haha!!" << std::endl;
    while(str[i] != '\0'){
        std::cout << " in while loop   " << str[i]<< std::endl;
        if(str[i] == c){
            std::cout << " in if loop        " << str[i-1]<< std::endl;
            res.push_back(substr(start, i-1));
            std::cout << "substr: " << substr(start, i-1) << std::endl;
            start = i+1;
            std::cout << "The start is: " << start << std::endl;
        }
        std::cout<< "+++++ " <<res.back() << std::endl;
        i++;
    }
    res.push_back(substr(start, i-1));
    return res;
}


bool operator==(char lhs,         const String& rhs) { return String(lhs) == rhs; }
bool operator==(const char lhs[], const String& rhs) { return String(lhs) == rhs; }
bool operator< (char lhs,         const String& rhs) { return String(lhs) < rhs; }
bool operator< (const char lhs[], const String& rhs) { return String(lhs) < rhs; }

bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator>=(const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator<=(const String& lhs, const String& rhs) { return !(lhs > rhs); }
bool operator> (const String& lhs, const String& rhs) { return !(lhs <= rhs); }
