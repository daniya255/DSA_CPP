#include <bits/stdc++.h>
  using namespace std;
  

      // Method to check if two strings are isomorphic
      bool rotateString(string s, string goal) {

        if(s.size()!= goal.size()) return false;

          // Get the length of the string
          int n = s.size(); 
          
          // Traverse for each shift
          for (int i = 1; i <= n; ++i) {
              
            // add elements from i till end at start
            //then append first i elements at the end
            string rotated= s.substr(i) + s.substr(0,i);

            //check if the rotated strings matches the goal or not
            if(rotated == goal) return true;

          }
          
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

//Time Complexity: O(N^2) since generating N rotations and each comparison takes O(N) time.
//Space Complexity: O(N) for the space needed to store each rotated string
