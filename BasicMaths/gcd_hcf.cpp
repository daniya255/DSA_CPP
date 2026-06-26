 
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int n1,int n2){
    for(int i=min(n1,n2); i>=1; i--){
        if(n1%i==0 && n2%i==0) 
        return i;
        
    }
    return 0;
    
}
int main(){
   cout<<gcd(12,9);
    return 0;
}
