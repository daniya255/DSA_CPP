#include <iostream>
#include<algorithm>
using namespace std;
void left_rotate(int arr[],int k,int n){
    k=k%n;
    
    reverse(arr,arr+k);//rotate 0----(k-1) elements
    reverse(arr+k,arr+n);//rotate k-----(n-1) elements
    reverse(arr,arr+n);//rotate the whole array
}
int main() {
  int arr[]={1,4,2,7,4};
   int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"Before left rotation by one : "<<endl;
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  cout<<"After left rotation : "<<endl;
  left_rotate(arr,3,n);
  for(int val:arr){
      cout<<val<<" ";
  }
  cout<<endl;
  
    return 0;
}