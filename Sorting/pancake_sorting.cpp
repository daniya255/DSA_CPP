#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void flip(vector<int>& arr, int k) {
        int i = 0, j = k - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int currSize = n; currSize > 1; currSize--) {
            int maxIdx = 0;
            for (int i = 1; i < currSize; i++) {
                if (arr[i] > arr[maxIdx]) {
                    maxIdx = i;
                }
            }

            if (maxIdx == currSize - 1) continue;

            if (maxIdx != 0) {
                res.push_back(maxIdx + 1);
                flip(arr, maxIdx + 1);
            }

            res.push_back(currSize);
            flip(arr, currSize);
        }
        return res;
    }
};

int main() {
    vector<int> arr = {3, 2, 4, 1};
    Solution sol;
    vector<int> flips = sol.pancakeSort(arr);
    cout << "K-values sequence: ";
    for (int k : flips) cout << k << " ";
    return 0;
}