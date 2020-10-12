#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = new Node();
}

LinkedList::~LinkedList(){
    removeAll();
}

//insert - inserts the given item in the list (in alphabetical order)
//if it’s not already there (no duplicates). Returns true if successful.
bool LinkedList::insert(string insertname){
    // "" b d
    // "" b
    if(!head->next) head->next = new Node(insertname);
    else{
        Node* walker = head;
        while(walker->next){
            if(walker->next->name == insertname) return false;
            if(insertname < walker->next->name){
                break;
            }
            walker = walker->next;
        }
        Node* temp = new Node(insertname);
        if(walker->next) temp->next = walker->next;
        walker->next = temp;
    }

    return true;
}

//remove - removes the given item from the list. Returns true if successful.
bool LinkedList::remove(string removename){
    Node* walker = head;
    while(walker->next){
        if(walker->next->name == removename){
            Node* toremove = walker->next;
            walker->next = walker->next->next;
            delete toremove;
            return true;
        }
        walker = walker->next;
    }
    return false;
}

//print - prints the list in order
void LinkedList::print(){
    Node* temp = head;
    while(temp->next){
        cout << temp->next->name << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

//count - returns a count of the number of items in the list using recursion (no loops allowed)
int LinkedList::count(){
    return countHelper(head->next);
}

int LinkedList::countHelper(Node* p){
    if(p == NULL) return 0;
    else return 1 + countHelper(p->next);
}

//removeAll - removes all items from the list
void LinkedList::removeAll(){
    removeAllHelper(head);
}

void LinkedList::removeAllHelper(Node* p){
    if(p == NULL) return;
    else{
        removeAllHelper(p->next);
        Node* temp = p->next;
        p->next = NULL;
        delete temp;
    }
}

//printReverse - prints the list in reverse order using recursion (no loops allowed)
void LinkedList::printReverse(){
    printReverseHelper(head->next);
    cout << endl;
}

void LinkedList::printReverseHelper(Node* p){
    if(p == NULL) return;
    else{
        printReverseHelper(p->next);
        cout << p->name << " -> ";
    }
}
