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

    // Car operator= ************************************************** 
    Car & operator=(const Car & carB) {
        reportingMark = carB.reportingMark; 
        carNumber = carB.carNumber; 
        kind = carB.kind; 
        loaded = carB.loaded; 
        destination = carB.destination;
        return * this;
    }
    /*
        A friend function of a class is defined outside that class' scope but it has the right to 
        access all private and protected members of the class.

        Even though the ***prototypes for friend functions appear in the class definition***, 
        friends are ***not member functions***.
     */
    friend bool operator==(const Car& lhs, const Car& rhs);
private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
};

class StringOfCars{
public:
    StringOfCars(){
        p = new Car[ARRAY_MAX_SIZE];
        size = 0;
    }
    StringOfCars(const StringOfCars & sc){
        p = new Car[ARRAY_MAX_SIZE];
        Car* temp1 = p;
        Car* temp2 = sc.p;
        size = sc.size;
        for(int i = 0; i < size; i++){
            *temp1 = *temp2;
            temp1++;
            temp2++;
        }
    }
    // StringOfCars & operator=(const StringOfCars & s){
    //     Car* p = new Car[ARRAY_MAX_SIZE];
    //     Car* temp1 = p;
    //     Car* temp2 = sc.p;
    //     size = sc.size;
    //     for(int i = 0; i < size; i++){
    //         *temp1 = *temp2;
    //         temp1++;
    //         temp2++;
    //     }
    // }
    ~StringOfCars(){
        delete [] p;
    }
    void push(Car c){
        if(size < ARRAY_MAX_SIZE){
            Car* temp = p;
            temp = temp + size;
            *temp = c;
            size++;
        }
    }
    Car pop(){
        Car temp;
        if(size != 0){
            temp = *(p+size-1);
            *(p+size-1) = Car();
            size--;
        }
        return temp;
    }

    void output(){
        Car* temp = p;
        for(int i = 0; i < size; i++){
            cout << "Car " << i << ": "; 
            temp++->output();
            cout << endl<< endl;
        }
    }
private:
    static const int ARRAY_MAX_SIZE = 10;
    Car* p;
    int size;

};
bool operator==(const Car& lhs, const Car& rhs){
    if(lhs.reportingMark == rhs.reportingMark && lhs.carNumber == rhs.carNumber) return true;
    else return false;
}


void input(StringOfCars & soc);
int main(){
    // cout << "TEST1" << endl;
    // Car car1("SP", 34567, "box", "true", "Salt Lake City");
    // Car car2 = car1;
    // car2.output();

    StringOfCars string1;
    cout << "TEST2" << endl;
    input(string1);
    cout << "STRING1" << endl;
    string1.output();

    cout << "^^^^^^^^^^^^^^^^TEST3^^^^^^^^^^^^^^^^^^^^" << endl;
    Car car3;
    car3 = string1.pop();
    cout << "CAR3" << endl;
    car3.output();
    cout << "STRING1" << endl;
    string1.output();

}

void input(StringOfCars & soc){
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
        // inputFile >> tempstr3;
        getline(inputFile, tempstr3);
        
        Car temp(tempstr1, tempint, tempstr2, load, tempstr3);
        // cout << "OUTPUT    !" << endl;
        // temp.output();
        // cout << endl << endl;
        soc.push(temp);
    }
    inputFile.close();
}





