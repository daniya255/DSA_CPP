#include <iostream>
#include<vector>
using namespace std;
void left_rotate(vector<int>&v){
    int n=v.size();
    int temp=v[0];
    for(int i=1;i<n;i++){
        v[i-1]=v[i];
    }
    v[n-1]=temp;
}
int main() {
  vector<int>arr={1,2,4,7,3,9};
  cout<<"Before left rotation by one : "<<endl;
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  cout<<"After left rotation : "<<endl;
  left_rotate(arr);
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  
    return 0;
}