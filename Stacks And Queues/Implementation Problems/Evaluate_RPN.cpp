#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (const string& token: tokens ){
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')){
            int a = int(st.top()); st.pop();
            int b = int(st.top()); st.pop();

            int result = 0;
            switch (token[0]) {
                case '+': st.push(b + a); break;
                case '-': st.push(b - a); break;
                case '*': st.push(b * a); break;
                case '/': st.push(b / a); break;
                default : cout<<"Invalid operator";
                }

        }
        else st.push(stoi(token));
    }

    return st.top();
}
int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    int result = evalRPN(tokens);
    cout<<result<<endl;
    return 0;
}