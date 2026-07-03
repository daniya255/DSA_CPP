#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>&v,int n){

    if(n==1) return;        //base case
    
    //sort the last element in each iteration
    for(int i=0;i<=n-2;i++){
        if(v[i]>v[i+1]){
            swap(v[i],v[i+1]);
        }
    }

    //recursion call excluding the last sorted element
    bubble_sort(v,n-1);
}
int main(){

    vector<int>arr={23,34,5,16,65,78};

    cout<<"Unsorted Array."<<endl;
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;

    bubble_sort(arr,arr.size());

    cout<<"Sorted Array."<<endl;
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    

    return 0;
}