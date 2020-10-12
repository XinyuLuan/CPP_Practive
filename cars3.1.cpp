#include <iostream>
#include <string>

using namespace std;

class Car{
public:
    Car(){
        carNumber = 0;
        loaded = false; 
        destination = "NONE";
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

private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
};

void input(string& tempstr1, int& tempint, string& tempstr2, string& load, string & tempstr3){
    cout << "please input reportMart: ";
    cin >> tempstr1;
    if (tempstr1.size() > 5){
        cout << "the reportMart is too long" << endl;
    }
    for(int j = 0; j < 5; j++){
        if(tempstr1[j] != '\0' && !isupper(tempstr1[j])){
            cout << "the reportMart is not correct, all character should be in uppercase" << endl;
            return;
        }
    }

    cout << "please input car number: ";
    cin >> tempint;

    cout << "please input your kind of car: ";
    cin >> tempstr2;
    cout << "please input loaded status: ";
    cin >> load;

    cout << "please input the destination: ";
    cin.ignore();
    getline(cin, tempstr3);
}




int main(){
    string reportingMark_;
    int carnumber_;
    string kind_;
    string loaded_;
    string destination_;
    
    Car newcar;

    input(reportingMark_, carnumber_, kind_, loaded_, destination_);
    newcar.setUp(reportingMark_, carnumber_, kind_, loaded_, destination_);
    newcar.output();
}
