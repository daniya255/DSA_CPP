#include <bits/stdc++.h>
using namespace std;
 // Helper function to check if it's possible to make m bouquets on or before a given day
bool isPossible(vector<int> &blooms, int d, int m, int k)
{
    int count = 0;
    int bouquets = 0;

    for (int bloom : blooms)
    {

        if (bloom <= d)
        {
            // Flower bloomed, increment consecutive count
            count++;
            if (count == k)
            {
                bouquets++;
                count = 0;
            }
        }

        else{
        // Flower not bloomed, reset consecutive count
            count = 0;
        }
    }
    // Check if at least m bouquets can be made
    return bouquets >= m;
}
// Main function to find the minimum day to make m bouquets
int minDays(vector<int> &blooms, int m, int k)
{
    long long total_flowers=(long long)m*k;

    // If total required flowers > available flowers, it's impossible
    if (blooms.size() < total_flowers)
        return -1;

    // Find minimum and maximum bloom days from array
    int low = *min_element(blooms.begin(), blooms.end());
    int high = *max_element(blooms.begin(), blooms.end());
    int possible_ans = -1;

    while (low <= high)
    {

        int mid = (low + high) / 2;
        bool ans = isPossible(blooms, mid, m, k);

        if (ans)
        {
            // If it's possible to make bouquets on this day, try to find an earlier day
            possible_ans = mid;
            high = mid - 1;
        }
        else
        {
            // Otherwise, try with a later day
            low = mid + 1;
        }
    }

    return possible_ans;
}

int main()
{
   vector<int> blooms = {1,10,3,10,2};
    int m=3, k=1;
    int ans = minDays(blooms,m,k);
    cout << "The minimum days required are  : " << ans <<  endl;
    return 0;
}

//Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
//Space Complexity : O(h)O(1) as we are not using any extra space to solve this problem.