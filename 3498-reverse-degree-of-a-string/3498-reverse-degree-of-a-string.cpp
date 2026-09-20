class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.length();i++){
            int product = -(((s[i]-'a') - 26) * (i+1));
            sum += product;
        }
        return sum;
    }
};