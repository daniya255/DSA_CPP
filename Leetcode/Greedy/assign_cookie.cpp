#include<bits/stdc++.h>
using namespace std;
int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){

    int s = Student.size();
    int c = Cookie.size();

    sort (Cookie.begin(), Cookie.end());
    sort (Student.begin(), Student.end());

   int i=0;
   int j=0;

   while(i<s && j<c){
    if (Student[i] <= Cookie[j]){
        i++;
    }
    j++;
   }

   return i;
        
}
int main(){
    vector<int> students = {1,2,3};
    vector<int> cookie = {1,2};
    int result = findMaximumCookieStudents(students, cookie);
    cout<<"The max number of students with cookies are : "<<result<<endl;
    return 0;
}

//Time Complexity: O(N *log N + M *log M) : O(N*logN) , O(M*logM) for sorting and linear O(N+M) for pointer traversal
//Space Complexity : O(1) no extra space required