class Solution {
public:
    int digitproduct(int n){
        int k  = n;
        if(n%10 == 0 ) return 0;
        int product=1;
        int digit;
        while(k>0){
            digit = k%10;
            product *= digit;
            k = k/10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        if(digitproduct(n)%t==0)return n;
        return smallestNumber(n+1,t);
    }
};