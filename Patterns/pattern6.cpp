#include <iostream>
using namespace std;
void print5(int n){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n-i+1 ; j++){
            cout<<j;
        }
        cout<<endl;
    }
}
int main() {
    int n=5;
    print5(n);
    return 0;
}