#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {

    if (s.empty()) return 0;

    int start=0;
    int sign=1;
    int result=0;

    while (start< s.size() && s[start]== ' '){
        start++;
    }

    if (start >= s.size()) return 0;

    if (s[start] == '-'){
        sign=-1;
        start++;
    }
    else if(s[start]== '+'){
        sign=1;
        start++;
    }

    for(int i=start; i<s.size(); i++){

        if( !isdigit(int(s[i])) ) break;

        else{
            if(result > (INT_MAX - (s[i] - '0') ) / 10 ){
                return (sign==1) ? INT_MAX : INT_MIN;
            }
            result = result*10 + (s[i] - '0');
        }
         
    }

    return sign*result;

}
int main(){
    string s = "1337c0d3";
    cout << myAtoi(s) << endl;  // Output: -12345

    return 0;
}

//Time complexity : O(N) as the loop traverse through the whole string in the worst case scenerio.
//Space Complexity : O(1)