#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t){
    // Case 1: when both of the strings have different lengths
    if(s.size()!=t.size()) return false;

    // Sort both strings
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    // Case 2: check if every character of str1 and str2 matches with each other
    for(int i=0;i<s.size(); i++){
        if(s[i]!=t[i]) return false;      // If any character doesn't match, they aren't anagrams
    }

    return true;
}
int main(){
    string s = "INTEGER";
    string t = "TEGERNI";

    // Check if the strings are anagrams and output the result
    if (isAnagram(s, t)) {
        cout << "True" << endl;  // Output "True" if they are anagrams
    } else {
        cout << "False" << endl;  // Output "False" if they aren't anagrams
    }

    return 0;
}

//Time Complexity: O(N log N), where N is the length of the strings. This is due to the sorting step performed on both strings.
//Space Complexity: O(1), as the sorting is done in-place and no extra space proportional to input size is used (excluding the input strings themselves).