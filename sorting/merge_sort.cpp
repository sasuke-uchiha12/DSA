#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int s, int e) {
    int m = (s + e) / 2;
    int i = s; // Starting index of the left subarray
    int j = m + 1; // Starting index of the right subarray

    vector<int> temp;

    // Merge the two halves into temp
    while (i <= m && j <= e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= m) {
        temp.push_back(array[i++]);
    }

    // Copy remaining elements from the right subarray, if any
    while (j <= e) {
        temp.push_back(array[j++]);
    }

    // Copy back the merged elements into the original array
    for (int k = 0; k < temp.size(); k++) {
        array[s + k] = temp[k];
    }
}

void mergesort(vector<int> &arr, int s, int e) {
    if (s >= e) {
        return; // Base case
    }
    
    int mid = (s + e) / 2;
    mergesort(arr, s, mid); // Sort the left half
    mergesort(arr, mid + 1, e); // Sort the right half
    merge(arr, s, e); // Merge the sorted halves
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergesort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
