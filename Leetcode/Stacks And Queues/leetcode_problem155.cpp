class MinStack {
private:
    stack<int> st;    // Main stack to store all elements
    stack<int> minSt; // Auxiliary stack to track minimum elements
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        // If minSt is empty or val is less than or equal to current min, push
        // to minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        // If the element we are removing is the current minimum, pop it from
        // minSt too
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */