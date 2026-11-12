#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(std::vector<int> &arr)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> rankMap;
    int rank = 1;

    for (int num : sortedArr)
    {
        if (rankMap.find(num) == rankMap.end())
        {
            rankMap[num] = rank++;
        }
    }

    vector<int> result;

    for (int num : arr)
    {
        result.push_back(rankMap[num]);
    }

    return result;
}


//Space Complexity : O(N) for hashmap and additional vector
//Time Complexity : O(N logN) : sorting + duplicating array + generating result vector + building hashmap