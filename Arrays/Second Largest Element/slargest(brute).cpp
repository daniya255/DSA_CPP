#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int slargest(vector<int>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    int slargest=v[n-2];

    return slargest;
}
int main(){
    vector<int>arr={2,1,5,3,6,2,8};
    cout<<"The second largest element is : "<<slargest(arr);
    return 0;
}