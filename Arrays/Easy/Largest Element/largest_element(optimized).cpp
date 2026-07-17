#include<iostream>
#include<vector>
using namespace std;

//Time Complexity : O(n)
int largest_element(vector<int>&v){
    int n=v.size();
    int largest=v[0];
    for(int i=0;i<n;i++){
        if(v[i]>largest) largest=v[i];
    }
    return largest;
}
int main(){
    vector<int>arr={1,2,3,4,6,4,2};
    cout<<"The element is : "<<largest_element(arr);
    return 0;

}