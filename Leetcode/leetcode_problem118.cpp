class Solution {
public:
    vector<int> generate_row(int r) {
        vector<int> row;
        int ans = 1;
        row.push_back(ans);
        for (int i = 1; i < r; i++) {
            ans *= (r - i);
            ans /= i;
            row.push_back(ans);
        }
        return row;
    }

    vector<vector<int>> generate(int r) {
        vector<vector<int>> triangle;
        // runs from 1--->rth row
        for (int i = 1; i <= r; i++) {
            triangle.push_back(generate_row(i));
        }
        return triangle;
    }
};