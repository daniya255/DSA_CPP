#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t){
    // Case: when both of the strings have different lengths
    if(s.size()!=t.size()) return false;

    int freq[26]={0};   // Initialize a frequency array to store character counts

    // Count frequency of each character in string s
    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }

    // Decrement frequency for each character in string t
    for(int i=0; i<s.size(); i++){
        if (freq[t[i]-'a'] > 0)  freq[t[i]-'a']--;   // Decrement frequency for each character
        else return false;
    }

    return true;

}
int main(){
    string s = "cat";
    string t = "aet";

    // Check if the strings are anagrams and output the result
    if (isAnagram(s, t)) {
        cout << "True" << endl;  // Output "True" if they are anagrams
    } else {
        cout << "False" << endl;  // Output "False" if they aren't anagrams
    }
    return 0;

}

//Time Complexity: O(N) :- We iterate through string s once to populate the frequency array O(N).We iterate through string t once to check and decrement the frequencies O(N).Since O(N + N) simplifies to O(N), the time complexity is linear with respect to the length of the strings.
//Space Complexity: O(1) :- We use an integer array freq of a fixed size (26). Because the auxiliary space is constant and independent of the input size N, the space complexity is O(1) (Constant Space)