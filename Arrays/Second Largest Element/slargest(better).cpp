#include<iostream>
#include<vector>
using namespace std;
int slargest(vector<int>&v){
    int n=v.size();
    int largest=v[0], slargest=-1;
    for(int i=0;i<n;i++){
        if(largest<v[i]) largest=v[i];
    }

    for(int i=0;i<n;i++){
        if(v[i]>slargest && v[i]!=largest) {
            slargest=v[i];
        }
    }

    return slargest;
}
int main(){
    vector<int>arr={2,1,5,3,6,2,8};
    cout<<"The second largest element is : "<<slargest(arr);
    return 0;
}