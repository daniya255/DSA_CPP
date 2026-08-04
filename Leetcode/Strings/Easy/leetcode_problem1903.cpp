class Solution {
public:
    string largestOddNumber(string num) {
        
    if (num.empty()) return "";

    int start=0, end=-1;

    for(int i=num.size()-1; i>=0; i--){
        if((num[i] - '0') %2== 1) {
            end=i;
            break;
        }
    }

    for(int i=0; i<end; i++){
        if (num[i] !='0' ) break;

        start++;
    }

    return num.substr(start, end-start+1);
    }
};