#include <vector>
#include <algorithm>
using namespace std;
vector<int> arrayRankTransform(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};
    vector<pair<int, int>> valIndex(n);
    for (int i = 0; i < n; ++i)
    {
        valIndex[i] = {arr[i], i};
    }

    sort(valIndex.begin(), valIndex.end());

    vector<int> result(n);
    int rank = 1;

    result[valIndex[0].second] = rank;

    for (int i = 1; i < n; ++i)
    {
        // If the current value is greater than the previous unique value, increment rank
        if (valIndex[i].first > valIndex[i - 1].first)
        {
            rank++;
        }
        // Assign the computed rank back to its original index position
        result[valIndex[i].second] = rank;
    }

    return result;
}
