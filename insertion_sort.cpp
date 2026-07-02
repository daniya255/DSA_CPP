#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>&ss){

    int n=ss.size();    //size of the vector

    //from first to  last index
    for(int i=0; i<=n-1; i++){ 

        int j=i;

        //This loop compares the jth element to the elements on its left
        while(j>0 && ss[j-1]>ss[j]){    //will not run if already sorted
            swap(ss[j],ss[j-1]);
            j--;
        }
    }
       
}

//helper function for printing the vector
void print(vector<int>&ss){
    for(auto &val: ss) cout<<val<<" ";
    cout<<endl;
}
int main(){
    
    vector<int>v={23,65,12,87,33,76};

    cout<<"Original Vector : "<<endl;
    print(v);

    cout<<"Sorted Vector : "<<endl;
    insertion_sort(v);
    print(v);

    return 0;
}