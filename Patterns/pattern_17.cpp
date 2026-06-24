#include<iostream>
using namespace std;
void pattern17(int n){
    for(int i=0;i<n;i++){
        //spaces
       for(int j=0;j<n-i-1;j++){
        cout<<" ";
       }

       //characters
       char ch='A';
       for(int j=0; j<2*i+1;j++){
        cout<<ch;
        if(j<i) ch++;
        else ch--;
       }
       
        cout<<endl;
    }
}
int main(){
    int n=5;
    pattern17(n);
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