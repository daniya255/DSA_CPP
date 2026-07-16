//      Prints the entire pascal triangle till rth row

#include<bits/stdc++.h>
using namespace std;
//function for generating rth row
vector<int> generate_row(int r){
    vector<int>row;
    int ans=1;
    row.push_back(ans);
    for(int i=1;i<r;i++){
        ans*=(r-i);
        ans/=i;
        row.push_back(ans);
    }
    return row;
}

//function for appending the row into the pascal triangle
vector<vector<int>>pascal_triangle(int r){
    vector<vector<int>>triangle;
    //runs from 1--->rth row
    for(int i=1;i<=r;i++){
        triangle.push_back(generate_row(i));
    }
    return triangle;
}
int main(){
    int n=10;
    vector<vector<int>>triangle=pascal_triangle(n);

    //runs from first till last row
    for(int i=0;i<triangle.size();i++){
        //formats the pascal triangle
        cout << string(n - i - 1, ' ');
        //runs from first till last column of the ith row
        for(int j=0;j<triangle[i].size();j++){
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

//Time Compelxity : O(N*N) as the outer loop runs from 1-->n and the helper function has time complexity O(N)
//Space Complexity: O(N*N) for the vector of vectors for the triangle structure

