//      Prints the cth column and rth row element of the pascal triangle

#include<bits/stdc++.h>
using namespace std;
long nCr(int r,int c){
    int k=c-1;  //column 
    int n=r-1;  //row
    long res=1;
    for(int i=0;i<k;i++){   //runs tell column - 1 
        res*=(n-i); //handles upper part of fraction
        res/=(i+1); //handle lower part of fraction
    }
    return res;
}
int main(){
    int n=10;
    int r=3;
    cout<<nCr(n,r);
    return 0;
}


// Time Complexity: O(min(c,r−c)), The loop runs for min(c−1,r−c) iterations because binomial coefficients are symmetric.
// Space Complexity: O(1), constant additional space is used.
