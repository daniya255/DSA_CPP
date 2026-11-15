#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }
    
    int maxLength = 0;
    for (auto& pair : countMap) {
        int num = pair.first;

        if (countMap.find(num + 1) != countMap.end()) {
            int currentLength = pair.second + countMap[num + 1];
            maxLength = max(maxLength, currentLength);
        }
    }
    return maxLength;
}