#include<bits/stdc++.h>
using namespace std;
int rotated_search(vector<int>& arr, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        
        if (arr[i]==x) return i;

    }
    return cnt;
}

int main()
{
    vector<int> arr =  {4,5,6,7,0,1,2,4};
    int n = 8, x = 8;
    int ans = rotated_search(arr, n, x);
    cout << "The index of the target in the rotated array is: "
         << ans << "\n";
    return 0;


//Time Complexity : O(N) linear search
//Space Complexity : O(1) const space required
