#include<iostream>
#include "list.h"
using namespace std;

int main() {
    Link l;
    
    l.push_front(1);
    l.push_back(2);
    l.push_front(0);

    l.display();

    return 0;
}
