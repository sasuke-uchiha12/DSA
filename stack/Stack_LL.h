#include<iostream>
using namespace std;

template<typename T>
class Stack;


template<typename T>
class Node{
    public:
    T data;
    Node<T> * next;

    Node(T d): data(d), next(nullptr){}

    T getData(){
        return data;
    }
};

template<typename T>
class Stack{
    Node<T> * head;
    public:
    Stack(): head(nullptr){}

    void push(T data){
        if(head ==nullptr){
            Node<T> *n = new Node<T>(data);
            head = n;
        }else{
            Node<T> *n = new Node<T>(data);
            n->next = head;
            head = n;
        }
    }

    void top(){
        if(head == nullptr){
            cout << "The Stack is empty!" << endl;
        }else{
            cout << head->getData() << endl;
        }
    }

    void pop(){
        if(head == nullptr){
            cout << "The stack is empty!" << endl;
        }else{
            Node<T> * temp = head;
            head = temp->next;
            delete temp;
        }
    }
};