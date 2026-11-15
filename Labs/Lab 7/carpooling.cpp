#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {

    map<int, int> timestamp;
    for (const auto& trip : trips) {
        int passengers = trip[0];
        int start = trip[1];
        int end = trip[2];
        
        timestamp[start] += passengers;
        timestamp[end] -= passengers;
    }
    
    int currentPassengers = 0;
    for (auto& pair : timestamp) {
        currentPassengers += pair.second;
        if (currentPassengers > capacity) {
            return false;
        }
    }
    return true;
}