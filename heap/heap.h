#include<iostream>
#include<vector>
using namespace std;


class Heap {
    vector<int> v;
public:
    Heap(int default_size = 10){
        v.reserve(default_size);
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);

        int index = v.size() - 1;
        int parent = index/2;

        while(index > 1 && v[parent] > v[index]){
            swap(v[parent], v[index]);
            index = parent;
            parent = index/2;
        }
    }

};