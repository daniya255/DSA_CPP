#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height){
    
    int n=height.size();
    int volume=0;

    for(int i=1;i<n-1;i++){
        int leftmax=0;
        int rightmax=0;
        int curr=height[i];

            //finds left maximum height
            for(int j=0;j<i;j++){
                leftmax=max(leftmax,height[j]);
            }
        
            //finds right max height
            for(int k=i+1;k<n;k++){
                rightmax=max(rightmax,height[k]);
            }

        int boundary= min(leftmax,rightmax);    //negative case check
        if(boundary > curr) volume+= (boundary - curr);
        
    }

    return volume;
}

int main(){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = trap(height);

    cout << "Trapped Rainwater: " << result << endl;

    return 0;
}


//Time Complexity: O(n²) because for each bar, we scan all bars to its left and right to find the maximum height, resulting in nested loops.
//Space Complexity: O(1) as no additional data structures are used proportional to input size, only variables to track max heights and total water.