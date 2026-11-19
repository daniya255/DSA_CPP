#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int totalCount = maxHeap.size() + minHeap.size();

        if(totalCount %2 != 0)  {
            return maxHeap.top();
        }
        else return (maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */