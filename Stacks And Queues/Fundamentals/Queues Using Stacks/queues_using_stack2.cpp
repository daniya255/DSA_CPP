#include<bits/stdc++.h>
using namespace std;
class QueStack{
    private:
    stack<int>input;
    stack<int>output;
    public:
    QueStack(){}
    void push_in(int val){
        input.push(val);
    }

    int pop_out(){

        if(output.empty() && input.empty()) return -1;

        if(output.empty()){
            int size=input.size();
            for(int i=0;i<size;i++){
                output.push(input.top());
                input.pop();
            }

        }

        int popped=output.top();
        output.pop();
        return popped;

    }

    int peek(){
        if(output.empty() && input.empty()) return -1;
        
        if(output.empty()){
            int size=input.size();
            for(int i=0;i<size;i++){
                output.push(input.top());
                input.pop();
            }

        }

        int popped=output.top();
        return popped;
    }

    bool isEmpty(){
        return (output.empty() && input.empty());
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