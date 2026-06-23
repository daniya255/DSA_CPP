#include <iostream>
using namespace std;
void print7(int n){
    for(int i=1 ; i<=n ; i++){
        //spaces
        for(int j=1 ; j<=n-i ; j++){
            cout<<" ";
        }
        //stars
    for(int j=1 ; j<=2*i -1  ; j++){
            cout<<"*";
        }
    
        cout<<endl;
    }
}
int main() {
    int n=5;
    print7(n);
    return 0;
}