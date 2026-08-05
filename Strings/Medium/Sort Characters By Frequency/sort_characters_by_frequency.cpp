#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string frequencySort(string s) {
    // Step 1: Count frequencies
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }

    // Step 2: Create buckets where index = frequency
    // Max possible frequency is s.size(), so size is s.size() + 1
    vector<string> buckets(s.size() + 1, "");
    for (auto& pair : freqMap) {
        char ch = pair.first;
        int freq = pair.second;
        // Append the character to its frequency bucket
        buckets[freq].append(freq, ch); 
    }

    // Step 3: Build the result string by iterating backwards from highest frequency
    string result = "";
    for (int i = s.size(); i > 0; i--) {
        if (!buckets[i].empty()) {
            result += buckets[i];
        }
    }

    return result;
}

int main() {
    string s = "tree";
    cout << frequencySort(s) << endl; // Output: "eetr" (or "eert")
    return 0;
}

//Time Complexity: O(N) — We loop through the string once to count frequencies, place characters into buckets in linear time, and traverse the buckets from back to front. No sorting or heap overhead!
//Space Complexity: O(N) — To store the frequency map and the bucket strings.