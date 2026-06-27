 
#include<iostream>
#include<algorithm>
using namespace std;
void recursive_num(int count,int num){
    if(count>num) return;
    cout<<count<<endl;
    recursive_num(count+1,num);

}
int main(){
   int n=6;
   recursive_num(1,n);
    return 0;
}
