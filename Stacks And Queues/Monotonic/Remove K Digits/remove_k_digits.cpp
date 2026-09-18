#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    string result="";
    stack<char>st;

    for(int i=0;i<num.size();i++){
        char curr = num[i];

        /* Pop last digits (when possible)
         if a smaller digit is found*/
        while(k>0 && !st.empty() && st.top() > curr){
            st.pop();
            k--;
        }
        st.push(curr);
    }

    // If more digits can be removed
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Handling edge case
    if(st.empty()) return "0";

    // Adding digits in stack to result
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    // Trimming the zeroes at the back
    while(result.size() > 0 && result.back() == '0'){
        result.pop_back();
    }

    // Reverse to get the actual number
    reverse(result.begin(),result.end());

    // Edge case
    if (result.empty()) return "0";

    return result;
}

int main(){
    string num = "1432219";
    cout<<"The resulting string is : "<<removeKdigits(num,3)<<endl;
    return 0;
}

//Time Complexity: O(N), since traversing the given string takes O(N) time, each element is pushed onto and popped from the stack at most once in worst-case taking o(N) time, removing the remaining digits (if k > 0) takes O(k) time which can go upto O(N) in worst-case and forming the result, trimming the zeros and reversing the digits takes O(N) time.
//Space Complexity: O(N), since we are using a stack to store the digits of the resulting number, in the worst case, the stack can contain all the digits of the input string.