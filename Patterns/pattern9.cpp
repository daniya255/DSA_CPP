#include <iostream>
using namespace std;
void print9(int n){
    //upper pyramid
    for(int i=1 ; i<=n ; i++){
        //spaces
        for(int j=1 ; j<=n-i ; j++){
            cout<<" ";
        }
        //stars
        for(int j=1 ; j<=2*i-1 ; j++){
            cout<<"*";
        }
    
        cout<<endl;
    }
    //lower pyramid
    for(int i=1 ; i<=n ; i++){
        //spaces
        for(int j=1 ; j<=i-1 ; j++){
            cout<<" ";
        }
        //stars
        for(int j=1 ; j<=2*n-(2*i-1) ; j++){
            cout<<"*";
        }
    
        cout<<endl;
    }
}
int main() {
    int n=5;
    print9(n);
    return 0;
}