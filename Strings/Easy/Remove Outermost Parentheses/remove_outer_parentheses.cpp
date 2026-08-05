#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {

    if(s.size()==1) return "";  // if string contains only ()
    if(s.empty()) return "";    //if string is empty

    if (s.size() % 2 == 1) return "";   // (Optional check, though valid LeetCode strings are always even)

    int balance=0;  //keep track of depths
    string result="";

    for(int i=0; i<s.size(); i++){

        if (s[i]=='(') {    // This handles s[i] == '()'
            // If balance > 0, it's NOT an outermost opening bracket, so keep it
            if (balance>0) result+=s[i];
            balance++;
        }
        if (s[i] == ')'){   // This handles s[i] == ')'
            // Decrement first, then check if it's NOT an outermost closing bracket
            balance--;
            if (balance>0) result+=s[i];           
        }

    }

    return result;
}
int main(){

    string s="((()))()";
    string result=removeOuterParentheses(s);
    cout<<"The resulting string is : "<<result<<endl;

    return 0;
}

//Time Complexity: O(n), since we are performing a single traversal of the string.
//Space Complexity: O(1), since we are using a few variables to track the current state, excluding the storage space for output.