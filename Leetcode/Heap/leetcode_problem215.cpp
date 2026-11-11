class Solution {
public:
    void siftDown(vector<int>& nums, int ind, int n) {

        while (true) {
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            int largestInd = ind;

            if (leftChild < n && nums[leftChild] > nums[largestInd]) {
                largestInd = leftChild;
            }

            if (rightChild < n && nums[rightChild] > nums[largestInd]) {
                largestInd = rightChild;
            }

            if (ind != largestInd) {
                swap(nums[ind], nums[largestInd]);
                ind = largestInd;
            }

            else
                break;
        }
    }

    void heapify(vector<int>& nums, int n) {
        if (n <= 1)
            return;
        int i = (n / 2) - 1;
        while (i >= 0) {
            siftDown(nums, i, n);
            i--;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 0 || k > n)
            return -1;
        heapify(nums, n);
        int currentSize = n;
        int kthElement = -1;
        for (int i = 0; i < k; i++) {
            kthElement = nums[0];
            nums[0] = nums[currentSize - 1];
            currentSize--;
            siftDown(nums, 0, currentSize);
        }
        return kthElement;
    }
};