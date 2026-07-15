#include<bits/stdc++.h>
using namespace std;
void set_zeroes(vector<vector<int>>&matrix){
    //row size
    int n=matrix.size();
    //column size
    int m=matrix[0].size();

    int col0=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                 matrix[i][0]=0;
                 if(j!=0) matrix[0][j]=0;
                 else col0=0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }

        }
    }
    }

    if(matrix[0][0]==0){
        for(int j=0;j<m;j++) matrix[0][j]=0;
    }
    if(col0==0) {
        for(int i=0;i<n;i++) matrix[i][0]=0;
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

// Time Complexity: O(m × n),We iterate over the entire matrix a constant number of times (first pass for markers, second pass for zeroing, final pass for first row/col), where m = number of rows and n = number of columns.

// Space Complexity: O(1),No extra space is used apart from a few boolean flags; all marker information is stored within the first row and column of the matrix itself.