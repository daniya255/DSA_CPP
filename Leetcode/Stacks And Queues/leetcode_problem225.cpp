class MyStack {
private:
    queue<int> st;

public:
    MyStack() {}

    void push(int x) {
        int size = st.size();
        st.push(x);

        for (int i = 0; i < size; i++) {
            st.push(st.front());
            st.pop();
        }
    }

    int pop() {
        if (st.empty())
            return -1;

        int top_el = st.front();
        st.pop();
        return top_el;
    }

    int top() {
        if (st.empty())
            return -1;

        return st.front();
    }

    bool empty() { return st.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */