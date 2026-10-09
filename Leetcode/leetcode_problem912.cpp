class Solution {
public:
    void merge(vector<int>& v, int low, int mid, int high) {

        int left = low;      // pointer to first array
        int right = mid + 1; // pointer to second array
        vector<int> temp;    // temp array

        // loops till one of the pointer reaches its last index
        while (left <= mid && right <= high) {
            if (v[left] <= v[right]) {
                temp.push_back(v[left]);
                left++;
            } else {
                temp.push_back(v[right]);
                right++;
            }
        }

        // loop tills all elements of the first array are appended
        while (left <= mid) {
            temp.push_back(v[left]);
            left++;
        }

        // loop tills all elements of the second array are appended
        while (right <= high) {
            temp.push_back(v[right]);
            right++;
        }

        // copy elements from temp space to the original array
        for (int i = low; i <= high; i++) {
            v[i] = temp[i - low];
        }
    }

    // fucntion for dividing array into sub-arrays
    void mergesort(vector<int>& v, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;

        // recursive calls to mergesort()
        mergesort(v, low, mid);      // first sub-array
        mergesort(v, mid + 1, high); // second sub-array
        merge(v, low, mid, high);    // sort and merge array
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};