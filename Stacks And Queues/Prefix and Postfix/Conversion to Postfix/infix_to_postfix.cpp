#include<bits/stdc++.h>
using namespace std;
int precedence(char op) {
    if (op == '^') return 3;          // Highest precedence
    if (op == '*' || op == '/') return 2; // Medium precedence
    if (op == '+' || op == '-') return 1; // Lowest precedence
    return -1;                        // For parentheses or invalid chars
}
string in2post(string s){

    if (s.empty()) return s;

    string output="";
    stack<char>op;

    for(int i=0;i<s.size();i++){

        //if char is an alphabet or number
        if(isalnum(s[i])){
            output+=s[i];   //add to output
        }

        else if (s[i]=='('){
            op.push(s[i]); //push to stack
        }

        //if char is closing bracket
        else if (s[i] == ')') {
            while (op.top() != '(') {
                output += op.top();    //remove elements from stack till empty
                op.pop();
            }
            op.pop();  // Pop the ‘(‘ from the stack
        }

        // If an operator is scanned
        else{
            while(!op.empty() && precedence(op.top())>= precedence(s[i])){
                output+=op.top();  //append higher precedence operators to output
                op.pop();
            }
            op.push(s[i]); //push the element to stack
        }

    }

    //pop the remaining elements and append to the outptu
    while(!op.empty()){
        output+=op.top();
        op.pop();
    }

    return output;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    string result=in2post(s);
    cout<<"Infix Expression : "<<s<<endl;
    cout<<"Postfix Expression : "<<result<<endl;
    return 0;
}

//Time Complexity: O(N), where N is the length of the infix expression. Each character in the expression is processed once.
//Space Complexity: O(N), where N is the length of the infix expression. The stack can hold at most N operators and parentheses in the worst case.