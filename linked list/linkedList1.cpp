#include<iostream>
#include "list1.h"
using namespace std;

int main() {
    Link l;
    l.push_front(2);
    l.push_front(0);
    l.insert(1, 1);
    Node * head = l.getHead();
    l.searchRecursive(head, 2, 0);
    l.search(2);
    l.display();

    return 0;
}