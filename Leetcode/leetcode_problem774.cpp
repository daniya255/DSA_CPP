class Solution {
public:
    bool isPossible(vector<int>&stations, int k, double mid){
    int count=0;
    
    for(int i=0; i<stations.size()-1; i++){
        double diff=stations[i+1]-stations[i];
        int stationsNeeded=ceil((diff)/mid)- 1;
        count+=stationsNeeded;

    }

    return count<=k;
}

    long double minimiseMaxDistance(vector<int> &stations, int k) {
    int n=stations.size();
    double low=0;
    double high=0;
    
    for(int i=0; i<n-1; i++){
        high=max(high,double(stations[i+1]-stations[i]));
    }

    while(high - low > 1e-6){

        double mid= (low+high)/2.0;
        bool check=isPossible(stations,k,mid);
        if(check){
            high=mid;
        }
        else low=mid;

    }

    return high;
    }
};