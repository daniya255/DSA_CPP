class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!= goal.size()) return false;
          
         string merge_str= s + s;   //concatenating s with s

         if (merge_str.find(goal) != string::npos) return true;     //finding if goal lies within the merged string
          
          // If no match is found, return false
          return false;
    }
};