#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>intersection_array(int arr1[], int arr2[],int n,int m){
    int v[m]={0};
    vector<int>result;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && v[j]==0){
                v[j]=1;
                result.push_back(arr1[i]);
                break;
            }

            if(arr1[i]<arr2[j]) break;
        }
    }

    return result;

}

int main(){
    int arr1[]={2,4,5,7,9,12,15};
    int arr2[]={2,3,4,6,7,8,9,11,12,14,1,15};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    vector<int>result=intersection_array(arr1,arr2,n,m);
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}


//Time Complexity : O(n*m) 
//Space Complexity : O(m) for the array v[m] and O(k) for the result vector where k is the number of common elements.