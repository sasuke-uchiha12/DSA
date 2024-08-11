#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int d): data(d), next(nullptr){}

    int getData(){
        return data;
    }
};

class Link{
    Node* head;
    Node* tail;

    public:
    Link(): head(nullptr), tail(nullptr){}

    Node* getHead(){
        return head;
    }

    //destructor
    ~Link(){
        Node * temp = head;
        if(temp != nullptr){
            while(temp != nullptr){
                Node *nextNode = temp->next;
                delete temp;
                temp = nextNode; 
            }
            cout << "destructor is called!" << endl;
        }
        head = tail = nullptr; //if not it may cause dangling pointer, double deletion
    }

    void push_front(int data){
        if(head == nullptr){
            Node *n = new Node(data);
            head = tail = n;
        }else{
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        Node *n = new Node(data);
        if(head == nullptr){ 
            head = tail = n;
        }
        else{
            tail->next = n; //note: both head and tail point to first and last node respectively
            tail = n;
        }
    }

    void display(){
        Node *current = head;
        if(current == nullptr){
            cout << "This is a empty Linked List!" << endl;
            return;
        }
        while(current!=nullptr){
            cout << current->getData() << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void insert(int data, int pos){
        Node *n = new Node(data);
        if(pos == 0){
            push_front(data);
            return;
        }

        Node *temp = head;
        for(int i = 1; i < pos; i++){
            temp = temp->next; 
            if(temp == nullptr){
                cout << "You have reached the end! " << i << " - is the last position!"<< endl;
                return;
            }
        }
        n->next = temp->next;
        temp->next = n;
    }

    //linear - search
    void search(int key){
        Node *temp = head;
        int idx = 0;
        while(temp != nullptr){
            if(temp->data == key){
                cout << idx << endl;
                return;
            }
            temp = temp->next;
            idx++;
        }
        cout << "Can't find the key element!" << endl;
    }

    //search - recursive
    void searchRecursive(Node * head, int key, int idx){
        Node *temp = head;
        if(temp == nullptr){
            cout << "no element!" << endl;
            return;
        }
        if(temp->data == key){
            cout << "key is present! - " << idx << endl;
            return;
        }
        else{
            return searchRecursive(temp->next, key, idx + 1);
        }
    }

    //pop front
    void pop_front(){
        Node *temp = head;
        if(temp == nullptr){
            cout << "Linked List is empty!" << endl;
            return;
        }
        if(temp != nullptr){
            delete head;
            // head = temp->next;
            if(temp->next == nullptr){
                head = tail = nullptr;
            }else{
                head = temp->next;
            }
        }
    
    }

    //Reverse a linked list
    void reverseList(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            tail = head;
        }

        Node * current = head;
        Node * prev = nullptr;
        Node * next = nullptr;

        tail = head;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};