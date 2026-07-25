class Solution {
public:
 bool isPossible(vector<int> &blooms, int d, int m, int k)
{
    int count = 0;
    int bouquets = 0;

    for (int bloom : blooms)
    {

        if (bloom <= d)
        {
            count++;
            if (count == k)
            {
                bouquets++;
                count = 0;
            }
        }

        else
            count = 0;
    }

    return bouquets >= m;
}
      
int minDays(vector<int> &blooms, int m, int k)
{
    long long total_flowers=(long long)m*k;
    if (blooms.size() < total_flowers)
        return -1;

    int low = *min_element(blooms.begin(), blooms.end());
    int high = *max_element(blooms.begin(), blooms.end());
    int possible_ans = -1;

    while (low <= high)
    {

        int mid = (low + high) / 2;
        bool ans = isPossible(blooms, mid, m, k);

        if (ans)
        {
            possible_ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return possible_ans;
    }
};