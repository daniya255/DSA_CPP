#include <iostream>
#include <queue>
using namespace std;

int findTheWinner(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop(); // Eliminate the k-th friend
    }
    return q.front();
}

int main() {
    int n = 5, k = 2;
    cout << "Winner: " << findTheWinner(n, k) << endl;
    return 0;
}