#include <iostream>
#include<vector>
using namespace std;
bool is_sorted(vector<int>&v){
    int n=v.size();
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}

int main() {
  vector<int>arr={1,2,3,4,5,6};
  cout<<is_sorted(arr);
    return 0;
}