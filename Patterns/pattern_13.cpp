#include<iostream>
using namespace std;
void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
       for(int j=1 ; j<=i ;j++){    
        cout<<num<<" ";
        num+=1;
       }
       
        cout<<endl;
    }
}
int main(){
    int n=5;
    pattern13(n);
    return 0;
}