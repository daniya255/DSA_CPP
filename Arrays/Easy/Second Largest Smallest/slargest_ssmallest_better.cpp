#include<iostream>
#include<vector>
using namespace std;
vector<int> slargest_ssmallest(vector<int>&v){
    int n=v.size();
    int largest=INT_MIN, slargest=INT_MIN;
    int smallest=INT_MAX, ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(largest<v[i]) largest=v[i];
        if(smallest>v[i]) smallest=v[i];
    }

    for(int i=0;i<n;i++){
        
        if(v[i]>slargest && v[i]!=largest) slargest=v[i];

        if(v[i]<ssmallest && v[i]!=smallest) ssmallest=v[i];
    }
    
    vector<int>result={slargest,ssmallest};
    return result;
}
int main(){
    vector<int>arr={2,1,5,3,6,2,8};
     vector<int>result=slargest_ssmallest(arr);
    cout<<"The second largest element is : "<<result[0]<<endl;;
    cout<<"The second smallest element is  : "<<result[1];
  
    return 0;
}