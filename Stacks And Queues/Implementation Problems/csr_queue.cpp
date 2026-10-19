#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Call {
    int callId;
    string customerName;
};

class CallCenter {
private:
    queue<Call> callQueue;
    int totalCSRs;
    int availableCSRs;
public:
    CallCenter(int csrs) {
        totalCSRs = csrs;
        availableCSRs = csrs;
    }

    void addCall(int id, string name) {
        callQueue.push({id, name});
        cout << "Call #" << id << " from " << name << " added to queue." << endl;
    }

    void processCalls() {
        while (!callQueue.empty() && availableCSRs > 0) {
            Call nextCall = callQueue.front();
            callQueue.pop();
            availableCSRs--;
            cout << "CSR assigned to handle Call #" << nextCall.callId << " (" << nextCall.customerName << ")." << endl;
            // Simulate call completion freeing up CSR
            availableCSRs++;
        }
    }
};

int main() {
    CallCenter center(2);
    center.addCall(101, "Alice");
    center.addCall(102, "Bob");
    center.addCall(103, "Charlie");
    center.processCalls();
    return 0;
}