#include<iostream>
using namespace std;
void pattern20(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars,spaces;
        if(i>n) {
            spaces=2*i - 2*n;
            stars=2*n -i;
        }
        else{
            spaces=2*n - 2*i;
            stars=i;
        }
        //stars
        for(int j=1; j<=stars; j++) cout<<"*";

        //spaces
        for(int j=1;j<=spaces;j++) cout<<" ";

        //stars
        for(int j=1;j<=stars;j++) cout<<"*";

        cout<<endl;
    }
    
    }

    


int main(){
    int n=5;
    pattern20(n);
    return 0;
}

