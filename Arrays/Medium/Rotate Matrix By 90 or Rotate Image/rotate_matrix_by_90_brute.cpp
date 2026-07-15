#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate_by_90(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>result(n,vector<int>(m,0));

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[j][n-1-i]=matrix[i][j];
        }
    }

   return result;
}
int main(){
    vector<vector<int>>matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=matrix.size();
    int m=matrix[0].size();

    cout<<"Original Array : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>>rotated=rotate_by_90(matrix);
    
    cout<<"Rotated Array : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<rotated[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(N^2), for nested loop, where N is the dimension of the matrix.
// Space Complexity: O(N^2), for the extra matrix used for copying elements.

