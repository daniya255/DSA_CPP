#include<bits/stdc++.h>
using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&a,const vector<int>&b){
        return a[1] > b[1];
    });

    int total = 0;

    for (auto& box: boxTypes){
        int numOfbox= box[0];
        int unitOfbox = box[1];
        if (truckSize >= numOfbox){
            total += numOfbox *unitOfbox;
            truckSize -= numOfbox;
        }
        else{
            total += truckSize*unitOfbox;
            break;
        }
    }

    return total;
        
}

int main(){
    vector<vector<int>> boxTypes = {{1,3}, {2,2},{3,1}};
    int truckSize = 4;
    double total = maximumUnits(boxTypes,truckSize);
    cout<<total<<endl;
    return 0;
}

//Time Complexity :- O(NlogN) ; O(N) for greedy traversal, O(NlogN) for sorting
//Space Complexity :- O(1) in place sorting is done