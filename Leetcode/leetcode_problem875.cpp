class Solution {
public:
    bool isPossible(vector<int>& piles, int hour, int rate) {
        long long total_hours = 0;
        for (int i = 0; i < piles.size(); i++) {
                total_hours += (piles[i] + rate - 1) / rate;
            
        }

        return hour >= total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int possible_ans;

        while (low <= high) {

            int mid = (low + high) / 2;
            int ans = isPossible(piles, h, mid);

            if (ans) {
                possible_ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return possible_ans;
    }
};