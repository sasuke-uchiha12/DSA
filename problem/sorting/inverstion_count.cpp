#include <iostream>
#include <vector>
using namespace std;

int inverstionCount(vector<int> &arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(i != j){
                if(arr[i] > arr[j] && i < j){
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {0, 5, 2, 3, 1};
    cout << inverstionCount(arr);

    return 0;
}