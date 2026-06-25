#include<iostream>
using namespace std;
void count_digit(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    cout<<"The number contains "<<count<<" digits";
}

int main(){
    int n=7743;
    count_digit(n);
    return 0;
}