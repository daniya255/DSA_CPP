class Solution {
public:
    int myAtoi(string s) {
        
    if (s.empty()) return 0;

    int start=0;
    int sign=1;
    int result=0;

    while (start< s.size() && s[start]== ' '){
        start++;
    }

    if (start >= s.size()) return 0;

    if (s[start] == '-'){
        sign=-1;
        start++;
    }
    else if(s[start]== '+'){
        sign=1;
        start++;
    }

    for(int i=start; i<s.size(); i++){

        if( !isdigit(int(s[i])) ) break;

        else{
            if(result > (INT_MAX - (s[i] - '0') ) / 10 ){
                return (sign==1) ? INT_MAX : INT_MIN;
            }
            result = result*10 + (s[i] - '0');
        }
         
    }

    return sign*result;
    }
};