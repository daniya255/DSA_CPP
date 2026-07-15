#include<bits/stdc++.h>
using namespace std;
void rotate_by_90(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    //transposing the matrix first
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reversing the rows after transpose
    for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end()); //take linear time complexity to reverse the entire row
        }
    
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
    rotate_by_90(matrix);
    cout<<"Rotated Array : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(N²),We traverse every element once during transposition and again during reversal of each row, resulting in a total of O(N²) time.
//O(N^2)(Transpose) + O(N^2)(Reverse) = O(N^2)
// Space Complexity: O(1),All operations are done in-place using only temporary variables. No extra matrix is used.

