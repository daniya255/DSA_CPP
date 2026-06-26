#include<iostream>
using namespace std;
bool palindrome(int n){
    int orig=n;
    int ld,rev=0;
    while(n>0){
        ld=n%10;
        rev=(rev*10)+ld;
        n=n/10;
    }
    if(rev==orig) return true;
    else return false;
}

int main(){
    int n= 1210;
    
    cout<<palindrome(n);
    return 0;
}