#include<iostream>
using namespace std;
void pattern18(int n){
    for(int i=1;i<=n;i++){
        char ch='A'+(n-i);
       for(int j=1;j<=i;j++){
        cout<<ch<<" ";
        ch++;
       }
        cout<<endl;
    }
}
int main(){
    int n=5;
    pattern18(n);
    return 0;
}


// [4,1,4]
// [3,3,3]
// [2,5,2]
// [1,7,1]
// [0,9,0]

// spaces= n-i-1    i=0,j=0 j<
// chars=2i+1
// if(j<=i+1) char++
// else char--