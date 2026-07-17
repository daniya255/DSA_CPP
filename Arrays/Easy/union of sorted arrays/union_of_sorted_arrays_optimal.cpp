#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>union_array(int arr1[], int arr2[],int n,int m){
   int i=0,j=0;
    vector<int>union_arr;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(union_arr.empty() || union_arr.back()!=arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr2[i]<arr1[j]){
            if(union_arr.empty() || union_arr.back()!=arr2[i]){
                union_arr.push_back(arr2[i]);  
            }
             j++;
        }
        else{
            if(union_arr.empty() || union_arr.back()!=arr1[i]){
                union_arr.push_back(arr1[i]);
            }
             i++,j++;
        }
    }

    while(i<n){
         if(union_arr.empty() || union_arr.back()!=arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;
    }
    
    while(j<m){
         if(union_arr.empty() || union_arr.back()!=arr2[i]){
                union_arr.push_back(arr2[i]);   
            }
            j++;
    }

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