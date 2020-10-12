//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <fstream>

#include "string.hpp" 
#include "logentry.hpp"

using std::ifstream;

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
	// lets say we are given 
	// "131.123.47.176 - -[18 / Sep / 2002:12 : 05 : 25 - 0400] "GET /~darci/ HTTP/1.0" 200 5625" 
	// as a string and we need to make it a new LogEntry
	std::vector<String> vec = s.split(' '); //split the String about the ' ' characters
	//it is now a vector of 10 strings, each split at the ' ' characters
	if (vec.size() == 10) { //assuming our given vector IS 10 strings
		host = vec[0];  //let's name the first string in the vector "host"

		std::vector<String> date_time = vec[3].split(':');          //take "[18/Sep/2002:12:05:25" and split it about the colons
		//now we have date_time to be <  "[18/Sep/2002" , "12" , "05" , "25" , "-0400]"  >
		std::vector<String> date_string = date_time[0].split('/');  //take "[18/Sep/2002" and split it about the fwd slashes
		//now we have date_string to be <  "[18" , "Sep", "2002"  >

		String stringday = date_string[0].substr(1, date_string[0].length()); //take "[18" and call stringday "18"
		date.setday(stringday); //set "18" to be the day
		
		String stringmonth = date_string[1]; //set stringmonth to "Sep"
		date.setmonth(stringmonth); //set the month to be "Sep"
		
		int intyear = date_string[2].toInt(); //convert "2002" to 2002 and call that intyear
		date.setyear(intyear); //set the year to be 2002

		time.sethour(date_time[1].toInt()); //convert "12" to 12 and make it the hour
		time.setminute(date_time[2].toInt()); //convert "05" to 05 and make it the minute
		time.setsecond(date_time[3].toInt()); //convert "25" to 25 and make it the second
		
		request = vec[5] + vec[6] + vec[7]; //set the request to "GET /~darci/ HTTP/1.0"
		status = vec[8]; //set the status to "200"

		if (vec[9] == '-') {  //a line that has no bytes are given a - instead of 0, lets set - to 0 in that case
			number_of_bytes = 0;
		}

		number_of_bytes = vec[9].toInt(); //convert "5625" to an int and set the number_of_bytes to it
	}
	else { //if the line does not have all valid info given, set s to a blank LogEntry
		host = "";
		date.setday("");
		date.setmonth("");
		date.setyear(0);
		time.sethour(0);
		time.setminute(0);
		time.setsecond(0);
		request = "";
		status = "";
		number_of_bytes = 0;
	}

}

std::ostream& operator<<(std::ostream& out, const LogEntry& log)
{
	out << "Host: " << log.host << '\n';

	out << "Day: " << log.date.getday() << '\n';
	out << "Month: " << log.date.getmonth() << '\n';
	out << "Year: " << log.date.getyear() << '\n';

	out << "Hour: " << log.time.gethour() << '\n';
	out << "Minute: " << log.time.getminute() << '\n';
	out << "Second: " << log.time.getsecond() << '\n';

	out << "Request: " << log.request << '\n';
	out << "Status: " << log.status << '\n';
	out << "Bytes: " << log.number_of_bytes << "\n\n";

	return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
//    char* line = new char[256];
    while (!in.eof()) {
        String line;
//        = getline(in);
//        std::cin.getline(line, 256);
        LogEntry log(line);
        result.push_back(log);
    }
    return result;
}


////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & voLogs) {
	
	for (int i = 0; i < voLogs.size(); ++i) {
		out << voLogs[i];
	}
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
	
	for (int i = 0; i < logs.size(); ++i) {
		out << logs[i].gethost() << '\n';
	}
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &logs) {
	int sum = 0;

	for (int i = 0; i < logs.size(); ++i) {
		sum += logs[i].getbytes();
	}
	return sum;
}
