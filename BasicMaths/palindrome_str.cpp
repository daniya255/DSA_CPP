 
#include<iostream>
#include<string>
using namespace std;

    bool palindrome(string &s){
        string new_str="";
        for (char c : s) {
            if(isalnum(c)) new_str+=c;
        }
        for(int i=0;i<new_str.size();i++){
            if(tolower(new_str[i])!=tolower(new_str[new_str.size()-i-1])) return false;
         }
         return true;

    }
int main(){
    string str= "MADAME";
    cout<<palindrome(str);
     cout<<endl;
    return 0;
}
