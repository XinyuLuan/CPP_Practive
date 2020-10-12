#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList list;
    while(1){
        char option;
        cout << "please choose one option below" << endl;
        cout << "a - Add an item \n"
                "r - Remove an item \n"
                "d - Remove all items from the list\n"
                "e - exit" << endl;
        cin >> option;
        if(option == 'a'){
            string s;
            cout << "input a word for adding: " << endl;
            cin >> s;
            if(list.insert(s)) cout << "successful added " << s << endl;
            else cout << "failed to add " << s << endl;
            cout << "the list: ";
            list.print();
        }
        else if(option == 'r'){
           string s;
           cout << "input a word for removing: " << endl;
           cin >> s;
           if(list.remove(s)) cout << "successful removed " <<s<< endl;
           else cout << "failed to remove " << s << endl;
           cout << "the list: ";
           list.print();
        }
        else if(option == 'd'){
            char cf;
            cout << "Do you confirm to delete all element in the Linkedlist?\n"
                 << "y - yes\nn-no" << endl;
            cin >> cf;
            if(cf == 'y'){
                list.removeAll();
                cout << "removed all element" << endl;
            }
            else if(cf == 'n'){
                cout << "the list: ";
                list.print();
                continue;
            }
            else cout << "wrong input for confirmation" << endl;
            cout << "the list: ";
            list.print();
        }
        else if(option == 'e') break;
        else cout << "wrong input!!" << endl;
        cout << endl << endl;
    }


    /**
    list.insert("b");
    list.print();
    list.insert("d");
    list.print();
    list.insert("a");
    list.print();
    list.insert("c");
    list.print();
    list.insert("e");
    list.print();
    list.insert("");
    list.print();
    list.insert("c");
    list.print();

    if(list.remove("c")){
        cout << "remove c successful" << endl;
        list.print();
    }
    else{
        cout << "remove c failed" << endl;
    }

    if(list.remove("")){
        cout << "remove \"\" successful" << endl;
        list.print();
    }
    else{
        cout << "remove \"\" failed" << endl;
    }

    cout << "The size: " << list.count() << endl;

    list.printReverse();

    list.removeAll();
    list.print();
    */
    return 0;
}
