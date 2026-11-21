#include <bits/stdc++.h>
using namespace std;
string freqChar(string &s)
{
    if (s.size() <= 1)
        return s;
    string result = "";
    unordered_map<char, int> hashmap;
    for (char ch : s)
        hashmap[ch]++;

    priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
    for (const auto &entry : hashmap)
    {
        char ch = entry.first;
        int freq = entry.second;
        maxHeap.push({freq, ch});
    }

    while (!maxHeap.empty())
    {
        int freq = maxHeap.top().first;
        char ch = maxHeap.top().second;
        maxHeap.pop();
        result.append(freq, ch);
    }
    return result;
}

int main()
{
    string s = "cccaaa";
    string result = freqChar(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}