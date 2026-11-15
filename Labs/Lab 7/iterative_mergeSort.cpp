#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
    int i = left;       // Starting index for left sub-array
    int j = mid + 1;    // Starting index for right sub-array
    int k = left;       // Starting index to store merged elements

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back into the original array
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

// Iterative (Bottom-Up) Merge Sort
void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    // Temporary array to store merged results to avoid repeated allocations
    vector<int> temp(n);

    // Sublist width starts at 1 and doubles in each iteration: 1, 2, 4, 8, ...
    for (int width = 1; width < n; width = 2 * width) {
        // Iterate through the array, merging sublists of size 2 * width
        for (int left = 0; left < n - 1; left += 2 * width) {
            int mid = min(left + width - 1, n - 1);
            int right = min(left + 2 * width - 1, n - 1);
            
            merge(arr, left, mid, right, temp);
        }
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    iterativeMergeSort(arr);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}