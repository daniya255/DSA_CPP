#include<iostream>
#include<vector>
using namespace std;
vector<int> slargest_ssmallest(vector<int>&v){
    int n=v.size();
    int largest=INT_MIN, slargest=INT_MIN;
    int smallest=INT_MAX, ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
       if(v[i]>largest){
        slargest=largest;
        largest=v[i];
       }
       else if (v[i]!=largest && v[i]>slargest) slargest=v[i];

       if(v[i]<smallest) {
        ssmallest=smallest;
        smallest=v[i];
       }

       else if(v[i]!=smallest && v[i]<ssmallest) ssmallest=v[i];

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