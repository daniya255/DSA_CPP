 
#include<iostream>
using namespace std;
bool prime_num(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) count++;
    }
    if(count==2) return true;
    else return false;
}
int main(){
    int n=7;
    cout << prime_num(n);
    return 0;
}
