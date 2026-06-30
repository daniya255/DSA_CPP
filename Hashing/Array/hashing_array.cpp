#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" element : ";
        cin>>arr[i]; 
    }

    //brute force method

    // int number,count=0;
    // cout<<"Enter the number to find its frequency : ";
    // cin>>number;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==number) count++;
    // }
    // cout<<"The number occured : "<<count<<" times."<<endl;


    //hashing 
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    int q;
    cout<<"Enter the number of integers to find their frequency : ";
    cin>>q;

    while(q!=0){
        int number;
        cout<<"Enter the number : ";
        cin>>number;
        cout<<"The number occured : "<<hash[number]<<" times."<<endl;
        q--;
    }


    return 0;

}