class Solution {
public:
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
};