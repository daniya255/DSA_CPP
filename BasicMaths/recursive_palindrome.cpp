#include<iostream>
#include<string>
using namespace std;

bool helper(int i,string &s,int n){
        int left=i;
        int right=n-i-1;
        if(i>=n/2) return true;
        if(s[left]!=s[right]) return false;
        return helper(i+1,s,n);
    }

bool palindromeCheck(string& s){
			return helper(0,s,s.size());
		}
    

int main(){
    string s="MADAMe";
    cout<<palindromeCheck(s);
}