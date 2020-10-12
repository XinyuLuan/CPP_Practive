#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

class LinkedList
{
public:
    struct Node{
        string name;
        Node* next;

        Node(){
            name = "";
            next = NULL;
        }

        Node(string newname){
            name = newname;
            next = NULL;
        }
    };

    LinkedList();

    ~LinkedList();

    //insert - inserts the given item in the list (in alphabetical order)
    //if it’s not already there (no duplicates). Returns true if successful.
    bool insert(string insertname);

    //remove - removes the given item from the list. Returns true if successful.
    bool remove(string removename);

    //print - prints the list in order
    void print();

    //count - returns a count of the number of items in the list using recursion (no loops allowed)
    int count();

    //removeAll - removes all items from the list
    void removeAll();

    //printReverse - prints the list in reverse order using recursion (no loops allowed)
    void printReverse();
private:
    Node* head;
    int countHelper(Node* p);
    void removeAllHelper(Node* p);
    void printReverseHelper(Node* p);
};

#endif // LINKEDLIST_H
