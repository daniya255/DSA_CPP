#include <iostream>
#include <vector>
using namespace std;

void permuteHelper(vector<int>& nums, int index, vector<vector<int>>& res) {
    if (index == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        permuteHelper(nums, index + 1, res);
        swap(nums[index], nums[i]); // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permuteHelper(nums, 0, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (const auto& vec : res) {
        cout << "[ ";
        for (int num : vec) cout << num << " ";
        cout << "] ";
    }
    cout << endl;
    return 0;
}