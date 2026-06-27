 
#include<iostream>
using namespace std;
  void printNumbers(int n) {
       if(n==0) return;
       cout<<n<<'\n';
       printNumbers(n-1);
    }
int main(){
   int n=6;
  printNumbers(n);
    return 0;
}
