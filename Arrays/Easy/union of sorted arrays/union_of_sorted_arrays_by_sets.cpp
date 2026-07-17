#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>union_array(int arr1[], int arr2[],int n,int m){
   
    set<int>sr;
    for(int i=0;i<n;i++){
        sr.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        sr.insert(arr2[i]);
    }
    vector<int>union_arr(sr.begin(),sr.end());

    return union_arr;
}
int main(){
    int arr1[]={2,4,5,7,9};
    int arr2[]={2,3,4,6,7,8,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    vector<int>result=union_array(arr1,arr2,n,m);
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}