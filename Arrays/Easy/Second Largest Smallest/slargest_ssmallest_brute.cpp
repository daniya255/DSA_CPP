#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> slargest(vector<int>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    int slargest=v[n-2];
    int ssmallest=v[1];

    vector<int>result={slargest,ssmallest};
    return result;
}
int main(){
    vector<int>arr={2,1,5,3,6,2,8};
     vector<int>result=slargest(arr);
    cout<<"The second largest element is : "<<result[0]<<endl;;
    cout<<"The second smallest element is  : "<<result[1];
  
    return 0;
}