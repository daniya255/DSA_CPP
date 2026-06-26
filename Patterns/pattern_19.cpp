#include<iostream>
using namespace std;
void pattern19(int n){
    //upper pattern
    for(int i=0;i<n;i++){
       //stars
       for(int j=0;j<n-i;j++){
        cout<<"*";
       }
       //spaces
       for(int j=0;j<2*i;j++){
        cout<<" ";
       }
       //stars
       for(int j=0;j<n-i;j++){
        cout<<"*";
       }
       cout<<endl;
    }

    //lower pattern
    for(int i=n-1;i>=0;i--){
       //stars
       //stars
       for(int j=0;j<n-i;j++){
        cout<<"*";
       }
       //spaces
       for(int j=0;j<2*i;j++){
        cout<<" ";
       }
       //stars
       for(int j=0;j<n-i;j++){
        cout<<"*";
       }
       cout<<endl;
    }

}
int main(){
    int n=5;
    pattern19(n);
    return 0;
}

