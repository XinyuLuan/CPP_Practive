#include <iostream>
#include <string>

using namespace std;

// const string KINDS = {"box", "tank", "flat", "other"};

struct Car{
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

    Car(){
        loaded = false; 
        destination = "NONE";
    }
};

void input(Car* car){
    // char temp[6];
    cout << "please input reportMart: ";
    cin >> car->reportingMark;
    // cin.getline(temp, 6);
    // cout << temp << endl;
    if (car->reportingMark.size() > 5){
        cout << "the reportMart is too long" << endl;
    }
    for(int j = 0; j < 5; j++){
        if(car->reportingMark[j] != '\0' && !isupper(car->reportingMark[j])){
            cout << "the reportMart is not correct, all character should be in uppercase" << endl;
            return;
        }
    }

    cout << "please input car number: ";
    cin >> car->carNumber;

    cout << "please input your kind of car: ";
    cin >> car->kind;
    // int i = 0;
    // for( ; i < 4; i++ ){
    //     if(KINDS[i] == car->kind) break;
    // }
    // if(i == 4) cout << "The kind input is not currect";
    
    string loaded_s;
    cout << "please input loaded status: ";
    cin >> loaded_s;
    if(loaded_s == "true") car->loaded = true;
    else if(loaded_s == "false") car->loaded = false;
    else{
        cout << "the input is not currect" << endl;
        return;
    } 

    cout << "please input the destination: ";
    cin >> car->destination;
    // cout << (car->reportingMark).size() << "   " << car->reportingMark << endl;    
}

void output(Car* car){
    cout << "reportingMark: " << car->reportingMark << endl;
    cout << "carNumber: " << car->carNumber << endl;
    cout << "kind: " << car->kind << endl;
    (car->loaded == true) ? cout << "loaded: " << "true" << endl : cout << "loaded: " <<"false" << endl;
    cout << "destination: " << car->destination << endl;
}


int main(){
    Car* newcar = new Car();
    input(newcar);
    output(newcar);
    delete newcar;
    return 0;
}
