#include<bits/stdc++.h>
using namespace std;
int pivotFunc(vector<int>&v,int low,int high){
    int pivot=v[low];       //first element of array
    int left=low;           //first pointer
    int right=high;         //second pointer
    while(left<right){      //till right doesn't cross left
        
        //if the element is smaller than pivot move towards right
        while(left<high && pivot>=v[left]){
            left++;
        }

        //if element is larger than pivot move towards left
        while(right>low && pivot<v[right]){
            right--;
        }

    //swap element to sort 
    if(left<right){
        swap(v[left],v[right]);
    }
}
    //swap the pivot so it can be placed at its right position
    swap(v[low],v[right]);
    return right;
}

void quick_sort(vector<int>&v,int low,int high){
    stack<pair<int,int>>st;
    st.push({low,high});
    while(!st.empty()){
        pair<int,int> curr = st.top();
        st.pop();
        int l = curr.first;
        int h =curr.second;
        int pi = pivotFunc(v,l,h);

        // If there are elements to the left of the pivot, push them to the stack
        if (l < pi - 1) {
            st.push({l, pi - 1});
        }

        // If there are elements to the right of the pivot, push them to the stack
        if(pi+1 < h) {
            st.push({pi+1,h});
        }
    }
}

int  main(){
    vector<int>v={4,8,7,1,9,3,2};

    for(int val:v) cout<<val<<" ";
    cout<<endl;

    quick_sort(v,0,v.size()-1);

    for(int val: v) cout<<val<<" ";
    cout<<endl;
    return 0;
}