#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    // return n >> i & 1 > 0 ? 1 : 0; //method 1
    return 1 << i & n > 0 ? 1 : 0;
}

void setIthBit(int &n, int i){
    int mask = 1 << i;
    n = n|mask;
}

int main(){
    int n = 5;
    int i;
    cin >> i;
    cout << n << endl;
    cout << getIthBit(n, i) << endl;
    setIthBit(n, i);
    cout << n;
    
    return 0;
}