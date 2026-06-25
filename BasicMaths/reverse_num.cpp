#include<iostream>
using namespace std;
int rev_num(int n){
    int ld,rev=0;
    while(n!=0){
        ld=n%10;
        rev=(rev*10) + ld;
        n=n/10;
    }
    return rev;
    
}

int main(){
    int n= -7743;
    cout<<"The real number is "<<n<<endl;
    cout<<"The reversed number is : "<<rev_num(n);
    return 0;
}