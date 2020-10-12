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
private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
};

void input(Car* car){
    string temp1;
    cout << "please input reportMart: ";
    cin >> temp1;
    if (temp1.size() > 5){
        cout << "the reportMart is too long" << endl;
    }
    for(int j = 0; j < 5; j++){
        if(temp1[j] != '\0' && !isupper(temp1[j])){
            cout << "the reportMart is not correct, all character should be in uppercase" << endl;
            return;
        }
    }
    car->setreportingMark(temp1);

    int temp2 = 0;
    cout << "please input car number: ";
    cin >> temp2;
    car->setcarNumber(temp2);

    temp1 = "";
    cout << "please input your kind of car: ";
    cin >> temp1;
    car->setkind(temp1);
    
    string loaded_s;
    cout << "please input loaded status: ";
    cin >> loaded_s;
    if(loaded_s == "true") car->setloaded(true);
    else if(loaded_s == "false") car->setloaded(false);
    else{
        cout << "the input is not currect" << endl;
        return;
    } 

    temp1 = "";
    cout << "please input the destination: ";
    cin >> temp1;
    car->setdestination(temp1); 
}

void output(Car* car){
    cout << "reportingMark: " << car->getreportingMark() << endl;
    cout << "carNumber: " << car->getcarNumber() << endl;
    cout << "kind: " << car->getkind() << endl;
    (car->getloaded() == true) ? cout << "loaded: " << "true" << endl : cout << "loaded: " <<"false" << endl;
    cout << "destination: " << car->getdestination() << endl;
}


int main(){
    Car* newcar = new Car();
    input(newcar);
    output(newcar);
    delete newcar;
    return 0;
}
