#include<iostream>
#include<vector>
using namespace std;

//optimized case of bubble sort algorithm
void bubble_sort(vector<int>&v,int n){

    if(n==1) return;        //base case
    
    bool swapped=false;     //flag for checking swapping of elements

    //sort the last element in each iteration
    for(int i=0;i<=n-2;i++){
        if(v[i]>v[i+1]){
            swap(v[i],v[i+1]);
            swapped=true;       //indicating a sort between adjacent elements
        }
    }

    if(!swapped) return;        //indicating the array is sorted

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