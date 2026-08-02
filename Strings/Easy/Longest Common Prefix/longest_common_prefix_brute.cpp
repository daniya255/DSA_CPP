#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs){

    //if vector is empty
    if(strs.empty()) return "";

    int min_len = strs[0].size();   //initializing the min_len variable 
    for (int i = 1; i < strs.size(); i++) {
        min_len = min(min_len, (int)strs[i].size());    //finding the shortest string
    }

    string result="";
    //taking the first string for comparison with the other larger strings
    string str= strs[0];

    for(int i=0; i<min_len; i++){
        char match=str[i];
        for(int j=1; j<strs.size()-1; j++){
            string c_str= strs[j];
            if(c_str[i]!= match)  return result;     //if characters don't match return the result string made so far
        }
        result+=match;

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

//Time Complexity:O(N *M)Where: N is the number of strings in the array (strs.size()). M is the length of the shortest string.
//Space Complexity: O(1) :- We only use a few variables (min_len, loop indices i and j, and a match character) which take constant extra space.
//The result string grows up to the length of the common prefix, but auxiliary space complexity traditionally excludes the output storage. Thus, the auxiliary space complexity is O(1) (Constant Space).