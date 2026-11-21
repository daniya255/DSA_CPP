#include<bits/stdc++.h>
using namespace std;
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    if(quality.size() == 0 || wage.size() == 0 || quality.size() != wage.size()) return 0;

    vector<pair<double,int>> ratios;
    for(int i=0; i<quality.size(); i++){
        double ratio = static_cast<double>(wage[i] ) / quality[i] ;
        ratios.push_back({ratio,quality[i]});
    }

    sort(ratios.begin(),ratios.end());

    priority_queue<int> maxHeap;
    long qualitySum = 0;
    double minCost = numeric_limits<double>::infinity();


    for(const auto& [ratio,q] : ratios){
        maxHeap.push(q);
        qualitySum += q;
        if(maxHeap.size() > k){
            qualitySum -= maxHeap.top();
            maxHeap.pop();
        }

        if(maxHeap.size() == k){
            minCost = min(minCost, qualitySum * ratio);
        }
    }

    return minCost;
}
int main(){
    vector<int>quality = {10,20,5};
    vector<int>wage = {70,50,30};
    int k = 2;
    double minCost = mincostToHireWorkers(quality,wage,k);
    cout<<"Minimum cost to hire "<<k<<" workers is  : "<<minCost<<endl;
    return 0;
}