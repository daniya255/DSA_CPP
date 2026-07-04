#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//If quick sort is used:
//---Time Complexity O(nlogn)---->sorting
//---Space complexity O(1)------>auxiliary space
int largest_element(vector<int>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    return v[n-1];
}
int main(){
    vector<int>v={5,3,7,2,8,1,5};
    cout<<"The largest element is : "<<largest_element(v);
    return 0;
}