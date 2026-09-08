#include<bits/stdc++.h>
using namespace std;
string pre2post(string s){
    if(s.empty()) return "";

    stack<string>st;

    for(int i=s.size()-1;i>=0;i--){
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else{
           string op1=st.top(); 
           st.pop();
           string op2=st.top();
           st.pop();
           st.push(op1 + op2 + s[i]);
        }
    }

    return st.top();
    
}
int main(){
    string s = "-*AB/CD";
    string result=pre2post(s);
    cout<<"Prefix Expression : "<<s<<endl;
    cout<<"Postfix Expression : "<<result<<endl;
    return 0;
}

//Time Complexity: O(n), single pass through the expression.
//Space Complexity: O(n), stack space for storing intermediate results.