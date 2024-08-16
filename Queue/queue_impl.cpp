#include<iostream>
#include "queue_vector.h"
using namespace std;

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.first();
    q.pop();
    q.first();
    return 0;
}