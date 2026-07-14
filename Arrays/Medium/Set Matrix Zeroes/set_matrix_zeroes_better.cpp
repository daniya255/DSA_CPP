#include<bits/stdc++.h>
using namespace std;
void set_zeroes(vector<vector<int>>&matrix){
    //row size
    int n=matrix.size();
    //column size
    int m=matrix[0].size();

    vector<int>col(m,0);
    vector<int>row(n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
           
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
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

// Time Complexity: O(m × n),We make two passes over the matrix.First pass to identify rows and columns to be zeroed (O(m × n)).Second pass to update the matrix using the markers (O(m × n)).Total time is proportional to the number of cells in the matrix, so O(m × n).
// Space Complexity: O(m + n),We store two extra arrays one for m rows and one for n columns. No other extra space is used besides these arrays.