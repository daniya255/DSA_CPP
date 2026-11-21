class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            topK;
        for (auto pair : freq) {
            int element = pair.first;
            int count = pair.second;
            topK.push({count, element});
            if (topK.size() > k)
                topK.pop();
        }

        vector<int> result;
        while (!topK.empty()) {
            result.push_back(topK.top().second);
            topK.pop();
        }

        return result;
    }
};