#include <bits/stdc++.h>
using namespace std;
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void heapifyDown(vector<int> &heap, int index, int lastInd)
{
    while (leftChild(index) <= lastInd)
    { // while there is a left child
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if (heap[left] > heap[largest])
            largest = left;
        if (right <= lastInd && heap[right] > heap[largest])
            largest = right;
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
        {
            break; // heap property satisfied
        }
    }
}

void heapSort(vector<int>& heap){
    if(heap.size() <= 1) return ;

    int n = heap.size();

    for(int i=((n/2)-1); i>=0; i--){
        heapifyDown(heap,i,n-1);
    }

    int lastInd = n-1;
    while(lastInd > 0){
        swap(heap[0],heap[lastInd--]);
        heapifyDown(heap,0,lastInd);
    }

}
int main()
{
    vector<int>heap = {4,10,5,3,1};
    heapSort(heap);
    for(int num : heap) cout<<num<<" ";
    return 0;
}