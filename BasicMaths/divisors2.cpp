 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> divisors(int n) {
        vector<int>div;
        for (int i=1;i*i<=n;i++){
            if(n%i==0) {
                div.push_back(i);
            if ((n/i)!=i) div.push_back(n/i);
            }
            
        }
        sort(div.begin(),div.end());
        return div;
    }

int main(){
   vector<int>div= divisors(36);
   for(int i : div) cout<<i<<" ";
    return 0;
}
