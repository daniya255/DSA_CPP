#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st;    // Main stack to store all elements
    stack<int> minSt; // Auxiliary stack to track minimum elements

public:
    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        st.push(val);
        // If minSt is empty or val is less than or equal to current min, push to minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        // If the element we are removing is the current minimum, pop it from minSt too
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Current Min (-3 expected): " << minStack.getMin() << endl; 
    
    minStack.pop();
    
    cout << "Top element (0 expected): " << minStack.top() << endl;    
    cout << "Current Min (-2 expected): " << minStack.getMin() << endl; 
    
    return 0;
}