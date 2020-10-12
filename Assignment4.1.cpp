#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

class Car{
public:    
    Car(){
        reportingMark = "";
        carNumber = 0;
        kind = "other";
        loaded = false; 
        destination = "NONE";
    }
    Car(const Car & c){
        reportingMark = c.reportingMark;
        carNumber = c.carNumber;
        kind = c.kind;
        loaded = c.loaded;
        destination = c.destination;
    }
    Car(string rm, int c, string k, string l, string des){
        reportingMark = rm;
        carNumber = c;
        kind = k;
        loaded = l == "true" ? true : false;
        destination = des;
    }
    ~Car(){

    }

    // An accessor is a class method used to read data members
    string getreportingMark(){
        return reportingMark;
    }
    int getcarNumber(){
        return carNumber;
    }
    string getkind(){
        return kind;
    }
    bool getloaded(){
        return loaded;
    }
    string getdestination(){
        return destination;
    }

    // a mutator is a class method used to change data members.
    void setreportingMark(string rm){
        reportingMark = rm;
    }
    void setcarNumber(int cn){
        carNumber = cn;
    }
    void setkind(string k){
        kind = k;
    }
    void setloaded(bool l){
        loaded = l;
    }
    void setdestination(string des){
        destination = des;
    }

    void output(){
        //change function to private number
        cout << "reportingMark: " << reportingMark << endl;
        cout << "carNumber: " << carNumber << endl;
        cout << "kind: " << kind << endl;
        (loaded == true) ? cout << "loaded: " << "true" << endl : cout << "loaded: " <<"false" << endl;
        cout << "destination: " << destination << endl;
    }

    void setUp(string rm, int c, string k, string l, string des){
        reportingMark = rm;
        carNumber = c;
        kind = k;
        loaded = l == "true" ? true : false;
        destination = des;
    }

    /*
        A friend function of a class is defined outside that class' scope but it has the right to 
        access all private and protected members of the class.

        Even though the ***prototypes for friend functions appear in the class definition***, 
        friends are ***not member functions***.
     */
    friend bool operator==(const Car& lhs, const Car& rhs){
        if(lhs.reportingMark == rhs.reportingMark && lhs.carNumber == rhs.carNumber) return true;
        else return false;
    }
private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
};

void input(){
    string tempstr1;
    int tempint;
    string tempstr2;
    string load;
    string tempstr3;

    ifstream inputFile("cardata.txt", std::ifstream::binary);
    if(!inputFile){
        cerr << "the file is not available" << endl;
        exit(0);
    }

    string type;
    while(inputFile.peek() != EOF){
        inputFile >> type;
        while(inputFile.peek() == ' ') inputFile.get();
        inputFile >> tempstr1;
        while(inputFile.peek() == ' ') inputFile.get();
        inputFile >> tempint;
        while(inputFile.peek() == ' ') inputFile.get();
        inputFile >> tempstr2;
        while(inputFile.peek() == ' ') inputFile.get();
        inputFile >> load;
        while(inputFile.peek() == ' ') inputFile.get();
        inputFile >> tempstr3;
        
        Car temp(tempstr1, tempint, tempstr2, load, tempstr3);
        temp.output();
        cout << endl << endl;
    }
    inputFile.close();
}




int main(){
    input();
}
