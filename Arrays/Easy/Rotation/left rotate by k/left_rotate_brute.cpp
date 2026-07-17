#include <iostream>
#include<vector>
using namespace std;
void left_rotate(vector<int>&v,int k){
    int n=v.size();
    k=k%n;
    int temp[k];
    
    //store the k elements in temp
    for(int i=0;i<k;i++){
        temp[i]=v[i];
    }
    
    //rotate the n-k elements
    for(int i=k;i<n;i++){
        v[i-k]=v[i];
    }
    
    //insert the k elements back to the array
    for(int i=n-k;i<n;i++){
        v[i]=temp[i-(n-k)];
    }
}
int main() {
  vector<int>arr={1,2,4,7,3,9};
  cout<<"Before left rotation by one : "<<endl;
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  cout<<"After left rotation : "<<endl;
  left_rotate(arr,3);
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  
    return 0;
}