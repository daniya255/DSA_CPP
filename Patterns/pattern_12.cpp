#include<iostream>
using namespace std;
void pattern12(int n){
    for(int i=1;i<=n;i++){
       //numbers
       for(int j=1 ; j<=i ;j++){    //123
        cout<<j;
       }
       //spaces
       for(int j=1; j<=2*n - 2*i; j++){
        cout<<" ";
       }
       //numbers
       for(int j=i ;j>=1 ;j--){ //321
        cout<<j;
       }
        cout<<endl;
    }
}
int main(){
    int n=5;
    pattern12(n);
    return 0;
}