#include<bits/stdc++.h>
using namespace std;
struct Item{
    long long val;
    long long wt;
};

bool compare(Item a,Item b){
    double r1 = (double)a.val / (double)a.wt;
    double r2 = (double)b.val / (double)b.wt;
    return r1 > r2;
}
double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
    int n = val.size();
    vector<Item> items(n);

    for(int i=0; i<n; i++){
        items[i] = {val[i],wt[i]};
    }

    sort(items.begin(), items.end(), compare);
    long long weight = 0;
    double result = 0.0;

    for(int i=0; i<n; i++){
        if (items[i].wt + weight <= capacity){
            weight+=items[i].wt;
            result+=items[i].val;
        }
        else{
            long long remaining_capacity = capacity - weight;
            double frac = (double)remaining_capacity/(double)items[i].wt;
            result += (items[i].val*frac);
            break;

        }
    }

    return result;
}


int main(){
    vector<long long>val = {60,100};
    vector<long long>wt = {10,20};
    long long capacity = 50;
    double sack = fractionalKnapsack(val,wt,capacity);
    cout<<sack<<endl;
    return 0;
}

//Time Complexity :- O(NlogN) ; O(N) for greedy traversal, O(N) for item populating, O(NlogN) for sorting
//Space Complexity :- O(N) ; a vector for holding values and weights