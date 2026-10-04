#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){

    if(s.empty() || s.size() == 1) return true;

    stack<char>st;

    for (int i=0; i<s.size(); i++){
        if(isalnum(s[i])){
            st.push(tolower(s[i]));
        }
    }

    int i=0;
    while(!st.empty()){
        while(i<s.length() && !isalnum(s[i])) i++;
        if (i<s.length() && tolower(s[i]) != st.top()) return false;
        st.pop();
        i++;
    }

    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome(s)) {
        cout << "It is a palindrome!" << endl;
    } else {
        cout << "It is NOT a palindrome." << endl;
    }
    return 0;
}