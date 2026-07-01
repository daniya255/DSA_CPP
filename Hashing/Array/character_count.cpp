#include<iostream>
#include<string>
using namespace std;
int main(){

    //FOR BOTH UPPER AND LOWER CASE 

    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<endl;

    //hashing 

    //1.pre-storing
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        //2.mapping
        hash[s[i]]++;
    }

    int q;
    cout<<"Enter the number of characters to find their frequency : ";
    cin>>q;

    //3.fetching
    while(q!=0){
        char ch;
        cout<<"Enter the character : ";
        cin>>ch;
        cout<<"The character occured : "<<hash[ch]<<" times."<<endl;
        q--;
    }


    return 0;

}