#include <iostream>
#include<vector>
using namespace std;
int duplicates(vector<int>&arr){
   int n=arr.size();
   int i=0;
   for(int j=1;j<n;j++){
       if(arr[j]!=arr[i]){
           arr[i+1]=arr[j];
           i++;
       }
   }
   
   return i+1;
}


int main() {
  vector<int>arr={1,1,2,1,3,2,1,3,2};
  cout<<duplicates(arr);
    return 0;
}