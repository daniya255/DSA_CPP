 
#include<iostream>
using namespace std;
  void helper(int i,int arr[], int n){
          if(i>=n/2) return;
          swap(arr[i],arr[n-i-1]);
          helper(i+1, arr, n);
      }
    void reverse_array(int arr[], int n){  
        helper(0,arr,n);
    }
int main(){
   int arr[]= {1,2,3,6,7};
    size_t s= sizeof(arr)/sizeof(arr[0]);

   cout<<"Before reversal."<<endl;
   for(int i=0;i<s;i++) cout<<arr[i];
   cout<<endl;
  
   reverse_array(arr,s);
   cout<<"After reversal."<<endl;
   for(int i=0;i<s;i++) cout<<arr[i];
   cout<<endl;
    return 0;
}
