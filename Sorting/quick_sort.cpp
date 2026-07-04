#include<iostream>
#include<vector>
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

//recursively calls the sort function for sub arrays
void quick_sort(vector<int>&v,int low,int high){
    if(low<high){
        int pInd=pivotFunc(v,low,high);
        quick_sort(v,low,pInd-1);
        quick_sort(v,pInd+1,high);
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