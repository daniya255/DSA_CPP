class Solution {
public:
    bool isArmstrong(int n) {
int ld,sum=0;
    int orig=n;
    int num= log10(abs(n))+1;
    while(n>0){
        ld=n%10;
        sum+=pow(ld,num);
        n=n/10;
    }
    if(orig==sum) return true;
    else return false;
    }
};