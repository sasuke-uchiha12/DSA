#include<iostream>
using namespace std;

class Node {
    int data;

    public:

    Node* next;
    //way 1 - assignment
    // Node(int d){
    //     data = d;
    //     next = nullptr;
    // }

    //way 2 - Initi list (preferred) 
    Node(int d): data(d), next(nullptr){}

    int getData(){
        return data;
    }

    Node * getNext(){
        return next;
    }
};

class Link {
    Node* head;
    Node* tail;

    public:
    Link(): head(nullptr), tail(nullptr){}

    Node * begin(){
        return head;
    }

    //push front
    void push_front(int data){
        //creating a new node
        Node * n = new Node(data);
        if(head == nullptr){
            head = tail = n;
        }
        else{
            n->next = head;
            head = n;
        }
    }

    //push back
    void push_back(int data){
        //creating a new node
        Node * n = new Node(data);
        if(head == nullptr){
            head = tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
    }

    //display all elements
    void display(){
        Node * current = head;
        while(current!=nullptr){
            cout << current->getData() << " -> ";
            current = current->getNext();
        }
        cout << "nullptr" << endl;
    }
};