
// reverse number [-2^31-1,2^31-1]

int reverse(int x){
     int ld;
     long rev=0;

        while(x!=0){
            ld=x%10;
            rev=(rev*10) + ld;
            x=x/10;
    }
    if(rev>INT_MAX || rev<INT_MIN) return 0;
    return (int)rev;
    
}