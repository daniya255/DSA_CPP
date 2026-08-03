#include <bits/stdc++.h>
  using namespace std;
  
      bool rotateString(string s, string goal) {

        if(s.size()!= goal.size()) return false;
          
         string merge_str= s + s;   //concatenating s with s

         if (merge_str.find(goal) != string::npos) return true;     //finding if goal lies within the merged string
          
          // If no match is found, return false
          return false;
      }

  
  // Main function to test the method
  int main() {

      string s = "rotation";
      string goal = "tionrota";

      if (rotateString(s, goal)) {
          cout << "true." << endl;
      } else {
          cout << "false" << endl;
      }
      
      return 0;
  }

//Time Complexity: O(N), because checking for a substring in s + s is linear in time.
//Space Complexity: O(N) for the space needed to store the concatenated string s + s.