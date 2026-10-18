#include<bits/stdc++.h>
using namespace std;
int calPoints(vector<string>& operations) {
   stack<int> score;
   int result = 0;

   for(const string& operation: operations){
        if (operation == "+"){
            int top = score.top(); score.pop();
            int secTop = score.top();
            int temp = top + secTop;
            score.push(top);
            score.push(temp);
        }

        else if (operation == "C"){
            if (!score.empty()) score.pop();
        }

        else if(operation == "D"){
            score.push(score.top() * 2);
        }

        else{
            score.push(stoi(operation));
        }
   } 
   
   while(!score.empty()) {
    result+= score.top(); 
    score.pop();
   }

   return result;

}

int main(){
    vector<string> operations = {"5","-2","4","C","D","9","+","+"};
    int result  = calPoints(operations);
    cout<<"Score : "<<result<<endl;
    return 0;
}
