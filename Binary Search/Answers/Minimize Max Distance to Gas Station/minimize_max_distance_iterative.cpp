#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&stations, int k, double mid){
    int count=0;
    
    for(int i=0; i<stations.size()-1; i++){
        double diff=stations[i+1]-stations[i];
        int stationsNeeded=ceil((diff)/mid)- 1;
        count+=stationsNeeded;

    }

    return count<=k;
}

long double minimiseMaxDistance(vector<int>& stations, int k) {
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

int main(){
    vector<int>stations={1,2,3,4,5};
    int k=4;
    double dist=minimiseMaxDistance(stations,k);
    cout<<"The distance between the stations is : "<<dist<<endl;
    return 0;
}

//Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
//Space Complexity: O(1), as we are using no extra space to solve this problem.