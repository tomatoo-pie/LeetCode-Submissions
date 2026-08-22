class Solution {
public:
    int isSumDivisible(int n){
        int k = n;
        int sum = 0;
        while(k>0){
            int d = k%10;
            sum = sum + d;
            k = k/10;
        }

        return sum;
    }

    int isProductDivisible(int n){
        int k = n;
        int product = 1;
        while(k>0){
            int d = k%10;
            product = product * d;
            k = k/10;
        }

        return product;
    }

    bool checkDivisibility(int n) {
        int sum = isProductDivisible(n) + isSumDivisible(n);
        return(n%sum==0);
    }
};