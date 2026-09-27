class Solution {
public:
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
};