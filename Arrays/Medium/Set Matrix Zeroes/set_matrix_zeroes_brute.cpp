#include<bits/stdc++.h>
using namespace std;
void set_zeroes(vector<vector<int>>&matrix){
    //row size
    int n=matrix.size();
    //column size
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //check for zeroes at the [i][j]th index
            if(matrix[i][j]==0){
                //set the column to -1
                for(int col=0;col<m;col++){
                    if(matrix[i][col]!=0) matrix[i][col]=-1;
                }
                //set the entire row to -1
                for(int row=0;row<n;row++){
                    if(matrix[row][j]!=0) matrix[row][j]=-1;
                }
            }
        }
    }

    //loop for converting -1's to 0's
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1) matrix[i][j]=0;
        }
    }

}
int main(){
    vector<vector<int>>matrix={{1,1,1},{0,1,1}, {1,0,1}};
    set_zeroes(matrix);
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(m * n * (m + n)), We iterate through every cell (m * n), and for each zero, we potentially mark its entire row (O(n)) and column (O(m)), leading to O(m * n * (m + n)) overall.

// Space Complexity: O(1), We are not using any extra data structures, only modifying the matrix in place (apart from a few variables).
