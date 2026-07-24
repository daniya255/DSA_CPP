#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&piles,int hour,int rate){
    long long  total_hours=0;
    for(int i=0;i<piles.size();i++){
        total_hours+=(piles[i] + rate - 1)/ rate;    
    }

    return hour>=total_hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low=1;
    int high=*max_element(piles.begin(),piles.end());
    int possible_ans=high;

    while(low<=high){

    int mid=(low+high)/2;
    int ans=isPossible(piles,h,mid);
    
        if(ans){
            possible_ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    

    return possible_ans;
        

}


int main(){
    vector<int>piles={3,6,7,11};
    int h=8;
    int ans=minEatingSpeed(piles,h);
    cout<<"The minimum eating speed is : "<<ans<<" bananas per hours"<<endl;
    return 0;
}


// Time Complexity: O(N*log(max(a[]))), we apply binary search on our search space to reduce it into half at every step.
// Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
