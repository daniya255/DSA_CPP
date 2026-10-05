#include<bits/stdc++.h>
using namespace std;
vector<int>nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> nextGreater;
    stack<int> st;

    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            nextGreater[st.top()] = x;    
            st.pop();
        }
        st.push(x);
    }
    while (!st.empty()) {                 
        nextGreater[st.top()] = -1;
        st.pop();
    }

    vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(nextGreater[nums1[i]]);
        }

    return result;
}