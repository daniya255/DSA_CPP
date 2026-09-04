#include<bits/stdc++.h>
using namespace std;
class StackQueue{
    private:
    queue<int>st;
    int capacity=10;
    int topInd;

    public:
    void push_in(int val){
        if(st.size()>=capacity){
            cout<<"Can't enter an other element, stack overflow!"<<endl;
            return;
        }

        int size=st.size();
        st.push(val);

        for(int i=0;i<size;i++){
            st.push(st.front());
            st.pop();
        }
    }

    int pop_out(){
        if(st.empty()) return -1;

        int top_el=st.front();
        st.pop();
        return top_el;
    }

    int topEl(){
        if(st.empty()) return -1;

       return st.front();
    }

    bool isEmpty(){
        return st.empty();
    }
};
int main(){
    StackQueue st;
    st.push_in(10);
    st.push_in(7);
    st.push_in(5);
    cout<<st.topEl()<<endl;
    cout<<st.pop_out()<<endl;
    cout << (st.isEmpty() ? "true" : "false") << endl;

    return 0;
}