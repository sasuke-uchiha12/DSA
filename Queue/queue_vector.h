#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Queue {
    vector<T> container;

    public:
    Queue() = default;

    void push(T data){
        container.push_back(data);
    }

    void pop(){
        if(container.empty()){
            cout << "The queue is empty!" << endl;
        }else{
            container.erase(container.begin());
        }
    }

    void first(){
        if(container.empty()){
            cout << "The queue is empty!" << endl;
        }else{
            cout << *container.begin() << endl;
        }
    }
};