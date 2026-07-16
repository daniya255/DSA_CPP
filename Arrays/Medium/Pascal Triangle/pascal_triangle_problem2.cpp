//      Prints the entire rth row of the pascal triangle

#include<bits/stdc++.h>
using namespace std;
vector<int> nCr(int r){
    vector<int>row;
    int ans=1;
    row.push_back(ans);
    for(int i=1;i<r;i++){
        ans*=(r-i);
        ans/=i;
        row.push_back(ans);
    }
    return row;
}
int main(){
    int n=10;
    vector<int>row=nCr(n);
    for(int val:row) cout<<val<<" ";
    cout<<endl;
    return 0;
}

// Time Complexity: O(N), we iterate N times to compute each element of the row in O(1) time using the direct relation.
// Space Complexity: O(N), additional space used for storing the Nth row.

