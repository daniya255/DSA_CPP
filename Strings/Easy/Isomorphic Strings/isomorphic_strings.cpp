#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    
    unordered_map<char, char> mapS;
    unordered_map<char, char> mapT;
    
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];
        
        // Check if c1 is already mapped to a different character
        if (mapS.count(c1) && mapS[c1] != c2) return false;
        
        // Check if c2 is already mapped to a different character
        if (mapT.count(c2) && mapT[c2] != c1) return false;
        
        // Establish the mapping
        mapS[c1] = c2;
        mapT[c2] = c1;
    }
    
    return true;
}

int main(){
    string s="paper";
    string t= "title";

    if(isIsomorphic(s,t)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

//Time Complexity: O(N) We are transversing both strings in a single loop
//Space Complexity : 0(1) although we are using hashmaps but the maximum length of the hashmap can be 256 including all ascii characters in the worst case scenerio