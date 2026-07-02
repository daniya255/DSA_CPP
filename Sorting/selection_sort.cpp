#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int>&ss){

    int n=ss.size();    //size of the vector

    //from first to 2 last index
    for(int i=0; i<=n-2; i++){
        int min=i;  
        //This loop compares the min element to the rest of the vector
        for(int j=i+1;j<=n-1; j++){
            if(ss[min]>ss[j]) min=j;
        }
        //swap the min with the current index
        swap(ss[min],ss[i]);
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
    selection_sort(v);
    print(v);

    return 0;
}