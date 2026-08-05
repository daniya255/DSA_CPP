class Solution {
public:
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

        // Step 3: Build the result string by iterating backwards from highest
        // frequency
        string result = "";
        for (int i = s.size(); i > 0; i--) {
            if (!buckets[i].empty()) {
                result += buckets[i];
            }
        }

        return result;
    }
};