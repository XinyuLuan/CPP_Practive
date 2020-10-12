#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date {
public:
    Date() {}
    void   setday    (String dayString)	  { day = dayString; }
    void   setmonth  (String monthString) { month = monthString; }
    void   setyear   (int yearString)	  { year = yearString; }
    String getday    () const	          { return day; }
    String getmonth  () const             { return month; }
    int    getyear   () const		      { return year; }
private:
	String  day, month;
	int     year;
};

////////////////////////////////////////////////////////////
class Time {
public:
	Time() {};
	void sethour    (int hourInt)	  { hour = hourInt; };
	void setminute  (int minuteInt)   { minute = minuteInt; };
	void setsecond  (int secondInt)   { second = secondInt; };
	int  gethour    () const          { return hour; };
	int  getminute  () const          { return minute; };
	int  getsecond  () const          { return second; };
private:
	int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
	       LogEntry ()        {};
	       LogEntry (String);
	friend std::ostream& operator<<(std::ostream&, const LogEntry&);
	String gethost  () const  { return host; };
	int    getbytes () const  { return number_of_bytes; };

private:
	String  host;
	Date    date;
	Time    time;
	String  request;
	String  status;
	int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::__1::istream &);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
//String&                 getline     (std::istream& in);               //Gets a line from a given file


#endif
