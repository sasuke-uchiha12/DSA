#include<iostream>
#include<stack>
using namespace std;

void push_AtBottom(int data, stack<int> &s) {
    //base case
    if(s.empty()){
        s.push(data);
        return;
    }

    //recursive case
    int temp = s.top();
    s.pop();
    push_AtBottom(data, s);
    s.push(temp);

}

void reverseStack(stack<int> &s){
    
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);

    push_AtBottom(temp, s);

}



int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // push_AtBottom(6, s);

    reverseStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}