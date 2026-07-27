class Solution {
public:
 // Function to determine if mid is the possible distance or not
    bool isPossible(vector<int>& positions, int mid,int m) {
        // Initialize count of balls placed by 1
        int balls_placed = 1;

        // first balls is placed at the first index so that the distance can be farthest
        int last_position = positions[0];

        // Loop through each position in the array
        for (int i=1;i<positions.size();i++) {
            // Check if the current position minus last position is equals to or greater than mid
            if (positions[i]-last_position>=mid) {
                balls_placed++;

                //update last position
                last_position=positions[i];
            }
        }

        // Return true if all balls are placed
        return balls_placed>=m;
    }

    int maxDistance(vector<int>& positions, int m) {
         //sorting the array
        sort(positions.begin(),positions.end());
        // Find min distnace between balls
        int low = 1;

        // Calculate the max distance between balls
        int high = *max_element(positions.begin(),positions.end()) - *min_element(positions.begin(),positions.end());

        int ans=1;

        // Binary search loop to find optimal distance between low and high
        while (low <= high) {
            // Calculate mid value as potential distance to test
            int mid = (low + high) / 2;

            // Check if the current capacity is a possible answer
            bool check = isPossible(positions, mid,m);

            if (check) {
                ans=mid;
                low=mid+1;

            } else {
                // If all balls can't be placed deccrease mid(distnace)
                high=mid-1;
            }
        }

        return ans;
    }
};