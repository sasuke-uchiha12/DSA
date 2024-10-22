#include<iostream>
#include<vector>
using namespace std;


int parition(vector<int> &arr, int s, int e){
    int pivot = arr[e];
    int i = s - 1;
    for(int j = s; j < e-1; j++){
        if(pivot > arr[j]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}


void quickSort(vector<int> &arr, int s, int e){
    if(s>=e) return;

    int p = parition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}


int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}