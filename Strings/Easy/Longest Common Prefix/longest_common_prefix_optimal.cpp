#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs){

    if(strs.empty()) return "";

    sort(strs.begin(),strs.end());

    string first=strs[0];
    string last=strs[strs.size()-1];
    string result="";

    int min_len=min(first.size(), last.size());

    for(int i=0; i<min_len; i++){
        if(first[i]!=last[i]) break;

        else result+=first[i];
    }

    return result;
}
int main(){
    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result =longestCommonPrefix(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl;
    
    return 0;

}

//Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.
//Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M), if output storage is excluded the auxiliary space complexity is O(1)

