#include<bits/stdc++.h>
using namespace std;
class QueStack{
    private:
    stack<int>que;
    public:
    QueStack(){}
    void push_in(int val){

        int size=que.size();
        stack<int>temp;

        for(int i=0; i<size; i++){
            temp.push(que.top());
            que.pop();

        }
        que.push(val);
        
        for(int i=0; i<size; i++){
            que.push(temp.top());
            temp.pop();
        }

    }

    int pop_out(){
        if(que.empty()) return -1;
        int popped=que.top();
        que.pop();
        return popped;
    }

    int peek(){
        if(que.empty()) return -1;
        return que.top();
    }

    bool isEmpty(){
        return que.empty();
    }
};
int main(){
    QueStack que;
    que.push_in(5);
    que.push_in(51);
    que.push_in(54);
    cout<<que.peek()<<endl;
    cout<< (que.isEmpty() ? "true" : "false" ) <<endl;
    cout<<que.pop_out()<<endl;
    cout<<que.peek()<<endl;
    return 0;
}