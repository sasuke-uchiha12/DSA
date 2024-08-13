#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack {
    public: 
    vector<T> container;

    Stack() =  default;

    void push(T data){
        container.push_back(data);
    }

    void pop(){
        if(container.empty()){
            cout << "The stack is empty!" << endl;
        }else{
            container.pop_back();
        }
    }

    T top() const{
        if(container.empty()){
            cout << "The stack is empty!" << endl;
            return T();
        }else{
            return container.back();
        }
    }
};