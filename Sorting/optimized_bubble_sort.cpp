#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(vector<int> &ss)
{

    int n = ss.size(); // size of the vector

    // from first to 2 last index
    for (int i = 0; i <= n - 2; i++)
    {
        bool swapped = false;

        // This loop compares an element to its adjacent elements leaving the sorted element at last
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ss[j] > ss[j + 1])
            {
                swapped = true;
                swap(ss[j], ss[j + 1]);
            }
        }
        //This means the vector is already sorted (best case)
        if(!swapped) break;
    }
}

// helper function for printing the vector
void print(vector<int> &ss)
{
    for (auto &val : ss)
        cout << val << " ";
    cout << endl;
}
int main()
{

    vector<int> v = {23, 65, 12, 87, 33, 76};

    cout << "Original Vector : " << endl;
    print(v);

    cout << "Sorted Vector : " << endl;
    bubble_sort(v);
    print(v);

    return 0;
}